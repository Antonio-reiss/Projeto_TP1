/**
 * @file ms.reserva.cpp
 * @brief Implementação dos métodos de serviço da classe msReserva.
 *
 * Responsável pelas operações de criação, edição, listagem e exclusão de
 * reservas, aplicando regras de negócio e validando dados através dos
 * domínios (Código, Data, Dinheiro, Email).
 */

#include "ms.reserva.hpp"
#include <iostream>
#include <sstream>

using namespace std;

/**
 * @brief Converte uma string no formato DD-MES-AAAA em valores separados.
 *
 * @details Caso o formato seja inválido, uma exceção é lançada para impedir
 * que dados corrompidos ou mal formatados sejam usados na criação da reserva.
 *
 * @param dataStr string no formato DD-MES-AAAA.
 * @param dia variável de saída para o dia.
 * @param mes variável de saída para o mês (string).
 * @param ano variável de saída para o ano.
 *
 * @throws invalid_argument se o formato não for respeitado.
 */
static void parseData(const string& dataStr, int& dia, string& mes, int& ano) {
    char s1, s2;
    stringstream ss(dataStr);
    ss >> dia >> s1 >> mes >> s2 >> ano;

    if (!ss || s1 != '-' || s2 != '-') {
        throw invalid_argument("Formato invalido! Use DD-MES-AAAA.");
    }
}

/**
 * @brief Cria uma nova reserva no sistema.
 *
 * @details Faz validação completa dos domínios e interpreta as datas de
 * chegada e partida utilizando o helper parseData(). Em seguida, instancia
 * um objeto Reserva e delega ao banco de dados a persistência.
 *
 * @param codigoStr código identificador da reserva.
 * @param chegadaStr data de chegada (DD-MES-AAAA).
 * @param partidaStr data de partida (DD-MES-AAAA).
 * @param valorStr valor total da reserva em formato string.
 * @param emailHospede email associado ao hóspede responsável.
 * @param numeroQuarto número do quarto reservado.
 *
 * @return true caso a criação seja concluída, false se qualquer validação,
 * conversão ou operação no BD falhar.
 */
bool msReserva::criarReserva(const string& codigoStr,
                             const string& chegadaStr,
                             const string& partidaStr,
                             const string& valorStr,
                             const string& emailHospede,
                             int numeroQuarto)
{
    try {
        // Validação dos domínios
        Codigo codigo(codigoStr);
        Email email(emailHospede);
        Dinheiro valor(stod(valorStr));

        // Interpretação das datas
        int dc, ac, dp, ap;
        string mc, mp;
        parseData(chegadaStr, dc, mc, ac);
        parseData(partidaStr, dp, mp, ap);

        // Construção do objeto Reserva
        Reserva reserva(
            dc, mc, ac,
            dp, mp, ap,
            valor.getValor(),
            codigo.getValor()
        );

        // Persistência no banco
        return db.criarReserva(reserva, numeroQuarto, email.getEmail());
    }
    catch (exception& e) {
        cout << "Erro ao criar reserva: " << e.what() << endl;
        return false;
    }
}

/**
 * @brief Lista todas as reservas cadastradas no sistema.
 *
 * @details A listagem é realizada diretamente pelo subsistema de banco de
 * dados, exibindo os registros armazenados.
 *
 * @return true caso a operação ocorra sem problemas, false em exceções.
 */
bool msReserva::listarReservas()
{
    try {
        db.listarTodos("Reserva");
        return true;
    }
    catch (exception& e) {
        cout << "Erro ao listar reservas: " << e.what() << endl;
        return false;
    }
}

/**
 * @brief Edita uma reserva existente no sistema.
 *
 * @details O código da reserva identifica o registro que será modificado. As
 * novas datas são validadas e interpretadas, e um objeto Reserva temporário é
 * montado apenas para atualizar as informações necessárias.
 *
 * @param codigoStr código identificador da reserva.
 * @param novaChegadaStr nova data de chegada (DD-MES-AAAA).
 * @param novaPartidaStr nova data de partida (DD-MES-AAAA).
 *
 * @return true se a edição for aplicada corretamente, false em caso de erro.
 */
bool msReserva::editarReserva(string codigoStr,
                              string novaChegadaStr,

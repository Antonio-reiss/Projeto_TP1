/**
* @file ma.gerente.hpp
* @brief Definicao da classe maGerente que implementa a funcao que valida os dados.
* @author Maria Ellen Guedes Montalvao - 232011402
*/
#ifndef MA_GERENTE_HPP
#define MA_GERENTE_HPP
#include "../../dominios/dominios.nome.hpp"
#include "../../dominios/dominios.email.hpp"
#include "../../dominios/dominios.ramal.hpp"
#include "../../dominios/dominios.senha.hpp"
#include "ia.gerente.hpp"
#include <string>

using namespace std;

/**
* @class maGerente
* @brief Classe concreta que valida os dados de entrada para uma conta Gerente.
*
* @details Esta classe usa heranca de templates (iaGerente<string>, iaGerente<int> para delegar
* a validacao dos dados brutos de entrada aos domínios.
*/
 class maGerente : public iaGerente{
 public:
     /**
     * @brief Valida se todos os domínio para a conta do Gerente sao validos.
     * @param string nome Nome do Gerente.
     * @param string email Email do Gerente.
     * @param int ramal Ramal do Gerente.
     * @param string senha Senha da conta.
     * @return Retorna true se todos os dados forem validos, caso contrario, false.
     */
    bool validarConta(const string&, const string&, const int&, const string&) override;
    /**
    * @brief Valida um unico dado de entrada do tipo string (dado e tipo) para edicao.
    * @param novoDado eh o novo valor (string) a ser validado;
    * @param tipoDado eh o campo a ser editado.
    * @return Retorna true se a validacao for bem-sucedida, false caso contrario.
    */
    bool validarEditar(const string&, const int&) override;
};
#endif // MA_GERENTE_HPP

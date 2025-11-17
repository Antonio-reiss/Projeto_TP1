/**
* @file ia.gerente.hpp
* @brief Interface abstrata para a camada de apresentacao do módulo gerente.
* @author Maria Ellen Guedes Montalvao - 2232011402
*/
#ifndef IA_GERENTE_HPP
#define IA_GERENTE_HPP
#include "../../dominios/dominios.nome.hpp"
#include "../../dominios/dominios.email.hpp"
#include "../../dominios/dominios.ramal.hpp"
#include "../../dominios/dominios.senha.hpp"
#include <string>

using namespace std;

template <typename T>
/**
* @class iaGerente
* @brief Contrato para o módulo de apresentacao do Gerente.
*
* Esta interface define os métodos que a IU deve implementar para coletar dados e iniciar a validacao de dominio.
*/
class iaGerente{
public:
    /**
    * @brief Valida os dados de entrada para a criacao de uma conta Gerente.
    * @details O método usa os construtores de dominio (Nome, Email, Ramal, Senha) para a validacao.
    * @param string nome com o nome de entrada.
    * @param string email com o email de entrada.
    * @param int ramal com o ramal de entrada.
    * @param string senha com a senha de entrada.
    * @return Retorna true se ocorrer a validacao em todos os dominios forem bem-sucedidas, false caso contrario.
    */
    virtual bool validarConta(const string&, const string&, const int&, const string&) = 0;

    virtual bool validarEditar(const T& novoDado, const string& tipoDado) = 0;

};

#endif // IA_GERENTE_HPP

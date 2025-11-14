/**
* @file ia.gerente.hpp
* @brief Interface abstrata para a camada de apresentação do módulo gerente.
* @author Maria Ellen Guedes Montalvão - 2232011402
*/
#ifndef IA_GERENTE_HPP
#define IA_GERENTE_HPP
#include "../../dominios/dominios.nome.hpp"
#include "../../dominios/dominios.email.hpp"
#include "../../dominios/dominios.ramal.hpp"
#include "../../dominios/dominios.senha.hpp"
#include <string>

using namespace std;

/**
* @class iaGerente
* @brief Contrato para o módulo de apresentação do Gerente.
*
* Esta interface define os métodos que a IU deve implementar para coletar dados e iniciar a validação de domínio.
*/
class iaGerente{
public:
    /**
    * @brief Valida os dados de entrada para a criação de uma conta Gerente.
    * * O método usa os construtores de domínio (Nome, Email, Ramal, Senha) para a validação.
    * @param string nome com o nome de entrada.
    * @param string email com o email de entrada.
    * @param int ramal com o ramal de entrada.
    * @param string senha com a senha de entrada.
    * @return Retorna true se ocorrer a validação em todos os domínios forem bem-sucedidas, false caso contrário.
    */
    virtual bool validarConta(const string&, const string&, const int&, const string&) = 0;

};

#endif // IA_GERENTE_HPP

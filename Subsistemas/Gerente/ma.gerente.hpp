/**
* @file ma.gerente.hpp
* @brief Definição da classe maGerente que implementa a função que valida os dados.
* @author Maria Ellen Guedes Montalvão - 232011402
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
*/
 class maGerente : public iaGerente{
 public:
     /**
     * @brief Valida se todos os domínio para a conta do Gerente são válidos.
     * @param string nome Nome do Gerente.
     * @param string email Email do Gerente.
     * @param int ramal Ramal do Gerente.
     * @param string senha Senha da conta.
     * @return Retorna true se todos os dados forem válidos, caso contrário, false.
     */
    bool validarConta(const string& nome, const string& email, const int& ramal, const string& senha) override;
 };

#endif // MA_GERENTE_HPP

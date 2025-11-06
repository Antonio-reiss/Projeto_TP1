#ifndef MA_GERENTE_HPP
#define MA_GERENTE_HPP
#include "../../dominios/dominios.nome.hpp"
#include "../../dominios/dominios.email.hpp"
#include "../../dominios/dominios.ramal.hpp"
#include "../../dominios/dominios.senha.hpp"
#include "i.gerente.hpp"
#include <string>

using namespace std;

 class maGerente : public IGerente{
 public:
    bool validarConta(const string& nome, const string& email, const float& ramal, const string& senha) override;
 };

#endif // MA_GERENTE_HPP

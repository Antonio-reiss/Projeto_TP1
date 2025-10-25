#include "dominios.email.hpp"
#include <regex>
#include <string>
#include <stdexcept>

using namespace std;

Email::Email(const string& email){
    setEmail(email);
};

string Email::getEmail() const{
    return this->email;
};

void Email::setEmail(const string& email){
    if(validarFormato(email)){
        this->email = email;
    }
    else{
        throw invalid_argument("Esse e-mail eh invalido.");
    }
}

bool Email::validarFormato(const string& email){
    regex padrao("^[a-zA-Z0-9][a-zA-Z0-9.-]{0,62}[a-zA-Z0-9]@"
                      "[a-zA-Z0-9][a-zA-Z0-9-]{0,62}[a-zA-Z0-9](\\.[a-zA-Z0-9-]+)*$"
                     );

    size_t posicaoArroba = email.find('@');
    if(posicaoArroba == string::npos){
        return false;
    }

    if(posicaoArroba > 64 || (email.length() - posicaoArroba - 1) > 255){
        return false;
    }

    return regex_match(email, padrao);
};

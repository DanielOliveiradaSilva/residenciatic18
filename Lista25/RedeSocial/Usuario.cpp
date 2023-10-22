#include "usuario.h"
Usuario::Usuario() {}

Usuario::Usuario(string username, string nome){
    this->username = username;
    this->nome = nome;
}
void Usuario::setUsername(string username){
    this->username = username;
}


void Usuario::setNome(string nome)
{
    this->nome = nome;
}

void Usuario::setSeguidor(Usuario novo_seguidor){
    this->seguidores.push_back(novo_seguidor);
}
void Usuario::setSeguir(Usuario novo_usuario){
    this->seguindo.push_back(novo_usuario);
}

string Usuario:: getNome(){
    return nome;
}
string Usuario:: getUsername(){
    return username;
}

Usuario::~Usuario() {}

#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Usuario
{
private:
    string username;
    string nome;

    vector<Usuario> seguidores;
    vector<Usuario> seguindo;

public:
    Usuario();
    Usuario(string username, string nome);
    // setts
    void setUsername(string username);
    void setNome(string nome);
    void setSeguidor(Usuario novo_seguidor);
    void setSeguir(Usuario novo_usuario);

    // gets
    string getNome();
    string getUsername();
    vector<Usuario> getSeguidores();
    vector<Usuario> getSeguindo();
    ~Usuario();
};

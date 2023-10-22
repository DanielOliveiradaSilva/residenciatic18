#pragma once

#include <iostream>
#include <string>
#include "usuario.h"
#include "twitter.h"
using namespace std;

class Ctrl_RedeSocial
{
private:
    static vector<Usuario> usuarios_do_twitter;
    static vector<Twitter> postagens_do_twitter;
public:
    Ctrl_RedeSocial(/* args */);
    ~Ctrl_RedeSocial();
    static Usuario acessarConta(string username, bool &request);
    static void criarConta(Usuario &novo);
    static bool token(string username, int &token_acesso);
    static void seguirPerfil(Usuario &usuario);
    static Usuario getUsuario(int &token_acesso);

    
};

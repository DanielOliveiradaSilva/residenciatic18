#include "ctrl_RedeSocial.h"

Ctrl_RedeSocial::Ctrl_RedeSocial(/* args */){}

Usuario Ctrl_RedeSocial:: acessarConta(string username, bool &request){

    int _token;
    request = token(username, _token);
    return usuarios_do_twitter[_token];
}

bool Ctrl_RedeSocial::token(string username, int &token_acesso){
    string username_usuario;
    for (int i =0; i < usuarios_do_twitter.size();i++){
        username_usuario = usuarios_do_twitter[i].getUsername();
      if (username_usuario == username){
         token_acesso = i;
         return true;
      }
      
    }
    token_acesso = -1;
    return false;
}

void Ctrl_RedeSocial:: criarConta(Usuario &novo){
    usuarios_do_twitter.push_back(novo);
}

void Ctrl_RedeSocial::seguirPerfil(Usuario &usuario){
    int token_acesso;
    token(usuario.getUsername(), token_acesso);
    usuarios_do_twitter[token_acesso] = usuario;
}


Usuario  Ctrl_RedeSocial::  getUsuario(int &token_acesso){

    return usuarios_do_twitter[token_acesso];
}

Ctrl_RedeSocial::~Ctrl_RedeSocial(){}

vector<Usuario> Ctrl_RedeSocial:: usuarios_do_twitter = {
    Usuario("oliveira4552", "Daniel Oliveira da silva"),
    Usuario("lorena", "Lorena Andrade"),
    Usuario("diascarlos", "Caros Dias")
};
vector<Twitter>Ctrl_RedeSocial:: postagens_do_twitter = {
    Twitter(Usuario("oliveira4552", "Daniel Oliveira da silva"), "Eu amo morrango!", "20/03/2023"),
    Twitter(Usuario("oliveira4552", "Daniel Oliveira da silva"), "Adotei um pet!", "28/05/2023"),
    Twitter(Usuario("oliveira4552", "Daniel Oliveira da silva"), "Virei vegano :)!", "20/03/2023"),
    Twitter(Usuario("lorena", "Lorena Andrade"), "Sou mãe de dois filhos!", "20/05/2015"),
    Twitter(Usuario("lorena", "Lorena Andrade"), "Casei aos 19 anos, e sou feliza!", "16/07/2017"),
    Twitter(Usuario("diascarlos", "Caros Dias"), "Os importos acabam com meu salario de 9.5k ;-;", "16/10/2023"),
};

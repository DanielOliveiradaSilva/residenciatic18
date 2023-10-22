#include <iostream>
#include "include/interface.h"
#include "include/ctrl_biblioteca.h"

using namespace std;
int main()
{

    int opcao;
    vector<string> menu = {
        "1. Adicionar livros à biblioteca",
        "2. Registrar empréstimos de livros",
        "3. Verificar a disponibilidade de um livro",
        "4. Listar os livros emprestados por um usuário específico",
        "5. Sair"};

    while (true)
    {

        opcao = monta_menu(menu, "biblioteca");
        cout<<endl;

        switch (opcao)
        {
        case 1:
            ctrl_biblioteca::insere_livro();
            break;
        case 2:
            ctrl_biblioteca::registrarEmpresimo();
            break;
        case 3:
            ctrl_biblioteca::verificarDisponibilidadeDelivroBiblioteca();
            break;
        case 4:
            ctrl_biblioteca::exibirTodosEmprestimosDoUsuario();
            break;
        case 5:
            exit(0);

        default:
            cout << "Opção invalida!" << endl;
            break;
        }
    }
}
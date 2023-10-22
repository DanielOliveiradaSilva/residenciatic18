#include "interface.h"

void loadingAnimation() {
    const int totalDots = 10;
    
    for (int i = 0; i <= totalDots; i++) {
        cout << "Carregando: [";
        for (int j = 0; j < i; j++) {
            cout << ".";
        }
        for (int j = i; j < totalDots; j++) {
            cout << " ";
        }
        cout << "]" << "\r";
        
        // Aguarde um curto período de tempo para criar a animação
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    
    cout << endl;
}

void clearScreen() {
    system("clear");
}

void PageTwitterConected(bool &loggedIn, Usuario &usuario){

    if (loggedIn) {
        int opcao;

        while (true) {
            loadingAnimation();
            clearScreen();
            cout << "\nBem-vindo, " << usuario.getNome() << "!" << endl;
            cout << "Escolha uma opção:" << endl;
            cout << "1. Ver a timeline" << endl;
            cout << "2. Fazer uma postagem" << endl;
            cout << "3. Seguir uma pessoa" << endl;
            cout << "4. Sair " << endl;

            cout << "\n5. Fechar pagina" << endl;

            cout << "Opção: ";
            cin >> opcao;

            switch (opcao) {
                case 1:
                    // Lógica para ver a timeline
                   // cout << "Ver timeline..." << endl;
                    break;
                case 2:
                    // Lógica para fazer uma postagem
                    //cout << "Fazer uma postagem..." << endl;
                    break;
                case 3:
                    // Lógica para seguir uma pessoa
                    //cout << "Seguir uma pessoa..." << endl;
                    break;
                case 4:
                    //cout << "Saindo..." << endl;
                    // Saia do menu e retorne à tela de login
                     PageTwitter();
                case 5:
                    exit(0); 
                   
                default:
                    break;
                    //cout << "Opção inválida. Tente novamente." << endl;
            }
        }
    }
}


void login()
{
    loadingAnimation();
    clearScreen();
    Usuario usuario;
    bool loggedIn;
    cin.ignore();

    string username;
    cout << "@username:";

    getline(cin, username);

    usuario = Ctrl_RedeSocial::acessarConta(username, loggedIn);

    if (loggedIn)
    {
        cout << "Logado com sucesso!" << endl;
        PageTwitterConected(loggedIn, usuario);
    }else
    {
        cout << "Login falhou !" << endl;
    }
}
void registerUsuario(){
    loadingAnimation();
    clearScreen();
    cin.ignore();
    string username, nome;
    cout <<"@username:";
    getline(cin, username);
    cout <<"Seu nome:";
    getline(cin, nome);

    
    int request;
    Ctrl_RedeSocial::token(username, request);
    if (request == -1)
    {
        Usuario novo(username, nome);
        Ctrl_RedeSocial::criarConta(novo);
        cout<<"Usuario cadastrado!"<<endl;
        return;
    }else{
        string confirmar;
        cout<<"Usuario já cadastrado!"<<endl;
        cout<<"Deseja fazer loggin? s/n:";
        getline(cin, confirmar);
        if(confirmar =="S"|| confirmar == "S"){
            PageTwitter();//redireciona;
        }else{
            registerUsuario();
        }
    }

}
// Função para a página do Twitter
void PageTwitter() {

    
    int opcao;

    while (true) {
        loadingAnimation(); //animação de carregamento
        clearScreen(); // Limpa o terminal
        cout << "Bem-vindo ao Twitter!" << endl;
        cout << "Escolha uma opção:" << endl;
        cout << "1. Login" << endl;
        cout << "2. Cadastrar" << endl;
        cout << "3. Sair" << endl;

        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Opção de Login selecionada." << endl;
                clearScreen();
                login();
                // Chame a função de login aqui
                break;
            case 2:
                cout << "Opção de cadastro selecionada." << endl;
                clearScreen();
                registerUsuario();
                // Substitua este comentário pela lógica de cadastro.
                break;
            case 3:
                cout << "Saindo do Twitter." << endl;
                //vá para pagina admin.
                return;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    }
}




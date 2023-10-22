#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Evento
{
private:
    int duracao;

public:
    Evento(int d);
    int getDuracao();
    void setDuracao(int d);
};

Evento::Evento(int d) : duracao(d) {}

int Evento::getDuracao()
{
    return duracao;
}

void Evento::setDuracao(int d)
{
    duracao = d;
}

class Pacote
{
private:
    string nome;
    vector<Evento*> eventos; // Vetor de ponteiros para Evento

public:
    Pacote(string n);
    void adicionarEvento(Evento &evento);
    void listarEventos();
};

Pacote::Pacote(string n) : nome(n) {}

void Pacote::adicionarEvento(Evento &evento)
{
    eventos.push_back(&evento);
}

void Pacote::listarEventos()
{
    cout << "Eventos do " << nome << endl;
    for (auto e: eventos)
    {
        cout << e->getDuracao() << endl;
    }
}

int main()
{
    Pacote p1("Pacote 1");
    Pacote p2("Pacote 2");

    Evento e1(1);
    Evento e2(2);
    Evento e3(3);
    Evento e4(4);

    p1.adicionarEvento(e1);
    p1.adicionarEvento(e2);

    p2.adicionarEvento(e2);
    p2.adicionarEvento(e3);

    p1.listarEventos();
    p2.listarEventos();

    e2.setDuracao(10); // Agora essa alteração refletirá em todos os pacotes

    p1.listarEventos();
    p2.listarEventos();
}

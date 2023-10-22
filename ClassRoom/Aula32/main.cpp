
#include <iostream>
#include <vector>
using namespace std;

class Transacoes
{
private:
    /* data */
public:
    Transacoes(/* args */);
    ~Transacoes();
};


class Conta{
private:
    string conta;
    string correntista;
    double saldo;
    vector<Transacoes> historico;

public:
    Conta(/* args */);
    ~Conta();
};

class Poupanca : public Conta
{
private:
    /* data */
public:
    Poupanca();
    ~Poupanca();
};

class ContaComum : public Conta
{
private:
    /* data */
public:
    ContaComum(/* args */);
    ~ContaComum();
};
class ContaCorrente : public Conta
{
private:
    /* data */
public:
};

int main()
{

    return 0;
}
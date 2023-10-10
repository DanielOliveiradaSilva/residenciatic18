#include <iostream>

using namespace std;

class Animal
{
private:
    string nome;
    int idade;

public:
    Animal(/* args */) {};
    ~Animal(){};

    void fazerSom()
    {
        cout << "Algum som" << endl;
    };
};

class Cachorro :Animal
{
private:
public:
    Cachorro(/* args */) {};
    ~Cachorro() {};

    void fazerSom()
    {
        cout << "Au Au!" << endl;
    };
};

int main()
{
    Animal a1;
    a1.fazerSom();

    Cachorro c1;
    c1.fazerSom();
}
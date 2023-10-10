#include <iostream>

using namespace std;

class Forma
{
private:

public:
    double calcularArea();
};

class Retangulo :Forma
{
private:
    double largura;
    double altura;
public:
    double  calcularArea(){
        double area = largura * altura;
    } 
};

class Circulo :Forma
{
private:
    /* data */
public:
 
}



int main()
{
    
}
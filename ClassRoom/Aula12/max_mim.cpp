#include <iostream> 
#include <string>

void maxmin (int vetor[], int n,int &maximo, int &minimo);

using namespace std;
int main (){
    int maximo;
    int minimo;

    int vetor[] = {2, 3, 4};
    int n = sizeof(vetor)/sizeof(vetor[0]);
    maxmin(vetor,n, maximo, minimo);
    cout << "O Valor maximo: " << maximo <<endl<< "O Valor minimo: " << minimo << endl;

   
}

void maxmin (int vetor[], int n, int &maximo, int &minimo){

    minimo = vetor[0];
    maximo = vetor [0];
    for (int i = 0; i<n-1;i++){
        if (minimo > vetor[i+1]){
            minimo = vetor[i+1];
        }
        if (maximo < vetor[i+1]){
            maximo = vetor[i+1];
        }
    }
}
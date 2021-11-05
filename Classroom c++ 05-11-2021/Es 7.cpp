//Consegna: Calcolare la somma dei primi N numeri naturali

#include <iostream>

using namespace std;

int main()
{
    int N;
    int somma = 0;
    cout<<"Inserisci un numero: ";
    cin>>N;
    while(N){
        somma += N;
        N--;
    }
    cout<<somma;

    return 0;
}

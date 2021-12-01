//Consegna: Calcolare la somma dei primi N numeri naturali

#include <iostream>

using namespace std;

int main()
{
    int N;
    int somma = 0;
    cout<<"Inserisci un numero: ";
    cin>>N;
    for(int i = N; i; i--){
        somma += i;
    }
    cout<<somma;

    return 0;
}
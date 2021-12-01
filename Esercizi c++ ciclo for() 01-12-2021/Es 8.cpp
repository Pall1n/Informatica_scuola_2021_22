//Consegna: Dati N numeri effettuarne la somma

#include <iostream>

using namespace std;

int main()
{
    int N;
    double numeri;
    double somma = 0;
    cout<<"Inserisci il numero di numeri che vuoi inserire: ";
    cin>>N;
    for(int i = 0; i < N; i++){
        cout<<"("<<i+1<<"/"<<N<<") Inserisci numero: ";
        cin>>numeri;
        somma += numeri;
    }
    cout<<somma;

    return 0;
}
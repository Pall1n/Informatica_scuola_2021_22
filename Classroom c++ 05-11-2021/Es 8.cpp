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
    int i = 0;
    while(i < N){
        cout<<"("<<i+1<<"/"<<N<<") Inserisci numero: ";
        cin>>numeri;
        somma += numeri;
        i++;
    }
    cout<<somma;

    return 0;
}

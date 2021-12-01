//Consegna: Dati N numeri calcolare la media aritmetica

#include <iostream>

using namespace std;

int main()
{
    double N, numeri;
    double somma = 0;
    double media = 0;
    cout<<"Inserisci il numero di numeri da inserire: ";
    cin>>N;
    
    for(int i = 0; i < N; i++){
        cout<<"("<<i+1<<"/"<<N<<") Inserisci un numero: ";
        cin>>numeri;
        somma += numeri;
    }
    
    media = somma / N;
    
    cout<<"\nLa media aritmetica dei numeri inseriti equivale a "<<media;
    
    return 0;
}
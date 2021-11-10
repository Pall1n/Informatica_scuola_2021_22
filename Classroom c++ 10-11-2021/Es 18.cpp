//Consegna: Dati N numeri determinare il valore più piccolo tra quelli incontrati, indicandone il numero d'ordine

#include <iostream>

using namespace std;

int main()
{
    double N, minimo;
    double numeri = 0;
    int posizione;
    int i = 0;
    cout<<"Inserisci il numero di numeri da inserire: ";
    cin>>N;
    
    while(i < N){
        cout<<"("<<i+1<<"/"<<N<<") Inserisci un numero: ";
        cin>>numeri;
        if(i == 0) minimo = numeri;
        else if(numeri < minimo){
            minimo = numeri;
            posizione = i+1;
        }
        i++;
    }
    
    cout<<"\nIl numero minore inserito è "<<minimo<<" e la sua posizione durante l'inserimento equivale a "<<posizione;
    
    return 0;
}

//Consegna: Dati N numeri determinare il valore maggiore e quante volte esso ricorre

#include <iostream>

using namespace std;

int main()
{
    int N, massimo;
    int count = 1;
    int i = 0;
    cout<<"Inserisci il numero di numeri da inserire: ";
    cin>>N;
    int numeri[N-1] = {};
    
    while(i < N){
        cout<<"("<<i+1<<"/"<<N<<") Inserisci un numero: ";
        cin>>numeri[i];
        i++;
    }
    
    massimo = numeri[0];
    int lunghezza = sizeof(numeri)/sizeof(numeri[0]);
    
    for(int i = 0; i <= lunghezza; i++){
        if(numeri[i] > massimo) massimo = numeri[i];
    }
    
    for(int x : numeri){
        if(x == massimo) count++;
    }
    
    cout<<"Il numero massimo inserito è "<<massimo<<" e ricorre "<<count<<" volte";
    
    return 0;
}
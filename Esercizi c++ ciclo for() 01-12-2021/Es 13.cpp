//Consegna: Determinare quanti numeri multipli di K sono compresi nell'intervallo [A..B] (estremi compresi)

#include <iostream>

using namespace std;

int main()
{
    int K, A, B;
    int multipli = 0;
    int numero_multipli = 0;
    cout<<"Inserisci il numero da cui determinare i multipli: ";
    cin>>K;
    cout<<"Inserisci il numero minimo del range da verificare: ";
    cin>>A;
    cout<<"Inserisci il numero massimo del range da verificare: ";
    cin>>B;
    
    for(int i = 1; multipli <= B; i++){
        if(multipli >= A){
            numero_multipli++;
        }
        multipli = K*i;
    }
    
    cout<<"\nNel range richiesto sono presenti "<<numero_multipli<<" multipli di "<<K;
    
    return 0;
}
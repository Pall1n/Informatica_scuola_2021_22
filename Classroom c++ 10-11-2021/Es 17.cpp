//Consegna: Dati N numeri calcolare la media aritmetica dei valori pari e quella dei valori dispari

#include <iostream>

using namespace std;

int main()
{
    int N, numeri;
    double somma_pari = 0;
    double somma_dispari = 0;
    double media_pari = 0;
    double media_dispari = 0;
    int numeri_pari = 0;
    int numeri_dispari = 0;
    int i = 0;
    cout<<"Inserisci il numero di numeri da inserire: ";
    cin>>N;
    
    while(i < N){
        cout<<"("<<i+1<<"/"<<N<<") Inserisci un numero: ";
        cin>>numeri;
        if(numeri%2 == 0){
            somma_pari += numeri;
            numeri_pari++;
        }
        else{
            somma_dispari += numeri;
            numeri_dispari++;
        }
        i++;
    }
    
    media_pari = somma_pari/numeri_pari;
    media_dispari = somma_dispari/numeri_dispari;
    
    cout<<"\nLa media aritmetica dei numeri pari inseriti equivale a "<<media_pari<<" e quella dei numeri dispari "<<media_dispari;
    
    return 0;
}

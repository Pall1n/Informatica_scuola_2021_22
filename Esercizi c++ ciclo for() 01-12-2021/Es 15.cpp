//Consegna: Determinare la somma dei numeri negativi e positivi di un insieme di N numeri relativi

#include <iostream>

using namespace std;

int main()
{
    double N, numeri;
    double somma_positivi = 0;
    double somma_negativi = 0;
    cout<<"Inserisci il numero di numeri da inserire: ";
    cin>>N;
    
    for(int i = 0; i < N; i++){
        cout<<"("<<i+1<<"/"<<N<<") Inserisci un numero: ";
        cin>>numeri;
        if(numeri < 0){
            somma_positivi += numeri;
        }
        else{
            somma_negativi += numeri;
        }
    }
    
    cout<<"\nLa somma dei nuemri positivi inseriti equivale a "<<somma_positivi<<" e la somma dei numeri negativi equivale a "<<somma_negativi;
    
    return 0;
}
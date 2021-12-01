//Consegna: Dati N numeri stampare la somma di quelli pari e di quelli dispari

#include <iostream>

using namespace std;

int main()
{
    int N, numeri;
    int somma_pari = 0;
    int somma_dispari = 0;
    cout<<"Inserisci il numero di numeri da inserire: ";
    cin>>N;
    
    for(int i = 0; i < N; i++){
        cout<<"("<<i+1<<"/"<<N<<") Inserisci un numero: ";
        cin>>numeri;
        if(numeri%2 == 0){
            somma_pari += numeri;
        }
        else{
            somma_dispari += numeri;
        }
    }
    
    cout<<"\nLa somma dei nuemri pari inseriti equivale a "<<somma_pari<<" e la somma dei numeri dispari equivale a "<<somma_dispari;
    
    return 0;
}
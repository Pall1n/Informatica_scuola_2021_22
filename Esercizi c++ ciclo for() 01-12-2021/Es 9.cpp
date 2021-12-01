//Consegna: Dati N numeri contare quanti sono i valori pari e quelli dispari

#include <iostream>

using namespace std;

int main()
{
    int N, numeri;
    int num_pari = 0;
    cout<<"Inserisci il numero di numeri che vuoi inserire: ";
    cin>>N;
    for(int i = 0; i < N; i++){
        cout<<"("<<i+1<<"/"<<N<<") Inserisci numero: ";
        cin>>numeri;
        if(numeri%2 == 0) num_pari += 1;
    }
    cout<<num_pari;

    return 0;
}
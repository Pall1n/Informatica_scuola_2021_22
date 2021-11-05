//Consegna: Dati N numeri contare quanti sono i valori pari e quelli dispari

#include <iostream>

using namespace std;

int main()
{
    int N, numeri;
    int num_pari = 0;
    cout<<"Inserisci il numero di numeri che vuoi inserire: ";
    cin>>N;
    int i = 0;
    while(i < N){
        cout<<"("<<i+1<<"/"<<N<<") Inserisci numero: ";
        cin>>numeri;
        if(numeri%2 == 0) num_pari += 1;
        i++;
    }
    cout<<num_pari;

    return 0;
}

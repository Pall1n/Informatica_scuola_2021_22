//Consegna: Dati N numeri contare quanti sono i multipli di A

#include <iostream>

using namespace std;

int main()
{
    int N, A, numeri;
    int num_multipli = 0;
    cout<<"Inserisci il numero di numeri che vuoi inserire: ";
    cin>>N;
    cout<<"Inserisci numero per la verifica del multiplo: ";
    cin>>A;
    int i = 0;
    while(i < N){
        cout<<"("<<i+1<<"/"<<N<<") Inserisci numero: ";
        cin>>numeri;
        if(numeri%A == 0) num_multipli += 1;
        i++;
    }
    cout<<num_multipli;

    return 0;
}

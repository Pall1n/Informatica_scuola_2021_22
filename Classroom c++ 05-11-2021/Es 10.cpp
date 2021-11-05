//Consegna: Dati N numeri contare quanti sono i multipli di 3

#include <iostream>

using namespace std;

int main()
{
    int N, numeri;
    int num_multipli = 0;
    cout<<"Inserisci il numero di numeri che vuoi inserire: ";
    cin>>N;
    int i = 0;
    while(i < N){
        cout<<"("<<i+1<<"/"<<N<<") Inserisci numero: ";
        cin>>numeri;
        if(numeri%3 == 0) num_multipli += 1;
        i++;
    }
    cout<<num_multipli;

    return 0;
}

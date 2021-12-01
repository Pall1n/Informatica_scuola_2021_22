//Consegna: Stampare i numeri pari minori di N in ordine decrescente

#include <iostream>

using namespace std;

int main()
{
    int N;
    cout<<"Inserisci un numero per la sequenza: ";
    cin>>N;
    for(int i = N; i >= 0; i--){
        if(i%2 == 0){
            cout<<i<<endl;
        }
    }

    return 0;
}
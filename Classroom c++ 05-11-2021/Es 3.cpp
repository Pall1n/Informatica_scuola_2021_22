//Consegna: Stampare i numeri pari minori di N in ordine decrescente

#include <iostream>

using namespace std;

int main()
{
    int N;
    cout<<"Inserisci un numero per la sequenza: ";
    cin>>N;
    int i = N;
    while(i >= 0){
        if(i%2 == 0){
            cout<<i<<endl;
        }
        i--;
    }

    return 0;
}

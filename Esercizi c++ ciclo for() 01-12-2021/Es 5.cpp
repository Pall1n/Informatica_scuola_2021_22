//Consegna: Stampare i primi N multipli di un numero

#include <iostream>

using namespace std;

int main()
{
    double numero, multipli;
    cout<<"Inserisci un numero: ";
    cin>>numero;
    cout<<"Inserisci il numero di multipli desiderato: ";
    cin>>multipli;
    for(int i = 1; i <= multipli; i++){
        double prodotto = numero*i;
        cout<<prodotto<<endl;
    }

    return 0;
}
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
    int i = 1;
    while(i <= multipli){
        double prodotto = numero*i;
        cout<<prodotto<<endl;
        i++;
    }

    return 0;
}

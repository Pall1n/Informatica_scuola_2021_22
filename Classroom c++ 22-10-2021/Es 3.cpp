//Consegna: Eleva un numero intero per un esponente inserito da tastiera

#include <iostream>

using namespace std;

int calcolo(int n, int esp){
    int totale = 1;
    for(int i = 1; i <= esp; i++){
        totale *= n;
    }
    return totale;
}

int main()
{
    int n, esp;
    cout<<"Inserisci un numero: ";
    cin>>n;
    cout<<"Inserisci l'esponente: ";
    cin>> esp;
    cout<<"Il risultato di questa potenza è: "<<calcolo(n, esp);

    return 0;
}

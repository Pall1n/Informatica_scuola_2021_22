//Consegna: Data la base e l'esponente intero di una potenza, stabilire senza effettuare il calcolo, il segno di tale potenza.

#include <iostream>

using namespace std;

string verifica(int a, int n){
    if(n == 0) return "positivo.";
    
    else if(a < 0){
        if(n%2 == 0) return "positivo.";
        else return "negativo.";
    }
    
    else return "positivo.";
}

int main()
{
    while(true){
        int a,n;
        cout<<"Inserisci la base: ";
        cin>>a;
        cout<<"Inserisci l'esponente: ";
        cin>>n;
        if(a == 0) cout<<"Inserisci come base un valore diverso da 0.\n\n";
        else{
            cout<<"Il segno della potenza è "<<verifica(a,n);
            break;
        }
    }
    return 0;
}
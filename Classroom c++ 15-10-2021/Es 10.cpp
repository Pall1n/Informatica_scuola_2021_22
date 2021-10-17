//Consegna: Dati due numeri interi, stabilire, senza effettuare il calcolo, se la loro somma è pari o dispari.

#include <iostream>

using namespace std;

string verifica(int a, int b){
    if(a%2 == 0 and b%2 == 0) return "pari.";
    
    else if((a%2 == 0 and b%2 != 0) or (a%2 != 0 and b%2 == 0)) return "dispari.";
    
    else return "pari.";
}

int main()
{
    int a,b;
    cout<<"Inserisci il primo numero: ";
    cin>>a;
    cout<<"Inserisci il secondo numero: ";
    cin>>b;
    cout<<"La loro somma è "<<verifica(a,b);
    return 0;
}

//Consegna: Determinare se la potenza an è un numero pari (senza effettuare l'operazione).

#include <iostream>

using namespace std;

string verifica(int a, int n){
    if(a == 0 and n == 0) return "impossibile.";
    
    else if(a == 0) return "pari (il risultato è 0).";
    
    else if(n == 0) return "dispari";
    
    else if(a%2 == 0) return "pari.";
    
    else return "dispari";
}

int main()
{
    int a,n;
    cout<<"Inserisci la base: ";
    cin>>a;
    cout<<"Inserisci l'esponente: ";
    cin>>n;
    cout<<"La potenza an è "<<verifica(a,n);
    return 0;
}

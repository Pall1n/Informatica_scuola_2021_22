/*
Consegna: Determinare se un numero A ha la stessa parità di un numero B. 
(Due numeri hanno la  stessa parità se sono entrambi pari o entrambi dispari).
*/

#include <iostream>

using namespace std;

void verifica(int a, int b){
    if(a%2 == 0 and b%2 == 0){
        cout<<a<<" e "<<b<<" sono entrambi pari.";
    }
    else if(a%2 == 0 and b%2 != 0){
        cout<<a<<" è pari, ma "<<b<<" no.";
    }
    else if(a%2 != 0 and b%2 == 0){
        cout<<b<<" è pari, ma "<<a<<" no.";
    }
    else{
        cout<<"Entrambi i numeri sono dispari.";
    }
}

int main(){
    int a,b;
    cout<<"Inserisci un numero: ";
    cin>>a;
    cout<<"Inseriscine un altro: ";
    cin>>b;
    verifica(a,b);
    return 0;
}
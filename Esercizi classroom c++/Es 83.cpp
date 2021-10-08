//Consegna: Stabilire se un numero naturale qualsiasi, diverso da zero, è divisore di 36.

#include <iostream>
using namespace std;

string verifica(int n){
    if(n != 0 && 36%n == 0){
        return "Questo numero è un divisore di 36.";
    }
    else if(n != 0 && 36%n != 0){
        return "Questo numero non è un divisore di 36.";
    }
    else{
        return "Numero non valido. Riprova con un numero diverso da 0";
    }
}

int main(){
    int n;
    cout<<"Inserisci un numero: ";
    cin>>n;
    cout<<verifica(n);
    return 0;
}

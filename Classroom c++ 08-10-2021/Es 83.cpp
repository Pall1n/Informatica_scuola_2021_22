//Consegna: Stabilire se un numero naturale qualsiasi, diverso da zero, è divisore di 36.

#include <iostream>
using namespace std;

string verifica(int n){
    if(36%n == 0){
        return "Questo numero è un divisore di 36.";
    }
    else{
        return "Questo numero non è un divisore di 36.";
    }
}

int main(){
    int n;
    cout<<"Inserisci un numero: ";
    cin>>n;
    if(n != 0){
        cout<<verifica(n);
    }
    else{
        cout<<"Numero non valido. Riprova con un numero diverso da 0."<<endl<<endl;
        main();
    }
    return 0;
}

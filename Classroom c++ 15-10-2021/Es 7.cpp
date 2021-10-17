//Consegna: Stabilire se un numero naturale N, diverso da zero, è divisore di altri due numeri qualsiasi.

#include <iostream>

using namespace std;

void verifica(int a, int n1, int n2){
    if(n1%a == 0 and n2%a == 0){
        cout<<a<<" è divisore di entrambi i numeri.";
    }
    else if(n1%a == 0 and n2%a != 0){
        cout<<a<<" è divisore di "<<n1<<" ma non di "<<n2<<".";
    }
    else if(n1%a != 0 and n2%a == 0){
        cout<<a<<" è divisore di "<<n2<<" ma non di "<<n1<<".";
    }
    else{
        cout<<a<<" non è divisore di nessuno dei due numeri.";
    }
}

int main(){
    int a,n1,n2;
    cout<<"Inserisci un numero: ";
    cin>>a;
    if(a == 0){
        cout<<"Numero non valido, riprova."<<endl;
        main();
    }
    cout<<"Inserisci il primo numero da verificare come dividendo: ";
    cin>>n1;
    cout<<"Inserisci il secondo numero da verificare come dividendo: ";
    cin>>n2;
    verifica(a,n1,n2);
    return 0;
}
//Consegna: Calcola l'elevamento a potenza utilizzando le funzioni

#include <iostream>
using namespace std;

void calcolo(double &n, short int esp){
    double result = n;
    for(int i = esp; esp > 1; esp--){
        result*=n;
    }
    n = result;
}

int main(){
    double n;
    short int esp;
    cout<<"Inserisci numero: ";
    cin>>n;
    cout<<"Inserisci esponente: ";
    cin>>esp;
    calcolo(n, esp);
    
    cout<<"Il risultato della potenza è: "<<n;

    return 0;
}
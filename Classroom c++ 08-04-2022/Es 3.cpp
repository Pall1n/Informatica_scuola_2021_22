//Consegna: Eleva un numero intero per un esponente inserito da tastiera

#include <iostream>

using namespace std;

double calcolo(double &n, short int &esp){
    double result = n;
    for(int i = esp; esp > 1; esp--){
        result*=n;
    }
    return result;
}

int main(){
    double n;
    short int esp;
    cout<<"Inserisci numero: ";
    cin>>n;
    cout<<"Inserisci esponente: ";
    cin>>esp;
    
    cout<<"Il risultato della potenza è: "<<calcolo(n, esp);

    return 0;
}
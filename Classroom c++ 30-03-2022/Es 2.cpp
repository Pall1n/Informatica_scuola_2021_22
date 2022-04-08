//Consegna: Creare una funzione che calcola e restituisce il valore assoluto di un numero intero

#include <iostream>

using namespace std;

double valore_assoluto(double n){
    return (n<0) ? n*-1 : n;
}

int main()
{
    double numero;
    cout<<"Inserisci un numero per conoscere il suo valore assoluto: ";
    cin>>numero;
    cout<<"Il valore assoluto del numero inserito è: "<<valore_assoluto(numero);

    return 0;
}
//Consegna: Dato un numero intero, trovare il suo valore assoluto.

#include <iostream>

using namespace std;

int calcolo_assoluto(int numero)
{
    if(numero<0){
        return -numero;
    }
    else{
        return numero;
    }
}

int main()
{
    int numero;
    cout<<"Inserisci un numero: ";
    cin>>numero;
    cout<<"Il valore assoluto del numero è: "<<calcolo_assoluto(numero);
    return 0;
}

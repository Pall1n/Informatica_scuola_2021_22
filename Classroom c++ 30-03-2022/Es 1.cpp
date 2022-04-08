//Consegna: Creare una funzione che calcola il cubo di un numero

#include <iostream>

using namespace std;

double cubo(double n){
    return n*n*n;
}

int main()
{
    double numero;
    cout<<"Inserisci un numero per conoscere il suo cubo: ";
    cin>>numero;
    cout<<"Il cubo del numero inserito è: "<<cubo(numero);

    return 0;
}
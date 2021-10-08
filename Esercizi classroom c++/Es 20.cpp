//Consegna: Calcolare il quadrato del successivo del doppio di un numero.

#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cout<<"Inserisci un numero: ";
    cin>>a;
    b = (a*2+1);
    b = b*b;
    cout<<"Il quadrato del succesivo del doppio del numero è: "<<b;
    return 0;
}

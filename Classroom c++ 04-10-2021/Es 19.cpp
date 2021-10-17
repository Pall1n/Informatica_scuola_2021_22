//Consegna: Calcolare il successivo del doppio del quadrato di un numero.

#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cout<<"Inserisci un numero: ";
    cin>>a;
    b = (a*a)*2+1;
    cout<<"Il successivo del doppio del quadrato del numero è: "<<b;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int a;
    double b;
    cout<<"Inserisci una percentuale: ";
    cin>>a;
    cout<<"Inserisci un prezzo non scontanto o aumentato: ";
    cin>>b;
    b = (b+(b/100)*a)-(b-(b/100)*a);
    cout<<"La differenza tra l'aumento e lo sconto è: "<<b;
    return 0;
}
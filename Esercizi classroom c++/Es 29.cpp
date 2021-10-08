#include <iostream>

using namespace std;

int main()
{
    int a,b;
    double sconto;
    cout<<"Inserisci valore lordo: ";
    cin>>a;
    cout<<"Inserisci valore scontato: ";
    cin>>b;
    sconto = ((a-b)*100)/a;
    cout<<"Lo sconto è del: "<<sconto<<"%";
    return 0;
}
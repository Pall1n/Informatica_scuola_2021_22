/*
Una merce subisce un certo aumento in percentuale. 
Il negoziante però pratica ai clienti abituali uno sconto pari all'aumento. 
Calcolate la differenza tra il nuovo prezzo scontato e il vecchio prezzo.
*/

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

#include <iostream>

using namespace std;

int main()
{
    double prezzo,peso,totale;
    cout<<"Inserisci il prezzo/kg: ";
    cin>>prezzo;
    cout<<"Inserisci il peso: ";
    cin>>peso;
    totale= prezzo*peso;
    cout<<"Devi pagare: " << totale;
    

    return 0;
}

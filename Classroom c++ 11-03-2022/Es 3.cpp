/*Consegna: 
Scrivere un programma che riceve in input un numero intero 
e stampa “pari” se  ∈ {0,2,4}, “dispari” se  ∈ {1,3,5}, altrimenti “altro”.
*/

#include <iostream>
using namespace std;

int main()
{
    short int numero;
    
    cout<<"Inserisci numero per sapere che è pari se appartiene a \n{0,2,4} o se è dispari se appartenente a {1,3,5}: ";
    cin>>numero;
    
    switch(numero){
        case 0:
        case 2:
        case 4:
        cout<<"\nPari";
        break;
        case 1:
        case 3:
        case 5:
        cout<<"\nDispari";
        break;
        default:
        cout<<"\nAltro";
    }

    return 0;
}

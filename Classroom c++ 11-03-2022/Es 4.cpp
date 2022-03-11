/*Consegna: 
Realizzare un programma, utilizzando lo switch case, che legga in input 
un voto rappresentato da un carattere tra A ed E e ne stampi il significato.
Ad esempio:
A significa ottimo;
B significa distinto;
C significa discreto;
D significa sufficiente;
E significa insufficiente.
*/

#include <iostream>
using namespace std;

int main()
{
    char voto;
    
    cout<<"Inserisci carattere voto: ";
    cin>>voto;
    
    switch(voto){
        case 'A':
        cout<<"\nOttimo";
        break;
        case 'B':
        cout<<"\nDistinto";
        break;
        case 'C':
        cout<<"\nDiscreto";
        break;
        case 'D':
        cout<<"\nSufficiente";
        break;
        case 'E':
        cout<<"\nInsufficiente";
        break;
        default:
        cout<<"\nVoto non valido";
    }

    return 0;
}

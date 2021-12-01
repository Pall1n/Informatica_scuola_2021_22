/*Consegna: 
Determinare il fattoriale di un numero intero N;
valgono le seguenti relazioni:
N! = N(N-1)(N-2)... 1, 0! = 1, 1! = 1
*/

#include <iostream>
using namespace std;

int main()
{
    double N;
    double somma = 1;
    
    cout<<"Inserisci un numero per trovare il suo fattoriale: ";
    cin>>N;
    
    if(N == 0) cout<<"Il fattoriale del numero inserito equivale a 1";
    else if(N == 1) cout<<"Il fattoriale del numero inserito equivale a 1";
    else if(N < 0) cout<<"Il programma accetta solo numeri maggiori o uguali a 0";
    else{
        for(int i = N; i > 1; i--){
            somma *= i;
        }
        cout<<"Il fattoriale del numero inserito equivale a "<<somma;
    }
    
    return 0;
}
/*Consegna:
Scrivere una funzione che calcoli la somma dei primi n numeri 
interi positivi utilizzando la ricorsione
*/

#include <iostream>
using namespace std;

int calcolo_somma(unsigned int n){
    if(n == 1){
        return 1;
    }
    return n + calcolo_somma(n-1);
}

int main(){
    unsigned int n;
    cout<<"Inserisci n: ";
    cin>>n;
    unsigned int somma = calcolo_somma(n);
    cout<<"\nLa somma dei primi n numeri è: "<<somma;

    return 0;
}
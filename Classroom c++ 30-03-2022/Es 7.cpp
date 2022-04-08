/*Consegna:
Creare una funzione che restituisce se un numero intero è naturale o meno
*/

#include <iostream>

using namespace std;

int verifica(int n){
    return (n >= 0) ? true : false;
}

int main(){
    int n;
    
    cout<<"Inserisci un numero: ";
    cin>>n;

    if(verifica(n)) cout<<"Il numero inserito appartiene all'insieme dei numeri naturali";
    else cout<<"Il numero inserito non appartiene all'insieme dei numeri naturali";

    return 0;
}
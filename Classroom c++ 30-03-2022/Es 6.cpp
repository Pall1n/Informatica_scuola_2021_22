/*Consegna:
Creare una funzione che riceve tre numeri interi e restituisce
la differenza tra il più grande e il più piccolo
*/

#include <iostream>

using namespace std;

int diff(int *numeri){
    int maggiore = numeri[0];
    int minore = numeri[0];
    for(int i = 1; i < 3; i++){
        if(numeri[i] > maggiore) maggiore = numeri[i];
        if(numeri[i] < minore) minore = numeri[i];
    }
    return maggiore-minore;
}

int main(){
    int numeri[3];
    
    for(int i = 0; i < 3; i++){
        cout<<i+1<<") Inserisci numero: ";
        cin>>numeri[i];
    }
    
    cout<<"\nLa differenza tra il numero massiore e quello minore è: "<<diff(numeri);
    
    return 0;
}
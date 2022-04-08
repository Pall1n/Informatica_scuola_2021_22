/*Consegna:
Creare una funzione che restituisce se un numero intero ha almeno tre divisori
*/

#include <iostream>

using namespace std;

bool verifica(int n){
    int count = 0;
    for(int i = 2; i < n; i++){
        if(n%2 == 0) count++;
    }
    if(count >= 3) return true;
    else return false;
}

int main(){
    int n;
    
    cout<<"Inserisci un numero: ";
    cin>>n;

    if(verifica(n)) cout<<"Il numero inserito ha almeno 3 divisori";
    else cout<<"Il numero inserito non ha almeno 3 divisori";

    return 0;
}
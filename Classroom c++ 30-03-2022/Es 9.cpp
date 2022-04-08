/*Consegna:
Creare una funzione che dice se un carattere è una vocale
*/

#include <iostream>

using namespace std;

bool verifica(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? true : false;
}

int main(){
    char c;
    
    cout<<"Inserisci un carattere: ";
    cin>>c;

    if(verifica(tolower(c))) cout<<"Il carattere inserito è una vocale";
    else cout<<"Il carattere inserito non è una vocale";

    return 0;
}
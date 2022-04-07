//Consegna: Creare un programma che dato un carattere in ingresso verifica se è maiuscolo

#include <iostream>

using namespace std;

bool maiuscolo_minuscolo(char carattere){
    if(carattere >= 'A' && carattere <= 'Z') return true;
    else return false;
}

int main(){
    char carattere;
    
    cout<<"Inserisci un carattere: ";
    cin>>carattere;
    
    if(maiuscolo_minuscolo(carattere)){
        cout<<"Il carattere inserito è maiuscolo";
    } else{
        cout<<"Il carattere inserito è minuscolo";
    }

    return 0;
}

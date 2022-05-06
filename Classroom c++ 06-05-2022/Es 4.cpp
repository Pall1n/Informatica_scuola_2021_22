//Consegna: Trovare la lunghezza di una stringa tramite puntatori: ricordarsi che le stringhe terminano con '\0'

#include <iostream>
using namespace std;

unsigned int check_length(char *stringa){
    unsigned length = 0;
    for(char *punt = &stringa[0]; *punt != '\0'; punt++){
        length++;
    }
    return length;
}

int main(){
    char stringa[300];
    cout<<"Inserisci stringa: ";
    cin>>stringa;
    
    unsigned int lunghezza = check_length(stringa);
    cout<<"\nLa lunghezza della stringa è: "<<lunghezza;
    
    return 0;
}
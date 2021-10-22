//Consegna: A scelta dell'utente, calcola la somma di 10 numeri interi inseriti da tastiera o eleva un numero per un esponente inserito da tastiera

#include <iostream>

using namespace std;


void somma(){
    int num[10] = {};
    int somma = 0;
    int lunghezza_num = sizeof(num)/sizeof(num[0]);
    for(int i = 0; i < lunghezza_num; i++){
        cout<<"Inserisci un numero: ";
        cin>>num[i];
    }
    for(int i = 0; i < lunghezza_num; i++){
        somma += num[i];
    }
    cout<<"La somma dei numeri inseriti è: "<<somma;
}

void potenza(){
    int n, esp;
    cout<<"Inserisci un numero: ";
    cin>>n;
    cout<<"Inserisci l'esponente: ";
    cin>> esp;
    int totale = 1;
    for(int i = 1; i <= esp; i++){
        totale *= n;
    }
    cout<<"Il risultato di questa potenza è: "<<totale;
}

int main()
{
    string scelta;
    while(true){
        cout<<"1. Somma di 10 numeri.\n2. Eleva un numero per un esponente.\n\nScelta: ";
        cin>>scelta;
        if(scelta == "1"){
            somma();
            break;
        }
        else if(scelta == "2"){
            potenza();
            break;
        }
        else cout<<"\nScelta non valida, riprova.\n\n";
    }
    
    return 0;
}

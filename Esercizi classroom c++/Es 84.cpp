//Consegna: Dati  due  numeri  naturali  A  e  B,  con  A  diverso  da  B,  aggiungere  al  più  piccolo  la somma dei due numeri.

#include <iostream>
using namespace std;

string calcolo(int a, int b){
    if(a<b){
        return "Il numero più piccolo sommato alla somma dei due numeri è: " + to_string(a+a+b);
    }
    else{
        return "Il numero più piccolo sommato alla somma dei due numeri è: " + to_string(b+b+a);
    }
}

int main(){
    int a,b;
    cout<<"Inserisci A: ";
    cin>>a;
    cout<<"Inserisci B: ";
    cin>>b;
    if(a!=b){
        cout<<calcolo(a,b);
    }
    else{
        cout<<"Numeri uguali. Riprova con numeri diversi"<<endl<<endl;
        main();
    }
    return 0;
}

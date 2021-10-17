//Consegna: Dato il numeratore e il denominatore di una frazione, stabilire se tale frazione è propria, impropria o apparente.

#include <iostream>

using namespace std;

string verifica(int n, int d){
    if(n < d) return "propria.";
    
    else if(n%d == 0) return "apparente.";
    
    else return "impropria.";
}

int main()
{
    while(true){
        int n,d;
        cout<<"Inserisci il numeratore: ";
        cin>>n;
        cout<<"Inserisci il denominatore: ";
        cin>>d;
        if(n == 0 or d == 0){
            cout<<"Riprova con valori diversi da 0.\n\n";
        }
        else{
            cout<<"La frazione è "<<verifica(n,d);
            break;
        }
    }
    return 0;
}

//Consegna: Somma 10 numeri interi e comunica la somma quando viene inserito lo 0

#include <iostream>

using namespace std;

int main()
{
    int num[10] = {};
    int somma = 0;
    int lunghezza_num = sizeof(num)/sizeof(num[0]);
    for(int i = 0; i < lunghezza_num; i++){
        cout<<"Inserisci un numero: ";
        cin>>num[i];
        if(num[i] == 0) break;
    }
    for(int i = 0; i < lunghezza_num; i++){
        somma += num[i];
    }
    cout<<"La somma dei numeri inseriti è: "<<somma;
    
    return 0;
}

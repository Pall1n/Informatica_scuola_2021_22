//Consegna: Calcola il fattoriale di un numero

#include <iostream>

using namespace std;

int fattoriale(int num){
    int totale = 1;
    for(int i = 0; i < num; i++){
        totale *= (num-i);
    }
    return totale;
}

int main()
{
    int num;
    cout<<"Inserisci un numero: ";
    cin>>num;
    cout<<"Il fattoriale del numero inserito è: "<<fattoriale(num);
    
    return 0;
}

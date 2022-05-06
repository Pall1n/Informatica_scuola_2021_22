//Consegna: sottrarre due variabili tramite puntatori

#include <iostream>
using namespace std;

int main(){
    double a, b;
    cout<<"Inserisci a: ";
    cin>>a;
    cout<<"Inserisci b: ";
    cin>>b;
    
    double *n = &a;
    double *n1 = &b;
    
    double result = *n - *n1;
    cout<<"Il risultato della sottrazione è: "<<result;
    
    return 0;
}
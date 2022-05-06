//Consegna: Implementare la funzione swap passandogli i valori tramite puntatori

#include <iostream>
using namespace std;

void swapping(double *n, double *n1){
    double temp = *n;
    *n = *n1;
    *n1 = temp;
}

int main(){
    double a, b;
    cout<<"Inserisci a: ";
    cin>>a;
    cout<<"Inserisci b: ";
    cin>>b;
    
    swapping(&a, &b);
    
    cout<<"\na: "<<a<<endl<<"b: "<<b;
    
    return 0;
}
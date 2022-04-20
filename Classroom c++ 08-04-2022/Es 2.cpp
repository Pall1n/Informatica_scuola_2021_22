//Consegna: Risolve un equazione di secondo grado del tipo ax2+bx+c=0

#include <iostream>
#include <cmath>

using namespace std;

void calcolo(double a, double b, double c){
    double delta = (b*b)-(4*a*c);
    if(delta < 0) cout<<"Non esistono soluzioni reali.";
    else{
        double primo_ris = (-b + sqrt(delta))/(2*a);
        double secondo_ris = (-b - sqrt(delta))/(2*a);
        if(primo_ris == secondo_ris) cout<<"Le due soluzioni sono doppie coincidenti; esse equivalvono infatti a "<<primo_ris;
        else cout<<"La prima soluzione equivale a "<<primo_ris<<", mentre la seconda a "<<secondo_ris;
    }
}

int main(){
    double a,b,c;
    cout<<"Inserisci a: ";
    cin>>a;
    cout<<"Inserisci b (0 se pura): ";
    cin>>b;
    cout<<"Inserisci c (0 se spuria): ";
    cin>>c;
    calcolo(a,b,c);

    return 0;
}
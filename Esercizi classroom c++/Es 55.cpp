//Consegna: Dati un quadrato di lato L ed una circonferenza di raggio R stabilire quale delle due figure ha perimetro maggiore e quale delle due ha area maggiore.

#include <iostream>
using namespace std;

void calcolo_e_verifica(double l, double r){
    double P1 = l*4;
    double P2 = (r*2)*3.14;
    double A1 = l*l;
    double A2 = (r*r)*3.14;
    if(P1 > P2){
        cout<<"Il quadrato ha un perimetro maggiore."<<endl;
    }
    else if(P2 > P1){
        cout<<"Il cerchio ha un perimetro maggiore."<<endl;
    }
    else{
        cout<<"Hanno lo stesso perimetro."<<endl;
    }
    if(A1 > A2){
        cout<<"Il quadrato ha un'area maggiore.";
    }
    else if(A2 > A1){
        cout<<"Il cerchio ha un'area maggiore.";
    }
    else{
        cout<<"Hanno la stessa area.";
    }
}

int main(){
    double l, r;
    cout<<"Inserisci il lato del quadrato: ";
    cin>>l;
    cout<<"Inserisci il raggio della circonferenza: ";
    cin>>r;
    calcolo_e_verifica(l, r);
    return 0;
}

#include <iostream>
using namespace std;

string calcolo_e_verifica(double b1, double h1, double b2, double h2){
    double A1 = (b1*h1)/2;
    double A2 = (b2*h2)/2;
    if(A1 > A2){
        return "Il primo triangolo ha l'area maggiore.";
    }
    else if(A1 <A2){
        return "Il secondo triangolo ha l'area maggiore.";
    }
    else{
        return "I triangoli hanno la stessa area.";
    }
}

int main(){
    double b1,h1,b2,h2;
    cout<<"Inserisci la base del primo: ";
    cin>>b1;
    cout<<"Inserisci l'altezza del primo: ";
    cin>>h1;
    cout<<"Inserisci la base del secondo: ";
    cin>>b2;
    cout<<"Inserisci l'altezza del secondo: ";
    cin>>h2;
    cout<<calcolo_e_verifica(b1,h1,b2,h2);
    return 0;
}
#include <iostream>
using namespace std;

string verifica_triangolo(double lato1, double lato2, double lato3){
    if(lato1==lato2 && lato2==lato3){
        return "Il triangolo è equilatero.";
    }
    else if(lato1!=lato2 and lato2!=lato3 and lato1!=lato3){
        return "Il triangolo è scaleno.";
    }
    else{
        return "Il triangolo è isoscele.";
    }
}

int main(){
    double lato1,lato2,lato3;
    cout<<"Inserisci il primo lato: ";
    cin>>lato1;
    cout<<"Inserisci il secondo lato: ";
    cin>>lato2;
    cout<<"Inserisci il terzo lato: ";
    cin>>lato3;
    cout<<verifica_triangolo(lato1,lato2,lato3);
    return 0;
}
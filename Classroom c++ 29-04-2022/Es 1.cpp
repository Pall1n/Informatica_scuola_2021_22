//Consegna: Implementare una funzione per determinare se un triangolo è equilatero, isoscele o scaleno

#include <iostream>
using namespace std;

string det_triangolo(double a, double b, double c){
    if(a==b && b==c){
        return "equilatero";
    } else if((a==b || b==c || a==c)&&(a=!b || b!=c || a!= c)){
        return "isoscele";
    } else{
        return "scaleno";
    }
}

int main(){
    double a, b, c;
    cout<<"Inserisci a: ";
    cin>>a;
    cout<<"Inserisci b: ";
    cin>>b;
    cout<<"Inserisci c: ";
    cin>>c;
    
    cout<<"\nIl triangolo con i lati inseriti è: "<<det_triangolo(a,b,c);
    
    return 0;
}

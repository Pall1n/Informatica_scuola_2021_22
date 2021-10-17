//Consegna: Classificare un triangolo rispetto agli angoli.

#include <iostream>
using namespace std;

string verifica(double ang1, double ang2, double ang3){
    if(ang1 == 90 or ang2 == 90 or ang3 == 90){
        return "\nIl triangolo è rettangolo.";
    }
    else if(ang1==ang2 && ang2==ang3){
        return "\nIl triangolo è equilatero.";
    }
    else if(ang1!=ang2 && ang2!=ang3 && ang1!=ang3){
        return "\nIl triangolo è scaleno.";
    }
    else{
        return "\nIl triangolo è isoscele";
    }
}

int main(){
    double ang1,ang2,ang3,verifica_esistenza;
    cout<<"Inserisci il primo angolo: ";
    cin>>ang1;
    cout<<"Inserisci il secondo angolo: ";
    cin>>ang2;
    cout<<"Inserisci il terzo angolo: ";
    cin>>ang3;
    verifica_esistenza = ang1+ang2+ang3;
    if(verifica_esistenza == 180){
        cout<<verifica(ang1,ang2,ang3);
    }
    else{
        cout<<"\nIl triangolo con i seguenti angoli non può esistere. Riprova."<<endl<<endl;
        main();
    }
    return 0;
}

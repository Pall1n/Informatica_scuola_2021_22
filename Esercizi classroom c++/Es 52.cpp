#include <iostream>
using namespace std;

string verifica_triangolo(double ang1, double ang2, double ang3){
    double somma = ang1+ang2+ang3;
    if((ang1==90 or ang2==90 or ang3==90) && somma==180){
        return "Il triangolo è rettangolo.";
    }
    else{
        return "Il triangolo non è rettangolo.";
    }
}

int main(){
    double ang1, ang2, ang3;
    cout<<"Inserisci il primo angolo: ";
    cin>>ang1;
    cout<<"Inserisci il secondo angolo: ";
    cin>>ang2;
    cout<<"Inserisci il terzo angolo: ";
    cin>>ang3;
    cout<<verifica_triangolo(ang1,ang2,ang3);
    return 0;
}
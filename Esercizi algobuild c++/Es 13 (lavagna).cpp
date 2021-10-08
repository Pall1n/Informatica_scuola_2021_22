#include <iostream>
using namespace std;

int main()
{   
    double ang1,ang2,ang3,somma_ang;
    cout<<"Inserisci il primo angolo: ";
    cin>>ang1;
    cout<<"Inserisci il secondo angolo: ";
    cin>>ang2;
    cout<<"Inserisci il terzo angolo: ";
    cin>>ang3;
    somma_ang = ang1+ang2+ang3;
    
    if(somma_ang==180){
        cout<<"Angolo interno";
    }
    else{
        cout<<"Angolo esterno";
    }
    
    return 0;
}

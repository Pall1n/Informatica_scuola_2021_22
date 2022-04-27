/*Consegna:
Definite 3 variabili sulla funzione main, implementare una funzione 
che ne calcoli i valori assoluti tramite il passaggio di parametri 
per riferimento
*/

#include <iostream>
using namespace std;

void val_ass(double& a, double& b, double& c){
    if(a < 0) a*=-1;
    if(b < 0) b*=-1;
    if(c < 0) c*=-1;
}

int main()
{
    double a,b,c;
    cout<<"Inserisci a: ";
    cin>>a;
    cout<<"Inserisci b: ";
    cin>>b;
    cout<<"Inserisci c: ";
    cin>>c;
    
    val_ass(a,b,c);
    cout<<"\nIl valore assoluto di a equivale a "<<a;
    cout<<"\nIl valore assoluto di b equivale a "<<b;
    cout<<"\nIl valore assoluto di c equivale a "<<c;
    
    return 0;
}

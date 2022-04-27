/*Consegna:
Restituisce il maggiore e il minore di una serie di numeri inseriti da tastiera
*/

#include <iostream>
using namespace std;

void calc_max_min(unsigned int n, double& max, double& min){
    double temp;
    cout<<"1) Inserisci numero: ";
    cin>>max;
    min = max;
    for(int i = 1; i < n; i++){
        cout<<i+1<<") Inserisci numero: ";
        cin>>temp;
        if(temp > max) max = temp;
        else if(temp < min) min = temp;
    }
}

int main(){
    unsigned int n;
    double max, min;
    cout<<"Inserisci il numero di numeri da inserire: ";
    cin>>n;
    calc_max_min(n, max, min);
    
    cout<<"\nIl numero più grande inserito è: "<<max<<
          "\nIl numero più piccolo inserito è: "<<min;

    return 0;
}

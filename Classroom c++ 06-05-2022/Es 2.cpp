//Consegna: Trovare il massimo tra due numeri tramite puntatori

#include <iostream>
using namespace std;

int main(){
    double a, b;
    cout<<"Inserisci a: ";
    cin>>a;
    cout<<"Inserisci b: ";
    cin>>b;
    
    double *n = &a;
    double *n1 = &b;
    
    if(*n > *n1){
        cout<<*n<<" è maggiore di "<<*n1;
    } else{
        cout<<*n1<<" è maggiore di "<<*n;
    }
    
    return 0;
}
//Consegna: Dato un numero intero N, stabilire se è divisibile per A. (Controllare il resto della divisione). 

#include <iostream>

using namespace std;

void verifica(int n, int a){
    if(n%a == 0){
        cout<<n<<" è divisibile per "<<a<<".";
    }
    else{
        cout<<n<<" non è divisibile per "<<a<<".";
    }
}

int main(){
    int n,a;
    cout<<"Inserisci un numero: ";
    cin>>n;
    cout<<"Verifica se è diisibile per: ";
    cin>>a;
    verifica(n,a);
    return 0;
}
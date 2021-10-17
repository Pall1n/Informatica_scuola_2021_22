//Consegna: Verificare se un numero dato in input è divisibile per 3 o per 7.  

#include <iostream>

using namespace std;

void verifica(int n){
    if(n%3 == 0 or n%7 == 0){
        cout<<n<<" è divisibile per 3 o per 7 o per entrambi.";
    }
    else{
        cout<<n<<" non è divisibile nè per 3 e neanche per 7.";
    }
}

int main(){
    int n;
    cout<<"Inserisci un numero: ";
    cin>>n;
    verifica(n);
    return 0;
}
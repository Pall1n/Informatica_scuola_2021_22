//Consegna: Verificare se un numero dato in input è divisibile per 3 ma non per 5.

#include <iostream>

using namespace std;

void verifica(int n){
    if(n%3 == 0 and n%5 != 0){
        cout<<n<<" è divisibile per 3 ma non per 5.";
    }
    else{
        cout<<n<<" è divisibile per entrambi o per 5 ma non per 3 o per nessuno.";
    }
}

int main(){
    int n;
    cout<<"Inserisci un numero: ";
    cin>>n;
    verifica(n);
    return 0;
}
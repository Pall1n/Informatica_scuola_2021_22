//Consegna: Verificare se un numero dato in input è divisibile sia per 3 sia per 5.  

#include <iostream>

using namespace std;

void verifica(int n){
    if(n%3 == 0 and n%5 == 0){
        cout<<n<<" è divisibile sia per 3 che per 5.";
    }
    else{
        cout<<n<<" non è divisibile per entrambi, potrebbe però essere divisibile per uno dei 2.";
    }
}

int main(){
    int n;
    cout<<"Inserisci un numero: ";
    cin>>n;
    verifica(n);
    return 0;
}
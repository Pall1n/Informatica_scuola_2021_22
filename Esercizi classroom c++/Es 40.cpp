#include <iostream>

using namespace std;

string verifica(int a){
    if(a%2 == 0){
        return "pari";
    }
    else{
        return "dispari";
    }
}

int main()
{
    int a;
    cout<<"Inserisci un numero: ";
    cin>>a;
    cout<<"Il numero è "<<verifica(a);
    return 0;
}
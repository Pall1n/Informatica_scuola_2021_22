#include <iostream>

using namespace std;

int main()
{
    int a,b;
    a = 0;
    while(a<=30){
        cout<<"Inserisci un numero: ";
        cin>>b;
        a = a+b;
        cout<<"Sei a quota "<<a<<"\n";
    }
    cout<<"Hai superato il numero 30";

    return 0;
}

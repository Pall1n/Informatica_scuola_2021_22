#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    c = 0;
    while(a!=99){
        cout<<"Inserisci un numero: ";
        cin>>b;
        c = c+b;
        a = b;
        cout<<"Somma: "<<c<<"\n";
    }
    cout<<"Hai scritto 99";

    return 0;
}

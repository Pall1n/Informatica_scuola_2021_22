#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d;
    cout<<"Inserisci a: ";
    cin>>a;
    cout<<"Inserisci b: ";
    cin>>b;
    cout<<"Inserisci c: ";
    cin>>c;
    if(a>b and a>c){
        cout<<"Il numero maggiore è: "<<a;
    }
    else if(b>a and b>c){
        cout<<"Il numero maggiore è: "<<b;
    }
    else{
        cout<<"Il numero maggiore è: "<<c;
    }

    return 0;
}

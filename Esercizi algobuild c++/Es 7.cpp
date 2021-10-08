#include <iostream>

using namespace std;

int main()
{
    int T;
    cout<<"Inserisci la temperatura: ";
    cin>>T;
    if(T==0){
        cout<<"La temperatura è uguale a zero";
    }
    else if(T>0){
        cout<<"La temperatura è maggiore di zero";
    }
    else{
        cout<<"La temperatura è minore di zero";
    }

    return 0;
}

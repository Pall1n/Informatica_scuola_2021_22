#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cout<<"Inserisci a: ";
    cin>>a;
    cout<<"Inserisci b: ";
    cin>>b;
    if(a==b*b){
        cout<<"è il quadrato";
    }
    else{
        cout<<"Non è il quadrato";
    }

    return 0;
}

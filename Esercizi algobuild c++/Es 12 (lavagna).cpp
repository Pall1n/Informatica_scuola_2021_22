#include <iostream>
using namespace std;

int main()
{   
    int a,b;
    cout<<"Inserisci a: ";
    cin>>a;
    cout<<"Inserisci b: ";
    cin>>b;
    if(a == b*b) {
        cout << "a è il quadrato di b.";
    }
    else{
        cout << "a non è il quadrato di b.";  
    }
    
    return 0;
}

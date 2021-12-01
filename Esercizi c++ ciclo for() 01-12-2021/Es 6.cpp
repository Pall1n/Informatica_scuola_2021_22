//Consegna: Stampare i dieci numeri pari successivi al numero N

#include <iostream>

using namespace std;

int main()
{
    int N;
    cout<<"Inserisci un numero: ";
    cin>>N;
    for(int i = 1; i <= 20; i++){
        int successivi = N+i;
        if(successivi%2 == 0){
            cout<<successivi<<endl;
        }
    }

    return 0;
}
//Consegna: Stampare i dieci numeri pari successivi al numero N

#include <iostream>

using namespace std;

int main()
{
    int N;
    cout<<"Inserisci un numero: ";
    cin>>N;
    int i = 1;
    while(i <= 20){
        int successivi = N+i;
        if(successivi%2 == 0){
            cout<<successivi<<endl;
        }
        i++;
    }

    return 0;
}

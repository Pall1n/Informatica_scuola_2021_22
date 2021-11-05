//Consegna: Stampare multipli di A minori di N

#include <iostream>

using namespace std;

int main()
{
    double N, A;
    cout<<"Inserisci un numero N: ";
    cin>>N;
    cout<<"Inserisci un numero A: ";
    cin>>A;
    int i = 1;
    while(A*i < N && i > 0){
        double prodotto = A*i;
        cout<<prodotto<<endl;
        i++;
    }

    return 0;
}

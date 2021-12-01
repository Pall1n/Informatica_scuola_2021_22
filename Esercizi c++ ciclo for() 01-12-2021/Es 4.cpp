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
    for(int i = 1; A*i < N; i++){
        double prodotto = A*i;
        cout<<prodotto<<endl;
    }

    return 0;
}
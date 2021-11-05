//Consegna: Stampare i numeri pari minori di N

#include <iostream>

using namespace std;

int main()
{
    int N;
    int i = 0;
    cout<<"Inserisci un numero per la sequenza: ";
    cin>>N;
    while(i <= N){
        if(i%2 == 0){
            cout<<i<<endl;
        }
        i++;
    }

    return 0;
}

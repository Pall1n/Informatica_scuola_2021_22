//Consegna: Stampare i numeri pari minori di N

#include <iostream>

using namespace std;

int main()
{
    int N;
    cout<<"Inserisci un numero per la sequenza: ";
    cin>>N;
        for(int i = 0; i <= N; i++){
        if(i%2 == 0){
            cout<<i<<endl;
        }
    }

    return 0;
}
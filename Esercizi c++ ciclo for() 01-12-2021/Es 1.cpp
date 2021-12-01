//Consegna: Stampare i primi N numeri interi

#include <iostream>

using namespace std;

int main()
{
    int N;
    cout<<"Inserisci un numero per la sequenza: ";
    cin>>N;
    for(int i = 1; i <= N; i++){
        cout<<i<<endl;
    }

    return 0;
}
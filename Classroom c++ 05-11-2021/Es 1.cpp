//Consegna: Stampare i primi N numeri interi

#include <iostream>

using namespace std;

int main()
{
    int N;
    int i = 1;
    cout<<"Inserisci un numero per la sequenza: ";
    cin>>N;
    while(i <= N){
        cout<<i<<endl;
        i++;
    }

    return 0;
}

//Consegna: Inserendo 10 numeri interi, calcola quanti numeri pari sono stati inseriti

#include <iostream>

using namespace std;

int main()
{
    int num[10] = {};
    int num_pari = 0;
    int num_disp = 0;
    int lunghezza_num = sizeof(num)/sizeof(num[0]);
    for(int i = 0; i < lunghezza_num; i++){
        cout<<"Inserisci un numero: ";
        cin>>num[i];
    }
    cout<<"Hai inserito ";
    for(int i = 0; i < lunghezza_num; i++){
        if(num[i]%2 == 0) num_pari++;
        else num_disp++;
    }
    cout<<"Hai inserito "<<num_pari<<" numeri pari e "<<num_disp<<" numeri dispari.";
    
    return 0;
}

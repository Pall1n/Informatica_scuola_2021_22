#include <iostream>

using namespace std;

int main()
{
    int prezzo,soldi,resto;
    cout<<"Quanto costa l'oggetto? ";
    cin>>prezzo;
    cout<<"Quanti soldi hai: ";
    cin>>soldi;
    if(prezzo<=soldi){
        resto = soldi-prezzo;
        cout<<"Puoi comprarlo, ti rimarrebbero: "<<resto;
    }
    else{
        cout<<"Non puoi permettertelo";
    }

    return 0;
}

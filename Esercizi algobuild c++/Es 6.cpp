#include <iostream>

using namespace std;

int main()
{
    int prezzo = 30;
    int giorni,costo;
    cout<<"Per quanti giorni vuoi noleggiare? ";
    cin>>giorni;
    costo = prezzo*giorni;
    if(giorni>6){
        costo = costo - (costo/10);
        cout<<"Hai il diritto allo sconto, devi pagare: "<<costo;
    }
    else{
        cout<<"Non hai diritto allo sconto, devi pagare: "<<costo;
    }

    return 0;
}

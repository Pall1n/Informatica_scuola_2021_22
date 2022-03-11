/*Consegna:
In un albergo il prezzo della camera dipende dal piano in cui ci si trova secondo la seguente tabella.
piano 1 € 35
piano 2 € 45
piano 3 € 55
piano 4 € 65
Calcola il prezzo del conto sapendo il numero di giorni di soggiorno e il piano della camera.
*/

#include <iostream>
using namespace std;

int main()
{
    short unsigned int piano;
    short unsigned int giorni;
    
    cout<<"Quanti giorni di soggiorno? ";
    cin>>giorni;
    cout<<"\nPiani disponibili:\n"
          "1) 35€/giorno;\n"
          "2) 45€/giorno;\n"
          "3) 55€/giorno;\n"
          "4) 65€/giorno.\n\n"
          "Scelta: ";
    cin>>piano;
    
    unsigned int totale = giorni;
    
    switch(piano){
        case 1:
        totale *= 35;
        break;
        case 2:
        totale *= 45;
        break;
        case 3:
        totale *= 55;
        break;
        case 4:
        totale *= 65;
        break;
        default:
        cout<<"Scelta non valida!";
        exit(0);
    }
    
    cout<<"Il totale da pagare equivale a: "<<totale<<"€";

    return 0;
}
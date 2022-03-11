/*Consegna:
Si scriva un programma in linguaggio C++ che permetta di stabilire la stagione 
corrispondente al mese inserito come intero dall’utente.
Esempio: se l’utente digita 1 (Gennaio) il programma deve stampare Inverno
Qualora il mese sia Marzo, Giugno, Settembre e Dicembre, tutti mesi a cavallo 
di due stagioni, si richieda all’utente di specificare anche il giorno. Se il 
giorno e’ compreso tra 1 e 20 si considera la stagione precedente altrimenti 
quella successiva.
*/

#include <iostream>
using namespace std;

int main()
{
    short unsigned int mese, giorno;
    
    cout<<"Inserisci il mese: ";
    cin>>mese;
    
    switch(mese){
        case 12:
            cout<<"Inserisci giorno: ";
            cin>>giorno;
            if(giorno < 21) cout<<"\nAutunno";
            else cout<<"\nInverno";
            break;
        
        case 1:
        case 2:
            cout<<"\nInverno";
            break;
        
        case 3:
            cout<<"Inserisci giorno: ";
            cin>>giorno;
            if(giorno < 21) cout<<"\nInverno";
            else cout<<"\nPrimavera";
            break;
        
        case 4:
        case 5:
            cout<<"\nPrimavera";
            break;
        
        case 6:
            cout<<"Inserisci giorno: ";
            cin>>giorno;
            if(giorno < 21) cout<<"\nPrimavera";
            else cout<<"\nEstate";
            break;
        
        case 7:
        case 8:
            cout<<"\nEstate";
            break;
        
        case 9:
            cout<<"Inserisci giorno: ";
            cin>>giorno;
            if(giorno < 21) cout<<"\nEstate";
            else cout<<"\nAutunno";
            break;
        
        case 10:
        case 11:
            cout<<"\nAutunno";
            break;
        
        default:
            cout<<"\nMese non valido";
    }

    return 0;
}

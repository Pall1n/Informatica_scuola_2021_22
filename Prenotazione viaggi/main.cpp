/* Consegna:
Un'agenzia di viaggi effettua le prenotazioni per i voli della compagnia Rapisardi Airlines, che applica delle tariffe standard per le seguenti destinazioni:
1) Catania-Roma 30€;
2) Catania-Praga 55€;
3) Catania-New York 400€.

Al momento della prenotazione il cliente dovrà indicare il numero di passeggeri da prenotare e l'eventuale supplemento del bagaglio in stiva, che corrisponde a €20 per 
le destinazioni europee e €50 per i voli intercontinentali.

Nel mese di Novembre l'agenzia applica uno sconto del 10% se il costo della prenotazione è superiore a €500.

Sul costo della prenotazione bisognerà calcolare le imposte di imbarco del 10% per destinazioni europee e del 17% per destinazioni intercontinentali.

Visualizzare:
1) Il totale lordo della prenotazione (con i bagagli);
2) Le imposte di imbarco;
3) Lo sconto;
4) Il totale netto da pagare;
5) Il messaggio "Sconto d'autunno" se è stato applicato lo sconto di Novembre.

Alla fine il programma dovrà prevedere il controllo dell'input in modo tale che non possano essere inseriti codici di destinazione diversi da quelli stabiliti.

Se il cliente ha bagagli in stiva, visualizzare il messaggio: "Recarsi per il check-in allo sportello 8".
*/

#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

string partenze[] = {"Catania Fontanarossa"};
int lenght_partenze = sizeof(partenze)/sizeof(partenze[0]);
string destinazioni_CT[] = {{"Roma Fiumicino", "Europeo", "30€"}, {"Praga Václav Havel", "Europeo", "55€"}, {"New York John F. Kennedy International", "Intercontinentale", "400€"}};
int lenght_destinazioni_CT = sizeof(destinazioni_CT)/sizeof(destinazioni_CT[0]);
int scelta;

class Programma{
    public:
    
    void clear(){
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }
    
    void partenze_scelta(){
        scelta = 0;
        while(scelta <= 0 || scelta > lenght_partenze){
            cout<<"================================\n"
                  "|           PARTENZE           |\n"
                  "================================\n";
                  
            cout<<"\nBenvenuto, da dove vuoi partire?\n";
            for(int i = 0; i < lenght_partenze; i++){
                cout<<i+1<<") "<<partenze[i]<<endl;
            }
            cout<<"\nIndica il numero della scelta: ";
            cin>>scelta;
            
            if(scelta > 0 && scelta <= lenght_partenze){
                clear();
                switch_partenze(scelta);
            }
            else{
                cout<<"\nScelta non valida, riprova.\n";
                sleep(2);
                clear();
            }
        }
    }
    
    void switch_partenze(char scelta){
        switch(scelta){
            case 1:
            destinazioni_catania();
            break;
        }
    }
    
    void destinazioni_catania(){
        scelta = 0;
        while(scelta <= 0 || scelta > lenght_destinazioni_CT){
            cout<<"================================\n"
                  "|         DESTINAZIONI         |\n"
                  "================================\n";
                  
            cout<<"\nQual'è la destinazione desiderata?\n";
            for(int i = 0; i < lenght_destinazioni_CT; i++){
                cout<<i+1<<") "<<destinazioni_catania[0][0]<<endl;
            }
            cout<<"\nIndica il numero della scelta: ";
            cin>>scelta;
            
            if(scelta > 0 && scelta <= lenght_destinazioni_CT){
                clear();
                switch_destinazioni_CT(scelta);
            }
            else{
                cout<<"\nScelta non valida, riprova.\n";
                sleep(2);
                clear();
            }
        }
    }
};


int main()
{
    Programma programma;
    programma.partenze_scelta();

    return 0;
}

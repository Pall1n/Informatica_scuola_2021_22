//Consegna: Inserendo il proprio giorno e mese di nascita, comunica il segno zodiacale corrispondente alla data inserita

#include <iostream>

using namespace std;

int main()
{
    string mesi[] = {"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"};
    int limite_giorni[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int lung_max = sizeof(mesi)/sizeof(mesi[0]);
    
    while(true){
        string mese;
        int giorno;
        cout<<"In che mese sei nato? ";
        cin>>mese;
        cout<<"In che giorno? ";
        cin>>giorno;
        for(int i = 0; i <= lung_max; i++){
            if(mese == mesi[i]){
                if(giorno > 0 && giorno <= limite_giorni[i]){
                    switch(i+1){
                        case 1:
                            if(giorno <= 19) cout<<"Sei Capricorno.";
                            else cout<<"Sei Acquario.";
                            break;
                        case 2:
                            if(giorno <= 19) cout<<"Sei Acquario.";
                            else cout<<"Sei Pesci.";
                            break;
                        case 3:
                            if(giorno <= 20) cout<<"Sei Pesci.";
                            else cout<<"Sei Ariete.";
                            break;
                        case 4:
                            if(giorno <= 19) cout<<"Sei Ariete.";
                            else cout<<"Sei Toro.";
                            break;
                        case 5:
                            if(giorno <= 20) cout<<"Sei Toro.";
                            else cout<<"Sei Gemelli.";
                            break;
                        case 6:
                            if(giorno <= 20) cout<<"Sei Gemelli.";
                            else cout<<"Sei Cancro.";
                            break;
                        case 7:
                            if(giorno <= 22) cout<<"Sei Cancro.";
                            else cout<<"Sei Leone.";
                            break;
                        case 8:
                            if(giorno <= 23) cout<<"Sei Leone.";
                            else cout<<"Sei Vergine.";
                            break;
                        case 9:
                            if(giorno <= 22) cout<<"Sei Vergine.";
                            else cout<<"Sei Bilancia.";
                            break;
                        case 10:
                            if(giorno <= 22) cout<<"Sei Bilancia.";
                            else cout<<"Sei Scorpione.";
                            break;
                        case 11:
                            if(giorno <= 21) cout<<"Sei Scorpione.";
                            else cout<<"Sei Sagittario.";
                            break;
                        case 12:
                            if(giorno <= 21) cout<<"Sei Sagittario.";
                            else cout<<"Sei Capricorno.";
                            break;
                    }
                    return 0;
                }
            }
        }
        cout<<"\nGiorno o mese non validi, riprova. (Inserisci il mese corretto con la prima lettera maiuscola)\n";
    }
}
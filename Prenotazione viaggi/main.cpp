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
#include <vector> //Per il vettore multidimensionale dei viaggi, lo uso al posto di un array per rendere dinamico l'uso della memoria
#include <string> /*Per la funzione stoi(), serve a trasformare una stringa di numeri in intero, lo uso per trasformare la stringa
del prezzo dei viaggi in un int*/
#include <time.h> //Per la verifica se è Novembre
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

vector<vector<vector<string>>> viaggi = {
    {
        {"Catania Fontanarossa", "CTA"},
        
        {"Roma Fiumicino", "FCO", "Europeo", "30"},
        {"Praga Vàclav Havel", "PRG", "Europeo", "55"},
        {"New York John F. Kennedy Int.", "JFK", "Intercontinentale", "400"}
    },
    {
        {"Test 2nd partenza", "TEST 2nd"},
        
        {"Test1", "Tested1", "Europeo", "80"},
        {"Test2", "Tested2", "Intercontinentale", "65"},
        {"test", "Tested3", "Intercontinentale", "90"}
    }
};

char alfabeto_controllo[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int partenza, destinazione, passeggeri, bagagli;
string data_partenza, data_ritorno, scelta, codice_p, codice_d, aeroporto_p, aeroporto_d;
bool andata_ritorno, sconto_novembre;

string colore_reset = "\033[0m";


time_t theTime = time(NULL);
struct tm *aTime = localtime(&theTime);
int anno = aTime->tm_year + 1900;
int mese = aTime->tm_mon + 1;
int giorno = aTime->tm_mday;


class Programma{
    public:
    
    void clear(){
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }
    
    int verifica_int(int scelta){
        while(cin.fail()){
            cin.clear();
            cout<<"Inserisci un numero! ";
            cin.ignore(10000, '\n');
            cin>>scelta;
        }
        return scelta;
    }
    
    bool verifica_data(int GG, int MM, int AA){
        if((GG < giorno && (MM <= mese && AA <= anno)) || AA < anno || (MM < mese && (AA <= anno))) return false;
        
        else if(MM < 0 || MM > 12) return false;
        
        else if(MM == 2){
            if(AA%4 == 0){
				if(GG > 29 || GG < 0) return false;
            }
            else{
                if(GG > 28 || GG < 0) return false;
            }
        }
        
        else if(MM == 1 || MM == 3 || MM  == 5 || MM == 7 || MM == 8 || MM == 10 || MM == 12){
            if(GG > 31 || GG < 0) return false;
        }
        
        else if(GG > 30 || GG < 0) return false;
    	
    	return true;
    }
    
    string sistema_data(int gg, int mm, int aa){
        string data;
        if(gg < 10 && mm < 10) data = "0" + to_string(gg) + "/0" + to_string(mm) + "/" + to_string(aa);
        else if(gg < 10) data = "0" + to_string(gg) + "/" + to_string(mm) + "/" + to_string(aa);
        else if(mm < 10) data = to_string(gg) + "/0" + to_string(mm) + "/" + to_string(aa);
        else data = to_string(gg) + "/" + to_string(mm) + "/" + to_string(aa);
        return data;
    }
    
    int homepage(){
        int scelta_home = 0;
        while(scelta_home != 3 || scelta_home != 2 || scelta_home != 1){
            cout<<"\033[1;96m"<<"========================================\n"
                  "|          RAPISARDI AIRLINES          |\n"
                  "========================================\n\n"<<colore_reset<<
                  "Benvenuto, fai scegli un'opzione:\n"
                  "1) Prenota viaggio;\n"
                  "2) Informazioni su un viaggio;\n"
                  "3) Esci.\n\n"
                  "Scelta (indica il numero): ";
            cin>>scelta_home;
            scelta_home = verifica_int(scelta_home);
            clear();
            if(scelta_home == 1 && mese == 11){
                clear();
                schermata_offerte();
            }
            else if(scelta_home == 1){
                clear();
                partenze_funz();
            }
            else if(scelta_home == 2){
                clear();
                informazioni_viaggio();
            }
            else if(scelta_home == 3) exit(0);
            else{
                cout<<"\nScelta non valida, riprova!\n";
                sleep(1);
                clear();
            }
        }
        return 0;
    }
    
    void schermata_offerte(){
        string sconto_ok;
        sconto_novembre = true;
        cout<<"\033[1;96m"<<"====================================\n"
              "|         SCONTO D'AUTUNNO         |\n"
              "====================================\n\n"<<colore_reset<<
              "Solo per questo mese riceverai uno\n"
              "sconto del 10% in fase di pagamento\n"
              "se spendi più di 500€!\n\n"
              "\033[95m"<<"Scrivi qualsiasi cosa per continuare: ";
        cin>>sconto_ok;
        cout<<colore_reset;
        clear();
        partenze_funz();
    }
    
    void partenze_funz(){
        partenza = 0;
        while(partenza <= 0 || partenza > viaggi.size()){
            cout<<"\033[1;92m"<<"================================\n"
                  "|           PARTENZE           |\n"
                  "================================\n"<<colore_reset;
                
            cout<<"\nBenvenuto, da dove vuoi partire?\n";
            for(int i = 0; i < viaggi.size(); i++){
                cout<<i+1<<") "<<viaggi[i][0][0]<<endl;
            }
            cout<<"\nIndica il numero della scelta: ";
            cin>>partenza;
            partenza = verifica_int(partenza);
            
            if(partenza <= 0 || partenza > viaggi.size()){
                cout<<"Scelta non valida, riprova.\n";
                sleep(1);
                clear();
            }
        }
        partenza -= 1;
        clear();
        destinazioni_funz();
    }
    
    void destinazioni_funz(){
        destinazione = 0;
        while(destinazione <= 0 || destinazione > viaggi[partenza].size()-1){
            cout<<"\033[1;92m"<<"====================================\n"
                  "|           DESTINAZIONI           |\n"
                  "====================================\n"<<colore_reset;
                  
            cout<<"\nDestinazioni disponibili da "<<viaggi[partenza][0][1]<<":\n";
            for(int i = 1; i < viaggi[partenza].size(); i++){
                cout<<i<<") "<<viaggi[partenza][i][0]<<endl;
            }
            cout<<"\nIndica il numero della scelta: ";
            cin>>destinazione;
            destinazione = verifica_int(destinazione);
            
            if(destinazione <= 0 || destinazione > viaggi[partenza].size()-1){
                cout<<"Scelta non valida, riprova.\n";
                sleep(1);
                clear();
            }
        }
        clear();
        andata_funz();
    }
    
    void andata_funz(){
        int gg_andata = 0;
        int mm_andata = 0;
        int aa_andata = 0;
        while(!verifica_data(gg_andata, mm_andata, aa_andata)){
            cout<<"\033[1;92m"<<"==================================================\n"
                  "|                  DATA PARTENZA                 |\n"
                  "==================================================\n"<<colore_reset;
                  
            cout<<"\nData della partenza (GG/MM/AAAA) o giorno: ";
            cin>>gg_andata;
            gg_andata = verifica_int(gg_andata);
            if(cin.get() != '/'){
                cout<<"Inserisci il mese/anno o mese: ";
            }
            cin>>mm_andata;
            mm_andata = verifica_int(mm_andata);
            if(cin.get() != '/'){
                cout<<"Inserisci l'anno: ";
            }
            cin>>aa_andata;
            aa_andata = verifica_int(aa_andata);
            
            if(!verifica_data(gg_andata, mm_andata, aa_andata)){
                cout<<"\nData non valida, riprova.\n";
                sleep(1);
                clear();
            }
        }
        data_partenza = sistema_data(gg_andata, mm_andata, aa_andata);
        
        scelta = "";
        while(scelta != "si" && scelta != "no"){
            cout<<"Vuoi prenotare pure il ritorno (si/no)? ";
            cin>>scelta;
            if(scelta == "si"){
                andata_ritorno = true;
                clear();
                ritorno_funz(gg_andata, mm_andata, aa_andata);
            }
            else if(scelta == "no"){
                andata_ritorno = false;
                clear();
                passeggeri_funz();
            }
            else{
                cout<<"\nScelta non valida, riprova!\n";
                sleep(1);
                clear();
            }
        }
    }
    
    void ritorno_funz(int gg_andata, int mm_andata, int aa_andata){
        int gg_ritorno = 0;
        int mm_ritorno = 0;
        int aa_ritorno = 0;
        while(!verifica_data(gg_ritorno, mm_ritorno, aa_ritorno) && !((gg_andata < gg_ritorno && (mm_andata <= mm_ritorno && aa_andata <= aa_ritorno)) || aa_andata < aa_ritorno || (mm_andata < mm_ritorno && (aa_andata <= aa_ritorno)))){
            cout<<"\033[1;92m"<<"==================================================\n"
                  "|                   DATA RITORNO                 |\n"
                  "==================================================\n"<<colore_reset;
                  
            cout<<"\nData del ritorno (GG/MM/AAAA) o giorno: ";
            cin>>gg_ritorno;
            gg_ritorno = verifica_int(gg_ritorno);
            if(cin.get() != '/'){
                cout<<"Inserisci il mese/anno o mese: ";
            }
            cin>>mm_ritorno;
            mm_ritorno = verifica_int(mm_ritorno);
            if(cin.get() != '/'){
                cout<<"Inserisci l'anno: ";
            }
            cin>>aa_ritorno;
            aa_ritorno = verifica_int(aa_ritorno);
            
            if(!verifica_data(gg_ritorno, mm_ritorno, aa_ritorno) || !((gg_andata < gg_ritorno && (mm_andata <= mm_ritorno && aa_andata <= aa_ritorno)) || aa_andata < aa_ritorno || (mm_andata < mm_ritorno && (aa_andata <= aa_ritorno)))){
                cout<<"\nData non valida, riprova.\n";
                sleep(1);
                clear();
            }
        }
        data_ritorno = sistema_data(gg_ritorno, mm_ritorno, aa_ritorno);
        
        clear();
        passeggeri_funz();
    }
    
    void passeggeri_funz(){
        passeggeri = 0;
        while(passeggeri <= 0 || passeggeri > 9){
            cout<<"\033[1;92m"<<"==============================================\n"
                  "|                N. PASSEGGERI               |\n"
                  "==============================================\n"<<colore_reset;
                  
            cout<<"\nN. passeggeri ("<<viaggi[partenza][destinazione][3]<<"€ a persona, max. 9): ";
            cin>>passeggeri;
            passeggeri = verifica_int(passeggeri);
            
            if(passeggeri <= 0 || passeggeri > 9){
                cout<<"Scelta non valida, riprova.\n";
                sleep(1);
                clear();
            }
        }
        clear();
        bagagli_func();
    }
    
    void bagagli_func(){
        bagagli = -1;
        while(bagagli < 0 || bagagli > 9){
            cout<<"\033[1;92m"<<"==============================================\n"
                  "|                 N. BAGAGLI                 |\n"
                  "==============================================\n"<<colore_reset;
                  
            cout<<"\nN. bagagli in stiva (";
            if(viaggi[partenza][destinazione][2] == "Europeo") cout<<20;
            else cout<<50;
            cout<<"€ ognuno, max.9): ";
            cin>>bagagli;
            bagagli = verifica_int(bagagli);
            
            if(bagagli < 0 || bagagli > 9){
                cout<<"Numero di bagagli non valido, riprova.\n";
                sleep(1);
                clear();
            }
        }
        clear();
        totale_func();
    }
    
    void totale_func(){
        int bagagli_prezzo, sconto, imposta, totale_lordo, totale_netto;
        int totale_char = 0;
        string codice_viaggio;
        
        codice_p = viaggi[partenza][0][1];
        codice_d = viaggi[partenza][destinazione][1];
        
        aeroporto_p = viaggi[partenza][0][0];
        aeroporto_d = viaggi[partenza][destinazione][0];
        
        if(viaggi[partenza][destinazione][2] == "Europeo") bagagli_prezzo = 20;
        else bagagli_prezzo = 50;
        
        if(viaggi[partenza][destinazione][2] == "Europeo") imposta = 10;
        else imposta = 17;
        
        totale_lordo = (passeggeri*stoi(viaggi[partenza][destinazione][3]) + (bagagli*bagagli_prezzo));
        if(sconto_novembre && totale_lordo > 500) sconto = 10;
        else sconto = 0;
        totale_netto = totale_lordo + (totale_lordo*imposta/100) + (totale_lordo*sconto/100);
        
        scelta = "";
        
        while(scelta != "si" && scelta != "no"){
            cout<<"\033[1;92m"<<"================================================\n"
                  "|              RIEPILOGO VIAGGIO               |\n"
                  "================================================\n\n"<<colore_reset;
            
            cout<<"Viaggio: "<<codice_p<<"-"<<codice_d<<endl;
            cout<<"Aeroporto di partenza: "<<aeroporto_p<<endl;
            cout<<"Aeroporto di destinazione: "<<aeroporto_d<<endl;
            cout<<"Numero passeggeri: "<<passeggeri<<endl;
            cout<<"Numero bagagli: "<<bagagli<<endl<<endl;
            
            cout<<"Andata e ritorno: ";
            if(andata_ritorno) cout<<"si"<<endl;
            else cout<<"no"<<endl;
            cout<<"Data partenza: "<<data_partenza<<endl;
            if(andata_ritorno) cout<<"Data ritorno: "<<data_ritorno<<endl<<endl;
            
            cout<<"Totale lordo prenotazione (bagagli inclusi): "<<totale_lordo<<"€"<<endl;
            cout<<"Imposte applicate: "<<imposta<<"%"<<endl;
            if(sconto) cout<<"Sconto applicato: "<<sconto<<"%"<<endl;
            
            cout<<"Totale da pagare (sconto applicato): "<<totale_netto<<"€"<<endl;
            
            cout<<"\nEffettuare pagamento (si/no)? ";
            cin>>scelta;
            if(scelta == "si"){
                if(andata_ritorno)codice_viaggio = {data_ritorno[8], char(passeggeri + '0'), data_ritorno[3], codice_d[1], char(bagagli + '0'), data_partenza[0], codice_p[2], data_ritorno[0], data_partenza[6], codice_p[0], data_partenza[1], data_ritorno[1], data_ritorno[7], codice_d[0], data_partenza[3], data_partenza[4], codice_d[2], data_ritorno[4], data_partenza[7], data_ritorno[9], codice_p[1], data_ritorno[6], data_partenza[8], data_partenza[9]};
                else codice_viaggio = {char(passeggeri + '0'), codice_d[1], char(bagagli + '0'), data_partenza[0], codice_p[2], data_partenza[6], codice_p[0], data_partenza[1], codice_d[0], data_partenza[3], data_partenza[4], codice_d[2], data_partenza[7], codice_p[1], data_partenza[8], data_partenza[9]};
                
                for(char x : codice_viaggio){
                    if(isdigit(x)) totale_char += (x - '0');
                    else totale_char += x;
                }
                codice_viaggio += {alfabeto_controllo[totale_char%26]};
                
                cout<<"\nComplimenti, il pagamento è stato  effettuato!\n";
                cout<<"Il codice del tuo viaggio è: "<<codice_viaggio<<endl;
                cout<<"Inserisci qualsiasi cosa per continuare: ";
                cin>>scelta;
                cout<<"\nRitorno alla homepage...\n";
                sleep(1.5);
                clear();
                homepage();
            }
            else if(scelta == "no"){
                cout<<"\nOperazione annullata, ritorno alla home...\n";
                sleep(1.5);
                clear();
                homepage();
            }
            else{
                cout<<"\nScelta non valida, riprova!\n";
                sleep(1);
                clear();
            }
        }
    }
    
    bool verifica_codice(string c){
        int totale_char = 0;
        if(c.length() == 17){
            if(isdigit(c[0]) && isdigit(c[2]) && isdigit(c[3]) && isdigit(c[5]) && isdigit(c[7]) && isdigit(c[9]) && isdigit(c[10]) && isdigit(c[12]) && isdigit(c[14]) && isdigit(c[15])){
                codice_p = {c[6], c[13], c[4]};
                for(int i = 0; i < viaggi.size(); i++){
                    if(codice_p == viaggi[i][0][1]){
                        codice_d = {c[8], c[1], c[11]};
                        for(int n = 1; n < viaggi[i].size(); n++){
                            if(codice_d == viaggi[i][n][1]){
                                for(char x : c){
                                    if(isdigit(x)) totale_char += (x - '0');
                                    else totale_char += x;
                                }
                                totale_char -= c[16];
                                if(alfabeto_controllo[totale_char%26] == c[16]){
                                    passeggeri = c[0] - '0';
                                    bagagli = c[2] - '0';
                                    aeroporto_p = viaggi[i][0][0];
                                    aeroporto_d = viaggi[i][n][0];
                                    data_partenza = {c[3], c[7], '/', c[9], c[10], '/', c[5], c[12], c[14], c[15]};
                                    andata_ritorno = false;
                                    return true;
                                }
                            }
                        }
                    }
                }
                return false;
            } else return false;
        }
        else if(c.length() == 25){
            if(isdigit(c[0]) && isdigit(c[1]) && isdigit(c[2]) && isdigit(c[4]) && isdigit(c[5]) && isdigit(c[7]) && isdigit(c[8]) && isdigit(c[10]) && isdigit(c[11]) && isdigit(c[12]) && isdigit(c[14]) && isdigit(c[15]) && isdigit(c[17]) && isdigit(c[18]) && isdigit(c[19]) && isdigit(c[21]) && isdigit(c[22]) && isdigit(c[23])){
                for(int i = 0; i < viaggi.size(); i++){
                    codice_p = {c[9], c[20], c[6]};
                    if(codice_p == viaggi[i][0][1]){
                        for(int n = 1; n < viaggi[i].size(); n++){
                            codice_d = {c[13], c[3], c[16]};
                            if(codice_d == viaggi[i][n][1]){
                                for(char x : c){
                                    if(isdigit(x)) totale_char += (x - '0');
                                    else totale_char += x;
                                }
                                totale_char -= c[24];
                                if(alfabeto_controllo[totale_char%26] == c[24]){
                                    passeggeri = c[1] - '0';
                                    bagagli = c[4] - '0';
                                    aeroporto_p = viaggi[i][0][0];
                                    aeroporto_d = viaggi[i][n][0];
                                    data_partenza = {c[5], c[10], '/', c[14], c[15], '/', c[8], c[18], c[22], c[23]};
                                    data_ritorno = {c[7], c[11], '/', c[2], c[17], '/', c[21], c[12], c[0], c[19]};
                                    andata_ritorno = true;
                                    return true;
                                }
                            }
                        }
                    }
                }
                return false;
            } else return false;
        }
        else return false;
    }
    
    void informazioni_viaggio(){
        string codice_viaggio;
        scelta = "";
        while(!verifica_codice(codice_viaggio)){
            cout<<"\033[1;92m"<<"========================================================\n"
                      "|                   VERIFICA VIAGGIO                   |\n"
                      "========================================================\n"<<colore_reset;
            
            cout<<"Inserisci il codice viaggio (maiuscolo): ";
            cin>>codice_viaggio;
            if(!verifica_codice(codice_viaggio)){
                cout<<"\nCodice viaggio non valido, riprova! \n";
                sleep(1);
                clear();
            }
        }
        
        cout<<"\nViaggio: "<<codice_p<<"-"<<codice_d<<endl;
        cout<<"Aeroporto di partenza: "<<aeroporto_p<<endl;
        cout<<"Aeroporto di destinazione: "<<aeroporto_d<<endl;
        cout<<"Numero passeggeri: "<<passeggeri<<endl;
        cout<<"Numero bagagli: "<<bagagli<<endl<<endl;
        
        cout<<"Andata e ritorno: ";
        if(andata_ritorno) cout<<"si"<<endl;
        else cout<<"no"<<endl;
        cout<<"Data partenza: "<<data_partenza<<endl;
        if(andata_ritorno) cout<<"Data ritorno: "<<data_ritorno<<endl<<endl;
        cout<<"Inserisci qualsiasi cosa per tornare alla home: ";
        cin>>scelta;
        clear();
        homepage();
    }
};

int main()
{
    Programma programma;
    programma.homepage();

    return 0;
}



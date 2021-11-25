/* Consegna:
Il supermercato Rapisardi Shop necessita di un software per le registrazioni di cassa e per stampare gli scontrini sui prodotti venduti.
Considerando che nel periodo di Natale (tutto il mese di dicembre) lo shop effettua il 20 % di sconto sui prodotti e che ai clienti con 
la carta fedeltà è concesso un ulteriore 5% di sconto il programma, prima di operare dovrà essere inizializzato inserendo la data attuale.
Successivamente per ogni operazione il programma dovrà chiedere se il cliente possiede la carta o meno.
I prodotti sono individuati tramite il codice a barre e per ogni operazione dovrà essere effettuata la somma dei prodotti acquistati 
dal cliente per la stampa dello scontrino.
*/

#include <iostream>
#include <vector> //Per il vettore multidimensionale dei prodotti e delle carte fedeltà, lo uso al posto di un array per ottimizzare il programma senza calcolare la sua lunghezza
#include <string> /*Per la funzione stod() e stoi(), serve a trasformare una stringa in un numero, lo uso per trasformare la stringa
del prezzo dei prodotti e la quantità in un numero*/
#include <time.h> //Per la verifica se è Dicembre
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

vector<vector<string>> carte_fedelta = {
    {"Thomas Vita", "3486528634"},
    {"Franco Pino", "8543746786"},
    {"Massimo Giustino", "8436762347"},
    {"Renato Zero", "3468576677"}
};

vector<vector<string>> prodotti = {
    {"Mele", "8326574786", "1.50", "75"},
    {"Pere", "6572351928", "2.50", "92"},
    {"Manghi", "3462874356", "1.99" "12"},
    {"Ricotta", "5642634867", "1.29", "38"},
    {"Shampoo", "3482726834", "1.89", "70"},
    {"Tonno in scatola", "6737462387", "1.50", "54"},
    {"Crakers", "4736268126", "3.50", "90"},
    {"Bagnoschiuma", "3776237828", "3.19", "56"},
    {"Pollo allo spiedo", "6234752897", "3", "15"},
    {"Tramezzino", "3289745123", "1.69", "56"}
};

vector<vector<string>> carrello;

int quantita_voluta, quantita_disponibile, indice_prodotto, indice_fedelta;
double prezzo_lordo, prezzo_totale;
string codice, scelta, codice_fedelta;
int sconto_dicembre = 0;
int sconto_fedelta = 0;

string colore_reset = "\033[0m";

time_t theTime = time(NULL);
struct tm *aTime = localtime(&theTime);
int mese = aTime->tm_mon + 1;

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
    
    bool verifica_codice(string c){
        for(int i = 0; i < prodotti.size(); i++){
            if(prodotti[i][1] == c){
                indice_prodotto = i;
                return true;
            }
        }
        return false;
    }
    
    bool verifica_codice_carrello(string c){
        for(int i = 0; i < carrello.size(); i++){
            if(carrello[i][0] == c){
                indice_prodotto = i;
                return true;
            }
        }
        return false;
    }
    
    bool verifica_carrello(string codice, int quantita_voluta){
        for(int i = 0; i < carrello.size(); i++){
            if(carrello[i][0] == codice){
                int quantita_presente = stoi(carrello[i][2]);
                carrello[i][2] = to_string(quantita_presente + quantita_voluta);
                carrello[i][3] = to_string(stod(carrello[i][3]) + quantita_voluta*stod(prodotti[i][2]));
                return true;
            }
        }
        carrello.push_back({prodotti[indice_prodotto][1], prodotti[indice_prodotto][0], to_string(quantita_voluta), to_string(quantita_voluta*stod(prodotti[indice_prodotto][2]))});
        return false;
    }
    
    bool verifica_fedelta(string c){
        for(int i = 0; i < carte_fedelta.size(); i++){
            if(carte_fedelta[i][1] == c){
                indice_fedelta = i;
                return true;
            }
        }
        return false;
    }
    
    void homepage(){
        if(mese == 12) sconto_dicembre = 20;
        int scelta_home = 0;
        while(scelta_home != 3 || scelta_home != 2 || scelta_home != 1){
            cout<<"\033[1;96m"<<"========================================\n"
                  "|            RAPISARDI SHOP            |\n"
                  "========================================\n\n"<<colore_reset<<
                  "Benvenuto, scegli un'opzione:\n"
                  "1) Aggiungi prodotto al carrello;\n"
                  "2) Visualizza carrello\n"
                  "3) Esci.\n\n"
                  "Scelta (indica il numero): ";
            cin>>scelta_home;
            scelta_home = verifica_int(scelta_home);
            if(scelta_home == 1){
                clear();
                cassa();
            }
            else if(scelta_home == 2){
                clear();
                riepilogo_carrello();
            }
            else if(scelta_home == 3) exit(0);
            else{
                cout<<"\nScelta non valida, riprova!\n";
                sleep(1);
                clear();
            }
        }
    }
    
    void cassa(){
        codice = "";
        while(!verifica_codice(codice)){
            cout<<"\033[1;92m"<<"====================================================\n"
                  "|                       CASSA                      |\n"
                  "====================================================\n\n"<<colore_reset;
                
            cout<<"Codice prodotto ('home' per la homepage): ";
            cin>>codice;
            
            if(codice == "home"){
                cout<<"\nRitorno alla home...\n";
                sleep(1);
                clear();
                homepage();
            }
            
            else if(!verifica_codice(codice)){
                cout<<"Codice prodotto non valido, riprova.\n";
                sleep(1);
                clear();
            }
        }
        clear();
        informazioni_prodotto();
    }
    
    void informazioni_prodotto(){
        scelta = "";
        quantita_voluta = 0;
        quantita_disponibile = stoi(prodotti[indice_prodotto][3]);
        while(scelta != "si" && scelta != "no" && (quantita_voluta <= 0 || quantita_voluta > quantita_disponibile)){
            cout<<"\033[1;92m"<<"=============================================\n"
                  "|           INFORMAZIONI PRODOTTO           |\n"
                  "=============================================\n\n"<<colore_reset;
                  
            cout<<"Nome prodotto: "<<prodotti[indice_prodotto][0]<<endl;
            cout<<"Prezzo prodotto (IVA incl.): "<<prodotti[indice_prodotto][2]<<"€"<<endl;
            cout<<"Quantità disponibile: "<<quantita_disponibile<<endl;
            cout<<"Codice prodotto: "<<prodotti[indice_prodotto][1]<<endl;
            
            cout<<"\nVuoi aggiungere il prodotto al carrello? ";
            cin>>scelta;
            
            if(scelta == "si"){
                cout<<"Quantità richiesta: ";
                cin>>quantita_voluta;
                quantita_voluta = verifica_int(quantita_voluta);
                
                if(quantita_voluta <= 0 || quantita_voluta > quantita_disponibile){
                    cout<<"Quantità richiesta non valida, riprova!";
                    sleep(1);
                    clear();
                }
            }
            else if(scelta == "no"){
                cout<<"\nRitorno alla cassa...\n";
                sleep(1);
                clear();
                cassa();
            }
            else{
                cout<<"Scelta non valida, riprova.\n";
                sleep(1);
                clear();
            }
        }
        prodotti[indice_prodotto][3] = to_string(quantita_disponibile - quantita_voluta);
        if(verifica_carrello(codice, quantita_voluta)) cout<<"\nQuantità aggiunta al carrello\n";
        else cout<<"\nProdotto aggiunto al carrello\n";
        sleep(1);
        clear();
        homepage();
    }
    
    void riepilogo_carrello(){
        scelta = "";
        prezzo_lordo = 0;
        
        while(scelta != "si" && scelta != "no"){
            cout<<"\033[1;92m"<<"================================================\n"
                  "|              RIEPILOGO CARRELLO              |\n"
                  "================================================\n\n"<<colore_reset;
            
            if(carrello.size() > 0){
                cout<<"             Prodotti nel carrello:             "<<endl<<endl;
                for(int i = 0; i < carrello.size(); i++){
                    cout<<i+1<<")   "<<carrello[i][0]<<" - "<<carrello[i][1]<<" - "<<carrello[i][2]<<"x - "<<stod(carrello[i][3])<<"€"<<endl;
                    prezzo_lordo += stod(carrello[i][3]);
                }
                
                cout<<"\n\nPrezzo totale articoli (IVA incl.): "<<prezzo_lordo<<"€"<<endl;
                
                if(sconto_dicembre) cout<<"Sconto di Dicembre: "<<sconto_dicembre<<"%"<<endl;
                
                cout<<"\nCosa vuoi fare? ";
                cin>>scelta;
                
                if(scelta == "pagare"){
                    clear();
                    fedelta_funz();
                }
                else if(scelta == "rimuovere"){
                    clear();
                    rimuovere();
                }
                else if(scelta == "back"){
                    cout<<"\nOk, ritorno alla home...\n";
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
            else{
                cout<<"          Nessun prodotto nel carrello.         \n"
                      "           Ritorno alla home in 3 sec.          \n";
                sleep(3);
                clear();
                homepage();
            }
        }
    }
    
    void rimuovere(){
        codice = "";
        quantita_voluta = 0;
        
        while(!verifica_codice_carrello(codice)){
            cout<<"\033[1;92m"<<"==============================================================\n"
                      "|                      RIMUOVI ARTICOLO                      |\n"
                      "==============================================================\n\n"<<colore_reset;
            
            cout<<"                   Prodotti da poter rimuovere:               "<<endl<<endl;
            for(int i = 0; i < carrello.size(); i++){
                cout<<i+1<<")   "<<carrello[i][0]<<" - "<<carrello[i][1]<<"x - "<<carrello[i][2]<<endl;
            }
            
            cout<<"\n\nCodice prodotto da eliminare ('back' per annullare): ";
            cin>>codice;
            if(codice == "back"){
                cout<<"\nRitorno al carrello...\n";
                sleep(1);
                clear();
                riepilogo_carrello();
            }
            else if(!verifica_codice_carrello(codice)){
                cout<<"\nCodice non valido, riprova!\n";
                sleep(1);
                clear();
            }
        }
        
        while(quantita_voluta <= 0 || quantita_voluta > stoi(carrello[indice_prodotto][2])){
            cout<<"Quantità da eliminare: ";
            cin>>quantita_voluta;
            quantita_voluta = verifica_int(quantita_voluta);
            if(quantita_voluta <= stoi(carrello[indice_prodotto][2])){
                if(quantita_voluta == stoi(carrello[indice_prodotto][2])){
                    carrello.erase(carrello.begin() + indice_prodotto);
                }
                else{
                    carrello[indice_prodotto][3] = to_string(stod(carrello[indice_prodotto][3]) - (quantita_voluta*(stod(carrello[indice_prodotto][3])/stoi(carrello[indice_prodotto][2]))));
                    carrello[indice_prodotto][2] = to_string(stoi(carrello[indice_prodotto][2]) - quantita_voluta);
                }
                cout<<"\nFatto! Ritorno alla home...\n";
                sleep(2);
                clear();
                homepage();
            }
            else{
                cout<<"\nQuantità non valida, riprova!\n";
            }
        }
    }
    
    void fedelta_funz(){
        scelta = "";
        codice_fedelta = "";
        
        while(scelta != "si" && scelta != "no" && !verifica_fedelta(codice_fedelta)){
            cout<<"\033[1;92m"<<"==========================================================\n"
                      "|                      CARTA FEDELTÀ                     |\n"
                      "==========================================================\n\n"<<colore_reset;
            
            cout<<"Si possiede la carta fedeltà ('back' per annullare)? ";
            cin>>scelta;
            
            if(scelta == "back"){
                cout<<"\nRitorno al carrello...\n";
                sleep(1);
                clear();
                riepilogo_carrello();
            }
            else if(scelta == "si"){
                cout<<"Codice fedeltà ('back' per annullare): ";
                cin>>codice_fedelta;
                if(codice_fedelta == "back"){
                    scelta = "";
                    clear();
                }
                else if(verifica_fedelta(codice_fedelta)) sconto_fedelta = 5;
                else{
                    cout<<"\nCodice non valido, riprova!\n";
                    sleep(1);
                    clear();
                }
            }
            else if(scelta == "no");
            else{
                cout<<"\nScelta non valida, riprova!\n";
                sleep(1);
                clear();
            }
        }
        clear();
        pagamento();
    }
    
    void pagamento(){
        scelta = "";
        prezzo_lordo = 0;
        
        while(scelta != "si" && scelta != "no"){
            cout<<"\033[1;92m"<<"=================================================\n"
                  "|                   PAGAMENTO                   |\n"
                  "=================================================\n\n"<<colore_reset;
            
            cout<<"          Prodotti pronti all'acquisto:          "<<endl<<endl;
            for(int i = 0; i < carrello.size(); i++){
                cout<<i+1<<")   "<<carrello[i][0]<<" - "<<carrello[i][1]<<" - "<<carrello[i][2]<<"x - "<<stod(carrello[i][3])<<"€"<<endl;
                prezzo_lordo += stod(carrello[i][3]);
            }
            prezzo_totale = prezzo_lordo - prezzo_lordo*sconto_dicembre/100 - prezzo_lordo*sconto_fedelta/100;
            
            cout<<"\n\nPrezzo articoli (IVA incl.): "<<prezzo_lordo<<"€"<<endl;
            
            if(sconto_dicembre) cout<<"Sconto di Dicembre: 20%"<<endl;
            cout<<"Sconto fedeltà: ";
            if(sconto_fedelta){
                cout<<"si ("<<sconto_fedelta<<"%)"<<endl;
                cout<<"Nome proprietario carta fedeltà: "<<carte_fedelta[indice_fedelta][0];
            }
            else if(!sconto_fedelta) cout<<"no";
            
            cout<<"\n\nTotale da pagare: "<<prezzo_totale<<"€"<<endl<<endl;
            
            cout<<"Effettuare il pagamento? ";
            cin>>scelta;
            
            if(scelta != "si" && scelta != "no"){
                cout<<"\nScelta non valida, riprova!\n";
            }
        }
        if(scelta == "no"){
            cout<<"\nOk, ritorno alla home...\n";
            sleep(2);
            clear();
            homepage();
        }
        else{
            clear();
            scontrino();
        }
    }
    
    void scontrino(){
        cout<<"\033[1;96m"<<"================================================\n"
                  "|                   SCONTRINO                  |\n"
                  "================================================\n\n"<<colore_reset;
        
        cout<<"              Prodotti acquistati:              "<<endl<<endl;
        for(int i = 0; i < carrello.size(); i++){
            cout<<i+1<<")   "<<carrello[i][0]<<" - "<<carrello[i][1]<<" - "<<carrello[i][2]<<"x - "<<stod(carrello[i][3])<<"€"<<endl;
        }
        
        cout<<"\033[92m"<<"\nTotale pagato: "<<prezzo_totale<<"€"<<colore_reset<<endl;
        cout<<"Scrivi qualsiasi cosa per continuare: ";
        cin>>scelta;
        
        carrello.erase(carrello.begin(), carrello.end());
        
        cout<<"\nTorno alla home...\n";
        sleep(2);
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
/*
Realizzare un programma che permetta di caricare in 4 vettori paralleli il
cognome, il nome, il tipo di abbonamento, e l'importo dell'abbonamento degli 
utenti di una palestra.
Dopo aver effettuato il caricamento, effettuare le seguenti operazioni:
1) Visualizzare l'importo totale degli abbonamenti ad un determinato servizio 
   dato in input.
2) Dato in input il cognome di un abbonato modificarne l'importo dell'abbonamento.
3) Trasportare in un'altro vettore i cognomi degli abbonati invertento l'ordine.
*/

#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

string nomi[] = {
    "Franco",
    "Antonio",
    "Alfonso",
    "Diego",
    "Maria",
    "Giulia",
    "Abdul",
    "Francesca",
    "Pietro"
};

string cognomi[] = {
    "Bollo",
    "Garante",
    "Speranza",
    "Maradona",
    "Braciola",
    "Bentino",
    "Bakin",
    "Trespiani",
    "Fico"
};

string tipo_abbonamento[] = {
    "pesistica",
    "bodybuilding",
    "pesistica",
    "jujutsu",
    "crossfit",
    "crossfit",
    "jujutsu",
    "bodybuilding",
    "crossfit"
};

double costi[] = {
    30,
    45,
    30,
    25,
    50,
    50,
    25,
    45,
    50
};

string abbonamenti[] = {"pesistica", "bodybuilding", "jujutsu", "crossfit", "yoga"};

int numero_utenti = sizeof(nomi)/sizeof(nomi[0]);
int numero_abbonamenti = sizeof(abbonamenti)/sizeof(abbonamenti[0]);

string colore_reset = "\033[0m";

class palestra{
    public:
    
    void clear(){
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }
    
    int verifica_int(int x){
        while(cin.fail()){
            cin.clear();
            cout<<"Inserisci un numero! ";
            cin.ignore(10000, '\n');
            cin>>x;
        }
        return x;
    }
    
    double verifica_double(double x){
        while(cin.fail()){
            cin.clear();
            cout<<"Inserisci un numero! ";
            cin.ignore(10000, '\n');
            cin>>x;
        }
        return x;
    }
    
    int verificare_esistenza(string valore, string array){
        if(array == "cognome"){
            for(int i = 0; i < numero_utenti; i++){
                if(cognomi[i] == valore) return i+1;
            }
        }
        else if(array == "abbonamento"){
            for(int i = 0; i < numero_abbonamenti; i++){
                if(abbonamenti[i] == valore) return 1;
            }
        }
        return 0;
    }
    
    void homepage(){
        int scelta = 0;
        while(scelta < 1 || scelta > 6){
            cout<<"\033[1;96m"<<"=========================================\n"
                  "|             RAPISARDI GYM             |\n"
                  "=========================================\n\n"<<colore_reset<<
                  "Benvenuto, scegli un'opzione:\n"
                  "1) Entrate totali di un servizio;\n"
                  "2) Modificare importo abbonamento utente;\n"
                  "3) Invertire array;\n"
                  "4) Esci.\n\n"
                  "Scelta (indica il numero): "<<"\033[92m";
            cin>>scelta;
            cout<<colore_reset;
            scelta = verifica_int(scelta);
            switch(scelta){
                case 1:
                clear();
                entrate_totali();
                break;
                case 2:
                clear();
                modifica_abbonamento();
                break;
                case 3:
                clear();
                invertire();
                break;
                case 4:
                clear();
                exit(0);
                default:
                cout<<"\nScelta non valida, riprova!\n";
                sleep(1);
                clear();
                break;
            }
        }
    }
    
    void entrate_totali(){
        string servizio;
        do{
            cout<<"\033[1;96m"<<"==========================================================\n"
                  "|                    GUADAGNI SPECIFICI                  |\n"
                  "==========================================================\n\n"<<colore_reset<<
                  "Abbonamento ('0' per tornare alla home): ";
            cin>>servizio;
            
            if(servizio == "0"){
                cout<<"\nRitorno alla home...\n";
                sleep(2);
                clear();
                homepage();
            }
            
            if(verificare_esistenza(servizio, "abbonamento")){
                double somma = 0;
                
                for(int i = 0; i < numero_utenti; i++){
                    if(tipo_abbonamento[i] == servizio) somma += costi[i];
                }
                
                if(!somma) cout<<"Nessun utente ha questo abbonamento";
                else cout<<"Questo abbonamento frutta "<<somma<<"€/mese";
                uscire_tornare();
            }
            else{
                cout<<"\nAbbonamento inesistente, riprova!\n";
                sleep(2);
                clear();
            }
            
        } while(!verificare_esistenza(servizio, "abbonamento"));
    }
    
    void modifica_abbonamento(){
        string cognome;
        int indice_utente;
        do{
            cout<<"\033[1;96m"<<"==========================================================\n"
                  "|                   MODIFICA ABBONAMENTO                 |\n"
                  "==========================================================\n\n"<<colore_reset<<
                  "Cognome ('0' per tornare alla home): ";
            cin>>cognome;
            
            if(cognome == "0"){
                cout<<"\nRitorno alla home...\n";
                sleep(2);
                clear();
                homepage();
            }
            
            indice_utente = verificare_esistenza(cognome, "cognome");
            
            if(indice_utente){
                double cambio;
                
                cout<<"Questo utente paga "<<costi[indice_utente-1]<<"€ al mese.\n"
                      "Nuovo prezzo: ";
                cin>>cambio;
                cambio = verifica_double(cambio);
                costi[indice_utente-1] = cambio;
                
                cout<<"\nCambio effetturato con successo!";
                uscire_tornare();
            }
            else{
                cout<<"\nUtente inesistente, riprova!\n";
                sleep(2);
                clear();
            }
            
        } while(!indice_utente);
    }
    
    void invertire(){
        string cognomi_invertiti[numero_utenti];
        
        for(int i = 0; i < numero_utenti; i++){
            cognomi_invertiti[i] = cognomi[(numero_utenti-1)-i];
        }
        
        cout<<"\033[1;96m"<<"=================================================\n"
                  "|               COGNOMI INVERTITI               |\n"
                  "=================================================\n\n"<<colore_reset<<
                  "I cognomi, all'inverso, sono:\n"<<"\033[95m";
        
        for(int i = 0; i < numero_utenti; i++){
            cout<<cognomi_invertiti[i]<<endl;
        }
        cout<<colore_reset;
        
        uscire_tornare();
    }
    
    void uscire_tornare(){
        string scelta;
        cout<<"\nRitornare alla home (si/no)? ";
        cin>>scelta;
        while(scelta != "si" && scelta != "no"){
            cout<<"Scelta non valida, riprova (si/no): ";
            cin>>scelta;
        }
        if(scelta == "si"){
            cout<<"\nRitorno alla home...\n";
            sleep(2);
            clear();
            homepage();
        }
        else{
            cout<<"\nUscita in corso...\n";
            sleep(2);
            clear();
            exit(0);
        }
    }
};

int main()
{
    palestra programma;
    programma.homepage();

    return 0;
}
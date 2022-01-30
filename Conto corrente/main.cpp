#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

vector<vector<string>> utenti = {{}};
vector<vector<string>> utenti_admin = 
{
    {"Paolo Larosa", "paolo_lar", "438298"},
    {"Testing Test", "testing_test", "test_398"}
};

int utente_index, bonifico_index, admin;
string colore_reset = "\033[0m";

time_t theTime = time(NULL);
struct tm *aTime = localtime(&theTime);
int anno = aTime->tm_year + 1900;
int mese = aTime->tm_mon + 1;
int giorno = aTime->tm_mday;

class Conto_corrente{
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
    
    void write(){
    	ofstream file;
    	file.open("Conti.txt");
    	for(int i = 0; i < utenti.size(); i++){
    	    for(int x = 0; x < utenti[0].size(); x++){
    	        file<<utenti[i][x]<<endl;
    	    }
    	    if(i < utenti.size()-1){
    	        file<<endl;
    	    }
    	}
    	file.close();
    }
    
    void read(){
    	ifstream file;
    	file.open("Conti.txt");
    	string line;
    	int x = 0;
	    for(int i = 1; getline(file, line); i++){
	        if(i%10 == 0){
	            x++;
	            utenti.push_back({});
	        }
	        else{
	            utenti[x].push_back(line);
	        }
	    }
    	file.close();
    }
    
    bool verifica_admin(string username, string password){
        for(int i = 0; i < utenti_admin.size(); i++){
            if(utenti_admin[i][1] == username && utenti_admin[i][2] == password){
                admin = 1;
                return true;
            }
        }
        return false;
    }
    
    bool esistenza_utente(string CF_utente){
        for(int i = 0; i < utenti.size(); i++){
            if(utenti[i][7] == CF_utente){
                utente_index = i;
                return true;
            }
        }
        return false;
    }
    
    bool verifica_login(string username, string password){
        for(int i = 0; i < utenti.size(); i++){
            if(utenti[i][2] == username && utenti[i][3] == password){
                admin = 0;
                utente_index = i;
                return true;
            }
        }
        return false;
    }
    
    bool verifica_iban(string iban){
        if(iban == utenti[utente_index][8]) return false;
        for(int i = 0; i < utenti.size(); i++){
            if(utenti[i][8] == iban){
                bonifico_index = i;
                return true;
            }
        }
        return false;
    }
    
    void login(){
        string username = "";
        string password = "";
        while(!verifica_login(username, password)){
            cout<<"\033[1;96m"<<"===========================================\n"
                      "|                  LOGIN                  |\n"
                      "===========================================\n\n"<<colore_reset<<
                      "Inserisci l'username: ";
            cin>>username;
            cout<<"Inserisci password: ";
            cin>>password;
            if(verifica_admin(username, password)){
                clear();
                homepage_admin();
            }
            else if(verifica_login(username, password)){
                clear();
                homepage();
            }
            else{
                cout<<"\nUsername e/o password errati, riprova.\n";
                sleep(1.5);
                clear();
            }
        }
    }
    
    void homepage(){
        int scelta = 0;
        while(scelta < 1 || scelta > 5){
            cout<<"\033[1;96m"<<"========================================\n"
                  "|            RAPISARDI BANK            |\n"
                  "========================================\n\n"<<colore_reset<<
                  "Benvenuto, scegli un'opzione:\n"
                  "1) Informazioni conto;\n"
                  "2) Preleva denaro;\n"
                  "3) Deposita denaro;\n"
                  "4) Effettua bonifico;\n"
                  "5) Esci.\n\n"
                  "Scelta (indica il numero): ";
            cin>>scelta;
            scelta = verifica_int(scelta);
            switch(scelta){
                case 1:
                clear();
                informazioni();
                break;
                case 2:
                clear();
                prelievo();
                break;
                case 3:
                clear();
                deposito();
                break;
                case 4:
                clear();
                inserimento_iban();
                break;
                case 5:
                clear();
                uscire();
                break;
                default:
                cout<<"\nScelta non valida, riprova!\n";
                sleep(1);
                clear();
                break;
            }
        }
    }
    
    void homepage_admin(){
        int scelta = 0;
        while(scelta < 1 || scelta > 4){
            cout<<"\033[1;96m"<<"========================================\n"
                  "|              ADMIN PAGE              |\n"
                  "========================================\n\n"<<colore_reset<<
                  "Benvenuto, scegli un'opzione:\n"
                  "1) Cerca utenti;\n"
                  "2) Aggiungi utente;\n"
                  "3) Esci.\n\n"
                  "Scelta (indica il numero): ";
            cin>>scelta;
            scelta = verifica_int(scelta);
            switch(scelta){
                case 1:
                clear();
                cerca();
                break;
                case 2:
                clear();
                registra();
                break;
                case 3:
                clear();
                uscire();
                break;
                default:
                cout<<"\nScelta non valida, riprova!\n";
                sleep(1);
                clear();
                break;
            }
        }
    }
    
    void cerca(){
        string CF_utente = "";
        while(!esistenza_utente(CF_utente)){
            cout<<"\033[1;96m"<<"==========================================\n"
                  "|              CERCA UTENTE              |\n"
                  "==========================================\n\n"<<colore_reset;
            cout<<"CF utente: ";
            cin>>CF_utente;
            if(esistenza_utente(CF_utente)){
                clear();
                informazioni();
            }
            else{
                cout<<"\nInformazioni non valide, riprova!\n";
                sleep(1);
                clear();
            }
        }
    }
    
    void registra_title(){
        cout<<"\033[1;96m"<<"===========================================\n"
                  "|              REGISTRAZIONE              |\n"
                  "===========================================\n\n"<<colore_reset;
    }
    
    void registra(){
        string nome_utente, data_di_nascita_utente, user_utente, pass_utente, IBAN_utente, CF_utente;
        int limite;
        string data_creazione = to_string(giorno) + "/" + to_string(mese) + "/" + to_string(anno);
        
        registra_title();
        cout<<"Nome e cognome: ";
        cin>>nome_utente;
        
        registra_title();
        cout<<"Data di nascita: ";
        cin>>data_di_nascita_utente;
        
        clear();
        registra_title();
        cout<<"Username: ";
        cin>>user_utente;
        cout<<"Password: ";
        cin>>pass_utente;
        
        clear();
        registra_title();
        cout<<"Limite: ";
        cin>>limite;
        limite = verifica_int(limite);
        
        clear();
        registra_title();
        cout<<"IBAN: ";
        cin>>IBAN_utente;
        
        clear();
        registra_title();
        cout<<"Codice fiscale: ";
        cin>>CF_utente;
        
        utenti.push_back({nome_utente, data_di_nascita_utente, user_utente, pass_utente, data_creazione, "0", to_string(limite), CF_utente, IBAN_utente});
        write();
        
        cout<<"\nRitorno alla home...\n";
        sleep(1);
        homepage_admin();
    }
    
    void informazioni(){
        string scelta = "";
        while(scelta != "si" && scelta != "no"){
            cout<<"\033[1;96m"<<"============================================\n"
                          "|            INFORMAZIONI CONTO            |\n"
                          "============================================\n"<<colore_reset<<
                          "Intestatario: "<<utenti[utente_index][0]<<
                          "\nData di nascita: "<<utenti[utente_index][1]<<
                          "\nCF intestatario: "<<utenti[utente_index][7]<<
                          "\nData apertura conto: "<<utenti[utente_index][4]<<
                          "\nSaldo contabile: "<<utenti[utente_index][5]<<"€"<<
                          "\nLimite prelievo: "<<utenti[utente_index][6]<<"€"<<
                          "\nIBAN: "<<utenti[utente_index][8]<<
                          "\n\nTornare alla home? (si/no): ";
            cin>>scelta;
            if(scelta == "si" && !admin){
                cout<<"\nRitorno alla home...\n";
                sleep(1);
                clear();
                homepage();
            }
            else if(scelta == "si" && admin){
                cout<<"\nRitorno alla home...\n";
                sleep(1);
                clear();
                homepage_admin();
            }
            else if(scelta == "no"){
                clear();
                uscire();
            }
            else{
                cout<<"\nScelta non valida, riprova!\n";
                sleep(1);
                clear();
            }
        }
    }
    
    void prelievo(){
        int quantita = -1;
        while(quantita < 0 || quantita > stoi(utenti[utente_index][5]) || quantita > stoi(utenti[utente_index][6])){
            cout<<"\033[1;96m"<<"==========================================\n"
                  "|                PRELIEVO                |\n"
                  "==========================================\n\n"<<colore_reset<<
                  "Quantità ('0' per annullare): ";
            cin>>quantita;
            quantita = verifica_int(quantita);
            if(quantita > 0 && quantita <= stoi(utenti[utente_index][5]) && quantita <= stoi(utenti[utente_index][6])){
                utenti[utente_index][5] = to_string(stoi(utenti[utente_index][5]) - quantita);
                write();
                cout<<"\nQuantità prelevata con successo!"
                      "\nTorno alla home...\n";
                sleep(1);
                clear();
                homepage();
            }
            else if(quantita == 0){
                cout<<"\nRitorno alla home...\n";
                sleep(1);
                clear();
                homepage();
            }
            else if(quantita < 0){
                cout<<"\nQuantità non valida, riprova!";
                sleep(1);
                clear();
            }
            else if(quantita > stoi(utenti[utente_index][5])){
                cout<<"\nQuantità maggiore della disponibilità contabile!\n";
                sleep(1);
                clear();
            }
            else if(quantita > stoi(utenti[utente_index][6])){
                cout<<"\nQuantità maggiore del limite possibile, riprova!\n";
                sleep(1);
                clear();
            }
        }
    }
    
    void deposito(){
        int quantita = -1;
        while(quantita < 0 || quantita > 10000){
            cout<<"\033[1;96m"<<"==========================================\n"
                  "|                DEPOSITO                |\n"
                  "==========================================\n\n"<<colore_reset<<
                  "Quantità ('0' per annullare): ";
            cin>>quantita;
            quantita = verifica_int(quantita);
            if(quantita > 0 && quantita <= 10000){
                utenti[utente_index][5] = to_string(stoi(utenti[utente_index][5]) + quantita);
                write();
                cout<<"\nQuantità depositata con successo!"
                      "\nTorno alla home...\n";
                sleep(1);
                clear();
                homepage();
            }
            else if(quantita == 0){
                cout<<"\nRitorno alla home...\n";
                sleep(1);
                clear();
                homepage();
            }
            else if(quantita < 0){
                cout<<"\nQuantità non valida, riprova!";
                sleep(1);
                clear();
            }
            else if(quantita > 10000){
                cout<<"\nQuantità troppo elevata, riprova!\n";
                sleep(1);
                clear();
            }
        }
    }
    
    void inserimento_iban(){
        string iban = "";
        while(!verifica_iban(iban)){
            cout<<"\033[1;96m"<<"==================================================================\n"
                  "|                            BONIFICO                            |\n"
                  "==================================================================\n\n"<<colore_reset<<
                  "IBAN beneficiario ('0' per annullare): ";
            cin>>iban;
            if(iban == "0"){
                cout<<"\nRitorno alla home...\n";
                sleep(1);
                clear();
                homepage();
            }
            else{
                if(verifica_iban(iban)){
                    clear();
                    bonifico(iban);
                }
                else{
                    cout<<"\nIBAN non valido, riprova!\n";
                    sleep(1);
                    clear();
                }
            }
        }
    }
    
    void bonifico(string iban){
        int quantita = -1;
        while(quantita < 0 || quantita > stoi(utenti[utente_index][5])){
            cout<<"\033[1;96m"<<"==================================================================\n"
                  "|                            BONIFICO                            |\n"
                  "==================================================================\n\n"<<colore_reset<<
                  "Quantità da inviare ('0' per annullare): ";
            cin>>quantita;
            quantita = verifica_int(quantita);
            if(quantita > 0 && quantita <= stoi(utenti[utente_index][5])){
                utenti[utente_index][5] = to_string(stoi(utenti[utente_index][5]) - quantita);
                utenti[bonifico_index][5] = to_string(stoi(utenti[bonifico_index][5]) + quantita);
                write();
                cout<<"\nQuantità inviata con successo!"
                      "\nTorno alla home...\n";
                sleep(1);
                clear();
                homepage();
            }
            else if(quantita == 0){
                cout<<"\nRitorno alla home...\n";
                sleep(1);
                clear();
                homepage();
            }
            else if(quantita < 0){
                cout<<"\nQuantità non valida, riprova!";
                sleep(1);
                clear();
            }
            else if(quantita > stoi(utenti[utente_index][5])){
                cout<<"\nQuantità maggiore della disponibilità contabile!\n";
                sleep(1);
                clear();
            }
        }
    }
    
    void uscire(){
        string scelta = "";
        while(scelta != "si" && scelta != "no"){
            cout<<"Si desidera uscire? ";
            cin>>scelta;
            if(scelta != "si" && scelta != "no"){
                cout<<"\nScelta non valida, riprova!\n";
                sleep(1);
                clear();
            }
        }
        while(scelta != "uscire" && scelta != "disconnettersi"){
            if(scelta == "si"){
                cout<<"Uscire o disconnettersi? "<<"\033[91m";
                cin>>scelta;
                cout<<colore_reset;
                if(scelta == "uscire"){
                    cout<<"\nUscita in corso...\n";
                    sleep(1);
                    exit(0);
                }
                else if(scelta == "disconnettersi"){
                    cout<<"\nDisconnessione in corso...\n";
                    sleep(1);
                    clear();
                    login();
                }
                else{
                cout<<"\nScelta non valida, riprova!\n";
                sleep(1);
                clear();
                }
            }
            else if(scelta == "no" && !admin){
                cout<<"\nRitorno alla home...\n";
                sleep(1);
                clear();
                homepage();
            }
            else if(scelta == "no" && admin){
                cout<<"\nRitorno alla home...\n";
                sleep(1);
                clear();
                homepage_admin();
            }
        }
    }
};

int main()
{
    Conto_corrente conto_corrente;
    conto_corrente.read();
    conto_corrente.login();
    
    return 0;
}
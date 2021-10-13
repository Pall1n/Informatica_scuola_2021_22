/*
Realizzare un programma che permetta di simulare la gestione di un ATM (Automated Teller Machine).
L'ATM ha una disponibilità iniziale di: 6000€;
L'utente può effettuare sia prelievi che versamenti;
Il limite giornaliero di prelievo è di: 250€;
Per ogni transazione è necessario indicare il PIN.
*/

#ifdef _WIN32 //Verifica se il OS è windows
#include <Windows.h> //Include un header permettendo a c++ di interfacciarsi con windows
#else
#include <unistd.h> //Include un header permettendo a c++ di interfacciarsi con linux
#endif //Fine condizione
#include <iostream>
#include <string> // Una libreria che mi servirà per delle operazioni

using namespace std;

string username[] = {"Paolo", "Mario", "Salvador", "Marco", "Gennaro", "Mortadella", "Francesca", "Chiara"}; //Info sugli account
string password[] = {"Ciao", "12345", "Spagna", "Poesia", "Rapina", "Pancetta", "Francia", "Mare"}; //Info sugli account
int soldi_user[] = {7000, 2000, 4500, 3800, 9000, 2700, 5000, 8400}; //Info sugli account
int limite_prelievo[] = {250,300,600,250,200,400,150,250}; //Info sugli account
int soldi_disponibili = 6000; //Info sull'ATM
int lunghezza_informazioni = sizeof(username)/sizeof(username[0]); //Calcolo il numero di account

class Atm{
    public:
    void clear(){ //Funzione per pulire lo schermo
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }
    
    void homepage(int i){ //Homepage dell'ATM
        string scelta;
        while(true){
            sleep(1);
            clear();
            cout<<"Benvenuto, "<<username[i]<<", hai "<<soldi_user[i]<< "€.\n"
            "L'ATM dispone di "<<soldi_disponibili<<"€.\n\n"
            "Scegli cosa vuoi fare: \n"
            "1) Preleva (limite di "<<limite_prelievo[i]<<"€ possibile);\n"
            "2) Deposita;\n"
            "3) Esci.\n\n"
            "Scelta: ";
            cin>>scelta;
            if(scelta == "1") soldi_user[i] -= prelievo(i);
            else if(scelta == "2") soldi_user[i] += deposito();
            else if(scelta == "3"){
                cout<<"\nUscita in corso...\n";
                sleep(1);
                break;
            }
            else{
                cout<<"Scelta non valida, riprova.\n";
                sleep(1);
            }
        }
    }
    
    int prelievo(int i){ //Funzione per il prelievo
        string PIN = verify_pin();
        string stringa_prelievo;
        int soldi_prelievo;
        while(limite_prelievo[i] > 0 && PIN == "Ok"){ //Finchè il limite non è stato già raggiunto e il pin da l'ok
            sleep(1);
            clear();
            cout<<"-----------------------------------\n";
            cout<<"|             PRELEVA             |\n";
            cout<<"-----------------------------------\n\n";
            cout<<"Prelievo ('0' per tornare indietro): ";
            cin>>stringa_prelievo;
            for(char carattere : stringa_prelievo){ //Per ogni carattere nella stringa appena inserita
                if(isdigit(carattere)) continue; //Verifico che il carattere inserito sia un numero
                else{ //Se non è un numero ritorno alla homepage
                    cout<<"\nValore non valido, ritorno alla homepage...\n";
                    sleep(1);
                    return 0;
                }
            }
            soldi_prelievo = stoi(stringa_prelievo); //Trasformo la stringa di verifica in intero per i calcoli
            if(soldi_prelievo > 0 && soldi_prelievo <= soldi_user[i] && limite_prelievo[i] - soldi_prelievo >= 0 && soldi_disponibili - soldi_prelievo >= 0){
                limite_prelievo[i] -= soldi_prelievo;
                soldi_disponibili -= soldi_prelievo;
                cout<<"\nTransazione eseguita, ritorno alla homepage...\n";
                sleep(1);
                return soldi_prelievo;
            }
            else if(soldi_prelievo == 0){
                cout<<"\nTorno alla homepage...\n";
                return 0;
            }
            else if(limite_prelievo[i] - soldi_prelievo < 0){
                cout<<"\nPrelievo non accettato, è necessario prelevare un valore minore per non superare il limite, riprova.\n";
                sleep(2);
            }
            else if(soldi_disponibili - soldi_prelievo < 0){
                cout<<"\nPrelievo non accettato, l'ATM non dispone dei soldi richiesti, riprova con un valore minore.\n";
                sleep(2);
            }
        }
        if(PIN != "Ok") return 0; //Se il PIN non da l'ok
        cout<<"\nHai superato il limite di prelievo, ritorno alla homepage...\n"; //Se il limite era già stato raggiunto
        sleep(2);
        clear();
        return 0;
    }

    int deposito(){ //Funzione per il deposito
        string PIN = verify_pin();
        string stringa_deposito;
        int soldi_deposito;
        while(PIN == "Ok"){ //Il pin da "Ok"
            sleep(1);
            clear();
            cout<<"------------------------------------\n";
            cout<<"|             DEPOSITA             |\n";
            cout<<"------------------------------------\n\n";
            cout<<"Deposito ('0' per tornare indietro): ";
            cin>>stringa_deposito;
            for(char carattere : stringa_deposito){ //Per ogni carattere nella stringa appena inserita
                if(isdigit(carattere))continue; //Verifico che il carattere inserito sia un numero
                else{ //Se non è un numero ritorno alla homepage
                    cout<<"\nValore non valido, ritorno alla homepage...\n";
                    sleep(1);
                    return 0;
                }
            }
            soldi_deposito = stoi(stringa_deposito); //Trasformo la stringa di verifica in intero per i calcoli
            if(soldi_deposito > 0){
                soldi_disponibili += soldi_deposito;
                cout<<"\nTransazione eseguita, ritorno alla homepage...\n";
                sleep(1);
                return soldi_deposito;
            }
            else if(soldi_deposito == 0){
                cout<<"\nTorno alla homepage...\n";
                return 0;
            }
        }
        return 0; //Se il PIN non da l'ok
    }
    
    int login(){ //Login utente
        string username_login, password_login;
        while(true){
            sleep(1);
            clear();
            cout<<"----------------------\n";
            cout<<"|       ACCEDI       |\n";
            cout<<"----------------------\n\n";
            cout<<"Inserisci username: ";
            cin>>username_login;
            cout<<"Inserisci password: ";
            cin>>password_login;
            
            for(int i = 0; i < lunghezza_informazioni; i++){ //Crea un numero sempre maggiore per indicare ogni account
                if(username[i] == username_login && password[i] == password_login) return i; //Se l'username e la password corrispondono alle info iniziali
                else continue; //Se non è così continua
            }
            cout<<"\nUsername e/o password non riconosciuti, riprova.\n"; 
        }
    }
    
    string verify_pin(){ //Chiede e verifica PIN
        string PIN;
        char consonante;
        int somma = 0;
        int consonanti = 0;
        const char alfabeto[27] = {'0','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        //Qua sopra è presente l'alfabeto
        cout<<"Inserisci il PIN: ";
        cin>>PIN;
        for(char carattere : PIN){ //Per ogmi carattere presente nella stringa digitata
            if(isdigit(carattere)) somma += carattere - '0'; //Se il carattere è un numero, lo trasformo in intero tramite un calcolo sulla tabella ASCII
            else if(consonanti != 0) return "Nope"; //Se sono state scritte più consonanti non dà l'ok
            else{ //Se il carattere non è un numero lo assengna alla variabile consonante e indica che è stato già inserito
                consonanti += 1;
                consonante = carattere;
            }
        }
        if(alfabeto[somma] == consonante && somma > 0 && PIN.length() == 4) return "Ok"; //Il PIN dà l'ok
        else{ //Se il PIN non rispetta l'algoritmo non dà l'ok
            cout<<"\nPIN errato, ritorno alla homepage...\n";
            sleep(1);
            return "No";
        }
    }
};

Atm atm; //Inizializza classe, per evitare di scrivere "Atm::"

int main(){ //Comincia da qui
    int i = atm.login(); //Chiede il login
    atm.homepage(i); //Mostra la homepage
    return 0;
}

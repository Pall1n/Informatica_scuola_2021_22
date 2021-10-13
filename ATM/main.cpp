#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <string>

using namespace std;

string username[] = {"Paolo", "Mario", "Salvador", "Marco", "Gennaro", "Mortadella", "Francesca", "Chiara"};
string password[] = {"Ciao", "12345", "Spagna", "Poesia", "Rapina", "Pancetta", "Francia", "Mare"};
int soldi_user[] = {7000, 2000, 4500, 3800, 9000, 2700, 5000, 8400};
int limite_prelievo[] = {250,300,600,250,200,400,150,250};
int soldi_disponibili = 6000;
int lunghezza_informazioni = sizeof(username)/sizeof(username[0]);

class Atm{
    public:
    void clear(){
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }
    
    void homepage(int i){
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
    
    int prelievo(int i){
        string PIN = verify_pin();
        string stringa_prelievo;
        int soldi_prelievo;
        while(limite_prelievo[i] > 0 && PIN == "Ok"){
            sleep(1);
            clear();
            cout<<"-----------------------------------\n";
            cout<<"|             PRELEVA             |\n";
            cout<<"-----------------------------------\n\n";
            cout<<"Prelievo ('0' per tornare indietro): ";
            cin>>stringa_prelievo;
            for(char carattere : stringa_prelievo){
                if(isdigit(carattere)) continue;
                else{
                    cout<<"\nValore non valido, ritorno alla homepage...\n";
                    sleep(1);
                    return 0;
                }
            }
            soldi_prelievo = stoi(stringa_prelievo);
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
        if(PIN != "Ok") return 0;
        cout<<"\nHai superato il limite di prelievo, ritorno alla homepage...\n";
        sleep(2);
        clear();
        return 0;
    }

    int deposito(){
        string PIN = verify_pin();
        string stringa_deposito;
        int soldi_deposito;
        while(PIN == "Ok"){
            sleep(1);
            clear();
            cout<<"------------------------------------\n";
            cout<<"|             DEPOSITA             |\n";
            cout<<"------------------------------------\n\n";
            cout<<"Deposito ('0' per tornare indietro): ";
            cin>>stringa_deposito;
            for(char carattere : stringa_deposito){
                if(isdigit(carattere))continue;
                else{
                    cout<<"\nValore non valido, ritorno alla homepage...\n";
                    sleep(1);
                    return 0;
                }
            }
            soldi_deposito = stoi(stringa_deposito);
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
        return 0;
    }
    
    int login(){
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
            
            for(int i = 0; i < lunghezza_informazioni; i++){
                if(username[i] == username_login && password[i] == password_login) return i;
                else continue;
            }
            cout<<"\nUsername e/o password non riconosciuti, riprova.\n"; 
        }
    }
    
    string verify_pin(){
        string PIN;
        char consonante;
        int somma = 0;
        int consonanti = 0;
        const char alfabeto[27] = {'0','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        cout<<"Inserisci il PIN: ";
        cin>>PIN;
        for(char carattere : PIN){
            if(isdigit(carattere)) somma += carattere - '0';
            else if(consonanti != 0) return "Nope";
            else{
                consonanti += 1;
                consonante = carattere;
            }
        }
        if(alfabeto[somma] == consonante && somma > 0 && PIN.length() == 4) return "Ok";
        else{
            cout<<"\nPIN errato, ritorno alla homepage...\n";
            sleep(1);
            return "No";
        }
    }
};

Atm atm;

int main(){
    int i = atm.login();
    atm.homepage(i);
    return 0;
}
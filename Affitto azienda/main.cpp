/*
Implementare un programma che ci permetta di calcolare il totale che deve pagare
un'impresa per l'affitto dei locali, tenuto conto che:
1.L'affitto è pari 15€ al metro quadrato.
2.Se il totale è superiore a 600€ verrà applicato uno sconto del 10%, in caso contrario del 5%.
3.Sul totale scontato calcolare l'imposta di registro del 2%.
4. Visualizzare l'importo dell'affitto senza sconto, lo sconto, l'affitto scontato, e l'imposta di registro
*/

#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

int sconto;
double prezzo_lordo, prezzo_scontato, imposta, misura;
string scelta = "";

string colore_reset = "\033[0m";

class Programma{
    public:
    
    void clear(){
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }
    
    int verifica_int(double numero){
        while(cin.fail() or numero < 0){
            cin.clear();
            cout<<"\nInserisci un numero valido! ";
            cin.ignore(10000, '\n');
            cin>>numero;
        }
        return numero;
    }
    
    void benvenuto(){
        cout<<"\033[1;96m"<<"=======================================\n"
                  "|              BENVENUTO              |\n"
                  "=======================================\n\n"<<colore_reset;
        
        cout<<"Salve, inserisci il numero di mq del \n"
              "locale del quale devi pagare l'affitto, \n"
              "('0' per uscire): ";
        cin>>misura;
        misura = verifica_int(misura);
        
        if(misura == 0){
            cout<<"\nUscita in corso...\n";
            sleep(1);
        }
        else{
            clear();
            totale_e_imposta();
        }
    }
    
    void totale_e_imposta(){
        prezzo_lordo = misura*15;
        if(prezzo_lordo > 600){
            sconto = 10;
            prezzo_scontato = prezzo_lordo - (prezzo_lordo/100)*sconto;
        }
        else{
            sconto = 5;
            prezzo_scontato = prezzo_lordo - (prezzo_lordo/100)*sconto;
        }
        imposta = (prezzo_scontato/100)*2;
        fine();
    }
    
    void fine(){
        cout<<"\033[1;96m"<<"========================================\n"
                  "|                 FINE                 |\n"
                  "========================================\n\n"<<colore_reset;
        
        cout<<"Totale senza sconto applicato: "<<prezzo_lordo<<"€\n"
              "Sconto applicato: "<<sconto<<"%\n"
              "Totale scontato: "<<prezzo_scontato<<"€ \n"
              "Imposta di registro: "<<imposta<<"€\n\n"
              "Ritornare alla home? (si/no): ";
        cin>>scelta;
        
        while(scelta != "si" && scelta != "no"){
            cout<<"Scelta non valida (si/no ammessi): ";
            cin>>scelta;
        }
        
        if(scelta == "si"){
            cout<<"\nRitorno alla home...\n";
            sleep(1);
            clear();
            benvenuto();
        }
        
        else{
            cout<<"\nOk, uscita in corso...\n";
            sleep(1);
        }
    }
};


int main()
{
    Programma programma;
    programma.benvenuto();

    return 0;
}
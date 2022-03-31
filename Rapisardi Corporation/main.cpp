/*Consegna:
L'azienda Rapisardi Corporation, dopo una lunga riunione del consiglio di
amministrazione, ha deciso che, per ottimizzare i processi aziendali, necessita di 
un software gestionale per catalogare i prodotti presenti in magazzino.
Hanno dunque deciso che il software in questione dovrà avere un menù con le seguenti 
funzionalità:
1) Inserimento prodotto;
2) Ricerca di un prodotto;
3) Cancellazione di un prodotto;
4) Somma del totale del valore dei prodotti;
5) Somma del valore dei prodotti della stessa tipologia.
*/

#include <iostream>
#include <algorithm>
#include<fstream>
#include <string>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

string categorie_legenda[] = {"smartphone", "alimentari", "elettrodomestici", "casa", "domotica", "computer", "ufficio", "gaming", "telefonia"}; //Categorie disponibili
int numero_categorie = sizeof(categorie_legenda)/sizeof(categorie_legenda[0]);
string categoria[1000];
string categoria_ordinata[1000];
int codice[1000];
int quantita[1000];
double prezzo[1000];
string nome[1000];
int prodotti_length = sizeof(codice)/sizeof(codice[0]);
string colore_reset = "\033[0m";

class warehouse{
    public:
    
    void clear(){
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }
    
    int verifica_int(int &x){
        while(cin.fail()){
            cin.clear();
            cout<<"Inserisci un numero! ";
            cin.ignore(10000, '\n');
            cin>>x;
        }
        return x;
    }
    
    int verifica_double(double &x){
        while(cin.fail()){
            cin.clear();
            cout<<"Inserisci un numero! ";
            cin.ignore(10000, '\n');
            cin>>x;
        }
        return x;
    }
    
    int verifica_nome(string &nome_verifica){
        for(int i = 0; i < prodotti_length; i++){
            if(nome[i] == nome_verifica) return i+1;
            else if(nome[i] == "") return i+1000;
        }
        return 0;
    }
    
    bool verifica_quantita(int &quantita_aggiunta){
        if(quantita_aggiunta <= 0) return false;
        else return true;
    }
    
    bool verifica_categoria(string &categoria_inserita){
        for(int i = 0; i < numero_categorie; i++){
            if(categorie_legenda[i] == categoria_inserita) return true;
        }
        return false;
    }
    
    int verifica_codice(int &codice_inserito){
        for(int i = 0; i < prodotti_length && codice[i] != -1; i++){
            if(codice[i] == codice_inserito) return i+1;
        }
        return 0;
    }
    
    bool verifica_categoria(string *categoria_ordinata, string categoria_inserita){
        for(int i = 0; i < prodotti_length && categoria_ordinata[i] != ""; i++){
            if(categoria_ordinata[i] == categoria_inserita) return true;
        }
        return false;
    }
    
    void cancella_elemento(int &indice){
        for(int i = indice; i < prodotti_length && codice[i] != -1; i++){
            codice[i] = codice[i+1];
            nome[i] = nome[i+1];
            prezzo[i] = prezzo[i+1];
            quantita[i] = quantita[i+1];
            categoria[i] = categoria[i+1];
            if(codice[i] != -1) codice[i] -= 1;
        }
    }
    
    void read(){
        ifstream file;
    	file.open("Prodotti.txt");
    	string temp_quantita, temp_prezzo;
        for(int i = 0; !file.eof() && i < prodotti_length; i++){    //Nel file deve essere presente almeno un prodotto
            codice[i] = i+1;
            getline(file, nome[i], ';');
            getline(file, categoria[i], ';');
            getline(file, temp_quantita, ';');
            quantita[i] = stoi(temp_quantita);
            getline(file, temp_prezzo, '\n');
            prezzo[i] = stod(temp_prezzo);
        }
    	file.close();
    }
    
    void write(){   //Chiudere il programma per poter vedere i prodotti aggiunti nel file
    	ofstream file;
    	file.open("Prodotti.txt");
    	for(int i = 0; i < prodotti_length && codice[i] != -1; i++){
    	    file<<nome[i]<<";"<<categoria[i]<<";"<<quantita[i]<<";"<<prezzo[i]<<endl;
    	}
    	file.close();
    }
    
    void ritorno_home(string &verifica){
        if(verifica == "0"){
            cout<<"\nRitorno alla home...\n";
            sleep(2);
            clear();
            homepage();
        }
    }
    
    void ritorno_home_int(int &verifica){
        if(verifica == 0){
            cout<<"\nRitorno alla home...\n";
            sleep(2);
            clear();
            homepage();
        }
    }
    
    void homepage(){
        int scelta_home = 0;
        
        while(scelta_home < 1 || scelta_home > 6){
        cout<<"\033[1;96m"<<"=========================================================\n"
                  "|                 RAPISARDI CORPORATION                 |\n"
                  "=========================================================\n\n"<<colore_reset<<
                  "Benvenuto, scegli un'opzione:\n"
                  "1) Inserisci prodotto;\n"
                  "2) Cerca un prodotto;\n"
                  "3) Cancella un prodotto;\n"
                  "4) Visualizza la somma totale dei prodotti;\n"
                  "5) Somma dei prodotti di una categoria;\n"
                  "6) Esci.\n\n"
                  "Scelta (indica il numero): "<<"\033[92m";
            cin>>scelta_home;
            scelta_home = verifica_int(scelta_home);
            cout<<colore_reset;
            if(scelta_home < 1 || scelta_home > 6){
                cout<<"\nScelta non valida, riprova!\n";
                sleep(2);
                clear();
            } else{
                clear();
                smistamento(scelta_home);
            }
        }
    }
    
    void smistamento(int n){
        switch(n){
            case 1:
            inserimento();
            break;
            case 2:
            ricerca();
            break;
            case 3:
            cancellazione();
            break;
            case 4:
            somma_totale();
            break;
            case 5:
            somma_tipologia();
            break;
            case 6:
            cout<<"Arrivederci!\n";
            sleep(1);
            clear();
            exit(0);
            break;
        }
    }
    
    void inserimento(){
        string nome_inserisci, categoria_inserisci;
        int verifica, quantita_inserisci;
        double prezzo_inserisci;
        
        do{
            cout<<"\033[1;96m"<<"==================================================================\n"
                      "|                       INSERISCI PRODOTTO                       |\n"
                      "==================================================================\n\n"<<colore_reset<<
                      "Prodotto ('0' per la home): ";
            getline(cin, nome_inserisci, '\n');
            if(nome_inserisci != ""){
                verifica = verifica_nome(nome_inserisci);
                ritorno_home(nome_inserisci);
                
                if(!verifica){
                    cout<<"\nL'array dei prodotti è pieno, riprova con un prodotto esistente...\n";
                    sleep(2);
                    clear();
                } else if(verifica < 1000){
                    cout<<"Inserisci la quantità da aggiungere ('0' per la home): ";
                    cin>>quantita_inserisci;
                    quantita_inserisci = verifica_int(quantita_inserisci);
                    ritorno_home_int(quantita_inserisci);
                    if(!verifica_quantita(quantita_inserisci)){
                        cout<<"\nQuantità non valida riprova!\n";
                        sleep(2);
                        clear();
                        verifica = 0;
                    } else{
                        quantita[verifica-1] += quantita_inserisci;
                        cout<<"\nQuantità aggiunta al prodotto: "<<codice[verifica-1]<<", ritorno alla home...\n";
                        write();
                        sleep(2);
                        clear();
                        homepage();
                    }
                } else if(verifica >= 1000){
                    verifica -= 1000;
                    cout<<"Categoria prodotto ('0' per la home): ";
                    getline(cin, categoria_inserisci, '\n');
                    ritorno_home(categoria_inserisci);
                    if(!verifica_categoria(categoria_inserisci)){
                        cout<<"\nCategoria non registrata nel sistema, riprova!\n";
                        sleep(2);
                        clear();
                        verifica = 0;
                    } else{
                        cout<<"Inserisci il prezzo ('0' per la home): ";
                        cin>>prezzo_inserisci;
                        prezzo_inserisci = verifica_double(prezzo_inserisci);
                        if(prezzo_inserisci <= 0){
                            cout<<"\nPrezzo non valido, riprova!\n";
                            sleep(2);
                            clear();
                            verifica = 0;
                        } else{
                            cout<<"Inserisci la quantità da aggiungere ('0' per la home): ";
                            cin>>quantita_inserisci;
                            quantita_inserisci = verifica_int(quantita_inserisci);
                            ritorno_home_int(quantita_inserisci);
                            if(!verifica_quantita(quantita_inserisci)){
                                cout<<"\nQuantità non valida riprova!\n";
                                sleep(2);
                                clear();
                                verifica = 0;
                            } else{
                                codice[verifica] = verifica+1;
                                nome[verifica] = nome_inserisci;
                                quantita[verifica] += quantita_inserisci;
                                categoria[verifica] = categoria_inserisci;
                                prezzo[verifica] = prezzo_inserisci;
                                cout<<"\nCodice prodotto aggiunto: "<<codice[verifica]<<", ritorno alla home...\n";
                                write();
                                sleep(2);
                                clear();
                                homepage();
                            }
                        }
                    }
                }
            } else clear();
        } while(!verifica || verifica == -1);
    }
    
    void ricerca(){
        int codice_ricerca, indice_codice;
        
        do{
            cout<<"\033[1;96m"<<"=========================================================\n"
                      "|                   CERCA UN PRODOTTO                   |\n"
                      "=========================================================\n\n"<<colore_reset<<
                      "Inserisci codice prodotto ('0' per la home): ";
            cin>>codice_ricerca;
            codice_ricerca = verifica_int(codice_ricerca);
            ritorno_home_int(codice_ricerca);
            indice_codice = verifica_codice(codice_ricerca);
            
            if(!indice_codice){
                cout<<"\nCodice inesistente, riprova!\n";
                sleep(2);
                clear();
            } else{
                cout<<"Nome prodotto: "<<nome[indice_codice-1]<<";\n"
                      "Categoria prodotto: "<<categoria[indice_codice-1]<<";\n"
                      "Prezzo prodotto: "<<prezzo[indice_codice-1]<<"€;\n"
                      "Quantità disponibile: "<<quantita[indice_codice-1]<<";\n";
                      uscita();
            }
        } while(!indice_codice);
    }
    
    void cancellazione(){
        int codice_cancella, indice_codice;
        
        do{
            cout<<"\033[1;96m"<<"==========================================================\n"
                      "|                  CANCELLA UN PRODOTTO                  |\n"
                      "==========================================================\n\n"<<colore_reset<<
                      "Inserisci codice prodotto ('0' per la home): ";
            cin>>codice_cancella;
            codice_cancella = verifica_int(codice_cancella);
            ritorno_home_int(codice_cancella);
            indice_codice = verifica_codice(codice_cancella);
            
            if(!indice_codice){
                cout<<"\nCodice inesistente, riprova!\n";
                sleep(2);
                clear();
            } else{
                indice_codice -= 1;
                cancella_elemento(indice_codice);
                cout<<"\nProdotto cancellato con successo, ritorno alla home...\n";
                sleep(2);
                clear();
                homepage();
            }
        } while(!indice_codice);
    }
    
    void somma_totale(){
        int somma_valore = 0;
        
        cout<<"\033[1;96m"<<"===============================================================\n"
                      "|                  SOMMA VALORE DEI PRODOTTI                  |\n"
                      "===============================================================\n\n"<<colore_reset;
        for(int i = 0; i < prodotti_length && codice[i] != -1; i++){
            somma_valore += prezzo[i]*quantita[i];
        }
        cout<<"La somma dei prezzi dei prodotti è: "<<somma_valore<<"€"<<endl;
        uscita();
    }
    
    void somma_tipologia(){
        bool verifica_cat;
        int somma_tipologia = 0, numero_elenco = 1;
        int categoria_scelta;
        string categorie_somma[numero_categorie];
        copy(begin(categoria), end(categoria), categoria_ordinata);
        sort(categoria_ordinata, categoria_ordinata + prodotti_length, greater<string>());
        if(codice[0] != -1){
            do{
                cout<<"\033[1;96m"<<"==========================================================================\n"
                      "|                         SOMMA VALORE TIPOLOGIA                         |\n"
                      "==========================================================================\n\n"<<colore_reset;
                cout<<numero_elenco<<") "<<categoria_ordinata[0]<<endl;
                categorie_somma[numero_elenco-1] = categoria_ordinata[0];
                numero_elenco++;
                for(int i = 1; i < prodotti_length && codice[i] != -1; i++){
                    if(categoria_ordinata[i] != categoria_ordinata[i-1]){
                        cout<<numero_elenco<<") "<<categoria_ordinata[i]<<endl;
                        categorie_somma[numero_elenco-1] = categoria_ordinata[i];
                        numero_elenco++;
                    }
                }
                cout<<"\nCategoria scelta ('0' per la home): ";
                cin>>categoria_scelta;
                categoria_scelta = verifica_int(categoria_scelta);
                ritorno_home_int(categoria_scelta);
                if(categoria_scelta <= 0 || categoria_scelta >= numero_elenco){
                    cout<<"\nNumero non valido, riprova!\n";
                    sleep(2);
                    clear();
                } else{
                    for(int i = 0; i < numero_categorie && categoria[i] != ""; i++){
                        if(categorie_somma[categoria_scelta-1] == categoria[i]){
                            somma_tipologia += quantita[i]*prezzo[i];
                        }
                    }
                    cout<<"Il prezzo totale dei prodotti con la categoria "<<categorie_somma[categoria_scelta-1]<<" è: "<<somma_tipologia<<"€"<<endl;
                    uscita();
                }
            } while(categoria_scelta <= 0 || categoria_scelta >= numero_elenco);
        } else{
            cout<<"\nNessun prodotto presente, inserisci prodotti!\n";
            sleep(2);
            clear();
            inserimento();
        }
    }
    
    void uscita(){
        string scelta_uscita;
        do{
            cout<<"\nTornare alla home? \033[91m";
            cin>>scelta_uscita;
            cout<<colore_reset;
            if(scelta_uscita == "si"){
                cout<<"\nTorno alla home...\n";
                sleep(2);
                clear();
                homepage();
            }
            else if(scelta_uscita == "no"){
                cout<<"\nUscita in corso...\n";
                sleep(2);
                clear();
                exit(0);
            }
            else{
                cout<<"\nScelta non valida, riprova!";
            }
        } while(scelta_uscita != "no" && scelta_uscita != "si");
    }
};

int main()
{
    for(int i = 0; i < 1000; i++){
        categoria[i] = "";
        codice[i] = -1;
        quantita[i] = 0;
        prezzo[i] = 0;
        nome[i] = "";
    }
    
    warehouse rapisardi_corporation;
    rapisardi_corporation.read();
    rapisardi_corporation.homepage();
    
    return 0;
}
#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

void clear(){
    #ifdef _WIND32
    system("cls");
    #else
    system("clear");
    #endif
}

float calcolo_lordo(float ore, float paga_oraria) {
	return ore * paga_oraria;
}

float calcolo_ritenute(float stipendio_lordo) {
	return stipendio_lordo * 23.81 / 100;
}

float calcolo_imponibile(float stipendio_lordo, float ritenute) {
	return stipendio_lordo - ritenute;
}

float calcolo_IRPEF(float imponibile) {
	if (imponibile <= 1154) {
		return imponibile * 23 / 100;
	}
	else if (imponibile > 1154 && imponibile <= 2154) {
		return imponibile * 25 / 100;
	}
	else {
		return imponibile * 35 / 100;
	}
}

float calcolo_detrazioni_dipendente(float imponibile) {
	if (imponibile <= 1154) {
		return 144;
	}
	else if (imponibile > 1154 && imponibile <= 2154) {
		return 146 + 92 * (2154 - imponibile) / 1000;
	}
	else {
		return 0;
	}
}

float calcolo_detrazioni_familiari(unsigned short int *figli, int numero_figli) {
	int tot = 0;
	for (int i = 0; i < numero_figli; i++) {
		switch (i) {
		case 0:
			tot += 220;
			break;
		case 1:
			tot += 350;
			break;
		case 2:
			tot += 620;
		}
	}
	return tot;
}

float calcolo_detrazione_coniuge(float imponibile) {
	if (imponibile <= 1154) {
		return 67;
	}
	else if (imponibile > 1154 && imponibile <= 3333) {
		return 58;
	}
	else {
		return 0;
	}
}

float somma_detrazioni(float detrazioni_dipendente, float detrazioni_familiari, float detrazioni_coniuge){
    return detrazioni_dipendente + detrazioni_familiari + detrazioni_coniuge;
}

float calcolo_imposta_netta(float IRPEF, float totale_detrazioni) {
    if(IRPEF < totale_detrazioni){
        IRPEF = 0;
    } else{
        IRPEF -= totale_detrazioni;
    }
    return IRPEF;
}

float calcolo_stipendio_netto(float imponibile, float imposta_netta){
    return imponibile - imposta_netta;
}

int main() {
    float paga_oraria, ore;
    cout<<"Inserisci paga oraria: ";
    cin>>paga_oraria;
    cout<<"Inserisci ore: ";
    cin>>ore;
    
    float stipendio_lordo = calcolo_lordo(ore, paga_oraria);
    float ritenute_previdenziali = calcolo_ritenute(stipendio_lordo);
    float imponibile = calcolo_imponibile(stipendio_lordo, ritenute_previdenziali);
    float imposta_lorda = calcolo_IRPEF(imponibile);
    float detrazioni_dipendente = calcolo_detrazioni_dipendente(imponibile);
    
    int numero_figli;
    float detrazioni_familiari;
    clear();
    cout<<"Numero figli: ";
    cin>>numero_figli;
    if(numero_figli == 0){
        detrazioni_familiari = 0;
    } else{
        unsigned short int *figli = new unsigned short int[numero_figli];
        int scelta_temp;
        for(int i = 0; i < numero_figli; i++){
            clear();
            
            cout<<"Scelte:"<<
              "\n1) Figlio minore di 3 anni"<<
              "\n2) Figlio maggiore di 3 anni"<<
              "\n3) Figlio con disabilità\n\n";
              
            cout<<"Figlio numero "<<i+1<<": ";
            cin>>scelta_temp;
            if(scelta_temp < 1 || scelta_temp > 3){
                cout<<"\nScelta non valida, riprova!\n";
                sleep(2);
                i--;
            } else{
                figli[i] = scelta_temp;
            }
        }
        detrazioni_familiari = calcolo_detrazioni_familiari(figli, numero_figli);
    }
    
    clear();
    float detrazioni_coniuge = 0;
    string scelta = "";
    while(scelta != "si" && scelta != "Si" && scelta != "no" && scelta != "No"){
        cout<<"Hai un coniuge a carico? ";
        cin>>scelta;
        if(scelta == "si" || scelta == "Si"){
            detrazioni_coniuge = calcolo_detrazione_coniuge(imponibile);
        } else if(scelta != "no" || scelta != "No"){
            cout<<"\nScelta non valida, riprova!\n";
            sleep(2);
            clear();
        }
    }
    
    float totale_detrazioni = somma_detrazioni(detrazioni_dipendente, detrazioni_familiari, detrazioni_coniuge);
    float imposta_netta = calcolo_imposta_netta(imposta_lorda, totale_detrazioni);
    float stipendio_netto = calcolo_stipendio_netto(imponibile, imposta_netta);
    
    clear();
    cout<<"L'imposta netta equivale a: "<<imposta_netta<<"€"<<endl<<
          "Lo stipendio netto equivale a: "<<stipendio_netto<<"€";
    return 0;
}

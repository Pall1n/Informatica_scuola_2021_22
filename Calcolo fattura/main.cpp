/*Consegna:
Realizzare un programma che permetta di calcolare il totale
di una fattura tenuto conto che:

1. L’operatore dovrà inserire:
	a. La quantità della merce acquistata;
	b. Il prezzo unitario;
	c. L’aliquota IVA
	d. La modalità di pagamento

2. Il programma dovrà prevedere le seguenti funzioni:
	a. Calcolo dell’imponibile (quantità * prezzo unitario)
	b. Calcolo dell’IVA (imponibile * aliquota iva / 100)
	c. Calcolo del totale lordo (imponibile + IVA)
	d. Calcolo dello sconto tenuto conto che:
		i. Se il pagamento è in contanti si avrà diritto ad uno sconto del 10%;
		ii. Se il pagamento è a 30gg l’importo totale dovrà essere aumentato degli interessi al 5% sul totale;
		iii. Se il pagamento è superiore a 30gg gli interessi saranno calcolati al 7%

3. Visualizzare:
	a. L’imponibile
	b. L’iva
	c. Il totale lordo
	d. Lo sconto
	e. Il totale netto (totale lordo - sconto + interessi)
*/

#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

void clear() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

const string colore_reset = "\033[0m";

unsigned int quantita;
unsigned short int aliquota_iva;
double prezzo_unitario, iva_costo, imponibile, sconto_interesse, totale_lordo, totale_netto;
string modalita_pagamento;
bool uscire = false;

int verifica_inserimento_quantita(unsigned int& x) {
	while (cin.fail()) {
		cin.clear();
		cout << "Inserisci una quantità valida! ";
		cin.ignore(10000, '\n');
		cin >> x;
	}
	return x;
}

double verifica_inserimento_prezzo(double& x) {
	while (cin.fail() || x <= 0) {
		cin.clear();
		cout << "Inserisci un prezzo valido! ";
		cin.ignore(10000, '\n');
		cin >> x;
	}
	return x;
}

int verifica_inserimento_aliquota(unsigned short int& x) {
	while (cin.fail() || x > 100) {
		cin.clear();
		cout << "Inserisci un'aliquota valida! ";
		cin.ignore(10000, '\n');
		cin >> x;
	}
	return x;
}

double calcolo_imponibile() {
	return quantita * prezzo_unitario;
}

double calcolo_iva() {
	return imponibile * aliquota_iva / 100;
}

double calcolo_totale_lordo() {
	return imponibile + iva_costo;
}

double calcolo_sconto() {
	if (modalita_pagamento == "contanti") {
		return -(totale_lordo * 10 / 100);
	}
	else if (modalita_pagamento == "30gg") {
		return totale_lordo * 5 / 100;
	}
	else if (modalita_pagamento == "30gg+") {
		return totale_lordo * 7 / 100;
	}
}

double calcolo_totale_netto() {
	return totale_lordo + sconto_interesse;
}

void risultati() {
	clear();
	cout << "\033[1;96m" << "===============================================\n"
		"|                   FATTURA                   |\n"
		"===============================================\n\n" << colore_reset <<
		"Imponibile: " << imponibile << endl <<
		"IVA: " << iva_costo << endl <<
		"Totale lordo: " << totale_lordo << endl;
	if (sconto_interesse > 0) {
		cout << "Interessi: " << sconto_interesse << endl;
	}
	else {
		sconto_interesse *= -1;
		cout << "Sconto: " << sconto_interesse << endl;
	}
	cout << "Totale netto: " << totale_netto << endl;
}

void uscita() {
	string scelta_uscita;
	do {
		cout << "\nTornare alla home? \033[91m";
		cin >> scelta_uscita;
		cout << colore_reset;
		if (scelta_uscita == "si") {
			cout << "\nTorno alla home...\n";
			sleep(2);
			clear();
			uscire = false;
		}
		else if (scelta_uscita == "no") {
			cout << "\nUscita in corso...\n";
			sleep(2);
			clear();
			uscire = true;
		}
		else {
			cout << "\nScelta non valida, riprova!";
		}
	} while (scelta_uscita != "no" && scelta_uscita != "si");
}

void homepage() {
	while(!uscire){
		modalita_pagamento = "";
		while (modalita_pagamento != "contanti" || modalita_pagamento != "30gg" || modalita_pagamento != "30gg+") {
			cout << "\033[1;96m" << "=====================================================\n"
				"|                  CALCOLO FATTURA                  |\n"
				"=====================================================\n\n" << colore_reset <<
				"Inserisci la quantità: ";
			cin >> quantita;
			verifica_inserimento_quantita(quantita);
			cout << "Inserisci il prezzo unitario: ";
			cin >> prezzo_unitario;
			verifica_inserimento_prezzo(prezzo_unitario);
			cout << "Inserisci l'aliquota IVA: ";
			cin >> aliquota_iva;
			verifica_inserimento_aliquota(aliquota_iva);
			cout << "Inserisci la modalità di pagamento: ";
			cin >> modalita_pagamento;

			if (modalita_pagamento != "contanti" || modalita_pagamento != "30gg" || modalita_pagamento != "30gg+") {
				cout << "\nModalità di pagamento non valida, riprova!\n";
				sleep(2);
				clear();
			}
		}
		
		imponibile = calcolo_imponibile();
		iva_costo = calcolo_iva();
		totale_lordo = calcolo_totale_lordo();
		sconto_interesse = calcolo_sconto();
		totale_netto = calcolo_totale_netto();
		
		risultati();
		uscita();
	}
}

int main()
{
	homepage();
	return 0;
}
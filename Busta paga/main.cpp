#include <iostream>
using namespace std;

float calcolo_lordo(float ore, float paga_oraria){
	return ore * paga_oraria;
}

float calcolo_ritenute(float stipendio_lordo) {
	return stipendio_lordo * 23.81 / 100;
}

float calcolo_imponibile(float stipendio_lordo, float ritenute) {
	return stipendio_lordo - ritenute;
}

float calcolo_imposta_lorda(float imponibile) {
	if (imponibile <= 1154) {
		return imponibile * 23 / 100;
	} else if (imponibile > 1154 && imponibile <= 2154) {
		return imponibile * 25 / 100;
	} else {
		return imponibile * 35 / 100;
	}
}

float calcolo_detrazioni_dipendente(float imponibile, float reddito) {
	if (imponibile <= 1154) {
		return 144;
	} else if (imponibile > 1154 && imponibile <= 2154) {
		return 146 + 92 * (2154 - reddito) / 1000;
	} else {
		return 0;
	}
}

float calcolo_detrazioni_familiari(int *figli) {
	int tot = 0;
	for (int i = 0; i < sizeof(figli) / sizeof(figli[0]); i++) {
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
}

float calcolo_detrazione_coniuge(float imponibile) {
	if (imponibile <= 1154) {
		return 67;
	} else if (imponibile > 1154 && imponibile <= 3333) {
		return 58;
	} else {
		return 0;
	}
}

float calcolo_imposta_netta() {
	
}

int main(){
	
	
	return 0;
}
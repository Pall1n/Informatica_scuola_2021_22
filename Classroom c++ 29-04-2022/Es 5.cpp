/*Consegna
Implementare una funzione che dato in ingresso una stringa (array di char) restituisca la stringa inversa
*/

#include <iostream>
using namespace std;

string inverti_stringa(string stringa, unsigned int length) {
	string stringa_invertita = stringa;

	for (int i = 0; i < length; i++) {
		stringa_invertita[i] = stringa[(length - 1) - i];
	}
	return stringa_invertita;
}

int main() {
	string stringa;
	cout << "Scrivi qualcosa: ";
	cin >> stringa;
	unsigned int length = stringa.length();
	
	cout << "\nLa stringa invertita è: " << inverti_stringa(stringa, length);
}

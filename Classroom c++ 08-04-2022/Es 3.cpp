/*Consegna:
Calcola la media dei voti presi da un numero N di studenti 
in un compito in classe, con N inserito da tastiera
*/

#include <iostream>
using namespace std;

double calc_media(unsigned int n){
    double temp, media = 0;
    
    for(int i = 0; i < n; i++){
        cout<<i+1<<") Inserisci voto: ";
        cin>>temp;
        media += temp;
    }
    media /= n;
    return media;
}

int main(){
    unsigned int n;
    
    cout<<"Inserisci il numero di alunni: ";
    cin>>n;
    double media = calc_media(n);
    
    cout<<"\nLa media della classe equivale a: "<<media;

    return 0;
}

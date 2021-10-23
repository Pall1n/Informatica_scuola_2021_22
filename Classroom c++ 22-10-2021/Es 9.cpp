//Consegna: Calcola la media dei voti presi da un numero N di studenti in un compito in classe, con N inserito da tastiera

#include <iostream>

using namespace std;

void calcolo_media(int num_studenti){
    double voto;
    double somma = 0;
    for(int i = 0; i < num_studenti; i++){
        cout<<"("<<i+1<<" su "<<num_studenti<<") Inserisci voto: ";
        cin>>voto;
        somma += voto;
    }
    double media = somma/num_studenti;
    cout<<"\nLa media dei voti equivale a: "<<media;
}

int main()
{
    int num_studenti;
    while(true){
        cout<<"Inserisci il numero degli studenti: ";
        cin>>num_studenti;
        if(num_studenti <= 0) cout<<"Numero studenti non valido, riprova.\n\n";
        else{
            calcolo_media(num_studenti);
            break;
        }
    }
    return 0;
}
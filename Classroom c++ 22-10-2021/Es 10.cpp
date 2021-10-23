//Consegna: Restituisce il maggiore e il minore di una serie di numeri inseriti da tastiera

#include <iostream>
#include <limits> //importo limits per creare la variabile min con la quale il programma confronterà il primo numero inserito

using namespace std;

void calcolo(int num_numeri){
    double numero, max;
    double min = numeric_limits<double>::max(); //questo è il valore massimo di una variabile double, in questo modo riesco a sostituire questo valore con il primo numero inserito, dato che è sicuramente minore
    for(int i = 0; i < num_numeri; i++){
        cout<<"("<<i+1<<" su "<<num_numeri<<") Inserisci un numero: ";
        cin>>numero;
        if((numero > max || numero < min) && i == 0) max = numero; //ho inserito "or numero < min" in modo tale da inserire sempre il primo numero scritto dall'utente nella variabile max per poterlo poi confrontare poi con tutti gli altri
        else if(numero > max) max = numero;
        if(numero < min) min = numero;
        else continue;
    }
    if(max == min) cout<<"\nTutti i numeri inseriti sono uguali, quindi non esiste un valore massimo o uno minimo.\n";
    else cout<<"\nIl numero maggiore è il "<<max<<", mentre il minore è il "<<min;
}

int main()
{
    while(true){
        int num_numeri;
        cout<<"Quanti numeri devi inserire? ";
        cin>>num_numeri;
        if(num_numeri <= 0) cout<<"\nValore non valido, riprova.\n";
        else{
            calcolo(num_numeri);
            break;
        }
    }
    return 0;
}
//Consegna: Implementare una funzione che inserita una data, converte il mese da numero a parola

#include <iostream>
using namespace std;

string conversione(unsigned short int data){
    switch(data){
        case 1:
        return "Gennaio";
        break;
        case 2:
        return "Febbraio";
        break;
        case 3:
        return "Marzo";
        break;
        case 4:
        return "Aprile";
        break;
        case 5:
        return "Maggio";
        break;
        case 6:
        return "Giugno";
        break;
        case 7:
        return "Luglio";
        break;
        case 8:
        return "Agosto";
        break;
        case 9:
        return "Settembre";
        break;
        case 10:
        return "Ottobre";
        break;
        case 11:
        return "Novembre";
        break;
        case 12:
        return "Dicembre";
        break;
        default:
        return "Error";
    }
}

int main(){
    unsigned short int data;
    cout<<"Inserisci numero mese: ";
    cin>>data;
    
    string mese = conversione(data);
    if(mese != "Error"){
        cout<<"Il numero inserito equivale al mese: "<<mese;
    } else{
        cout<<"Il numero inserito non rientra nel range di mesi dell'anno";
    }

    return 0;
}
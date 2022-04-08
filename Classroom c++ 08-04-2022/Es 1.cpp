/*Consegna:
Inserendo il proprio giorno e mese di nascita, comunica 
il segno zodiacale corrispondente alla data inserita
*/

#include <iostream>

using namespace std;

string verifica_segno(int giorno, int mese){
    switch(mese){
        case 1:
        if(giorno <= 20) return "Capricorno";
        else return "Acquario";
        break;
        case 2:
        if(giorno <= 19) return "Acquario";
        else return "Pesci";
        break;
        case 3:
        if(giorno <= 20) return "Pesci";
        else return "Ariete";
        break;
        case 4:
        if(giorno <= 20) return "Ariete";
        else return "Toro";
        break;
        case 5:
        if(giorno <= 20) return "Toro";
        else return "Gemelli";
        break;
        case 6:
        if(giorno <= 21) return "Gemelli";
        else return "Cancro";
        break;
        case 7:
        if(giorno <= 22) return "Cancro";
        else return "Leone";
        break;
        case 8:
        if(giorno <= 23) return "Leone";
        else return "Vergine";
        break;
        case 9:
        if(giorno <= 22) return "Vergine";
        else return "Bilancia";
        break;
        case 10:
        if(giorno <= 22) return "Bilancia";
        else return "Scorpione";
        break;
        case 11:
        if(giorno <= 22) return "Scorpione";
        else return "Sagittario";
        break;
        case 12:
        if(giorno <= 21) return "Sagittario";
        else return "Capricorno";
        break;
        default:
        return "";
    }
}

int main()
{
    int giorno, mese;
    
    cout<<"Inserisci il giorno della tua data di nascita: ";
    cin>>giorno;
    cout<<"Inserisci il mese della tua data di nascita: ";
    cin>>mese;
    
    string segno_zodiacale = verifica_segno(giorno, mese);
    
    if(segno_zodiacale != "") cout<<"\nIl tuo segno zodiacale è: "<<segno_zodiacale;
    else cout<<"\nHai inserito un giorno e/o un mese sbagliato";

    return 0;
}
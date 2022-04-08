/*Consegna:
Creare una funzione che riceve una quantità di tempo in formato ore, 
minuti e secondi e la restituisce espressa solamente in secondi.
*/

#include <iostream>

using namespace std;

int transform(int hour, int min, int sec){
    return (hour*3600)+(min*60)+sec;
}

int main()
{
    int hour, min, sec;
    cout<<"Inserisci ore: ";
    cin>>hour;
    cout<<"Inserisci minuti: ";
    cin>>min;
    cout<<"Inserisci secondi: ";
    cin>>sec;
    
    cout<<"Il totale di secondi è: "<<transform(hour, min, sec);

    return 0;
}
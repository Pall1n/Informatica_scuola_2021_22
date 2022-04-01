/*Consegna:
Creare poi un programma che si faccia passare due quantità di tempo e 
verifichi quale è maggiore
*/

#include <iostream>

using namespace std;

string compara(int hour1, int min1, int sec1, int hour2, int min2, int sec2){
    if ((hour1*3600)+(min1*60)+sec1 > (hour2*3600)+(min2*60)+sec2){
        return "la prima";
    } else if(((hour1*3600)+(min1*60)+sec1 < (hour2*3600)+(min2*60)+sec2)){
        return "la seconda";
    } else return "sono uguali";
}

int main()
{
    int hour1, min1, sec1, hour2, min2, sec2;
    cout<<"Inserisci ore primo tempo: ";
    cin>>hour1;
    cout<<"Inserisci minuti primo tempo: ";
    cin>>min1;
    cout<<"Inserisci secondi primo tempo: ";
    cin>>sec1;
    cout<<"Inserisci ore secondo tempo: ";
    cin>>hour2;
    cout<<"Inserisci minuti secondo tempo: ";
    cin>>min2;
    cout<<"Inserisci secondi secondo tempo: ";
    cin>>sec2;
    
    cout<<"\nLa quantità di tempo maggiore è: "<<compara(hour1, min1, sec1, hour2, min2, sec2);

    return 0;
}
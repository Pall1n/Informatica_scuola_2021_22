//Consegna: Selezionando un giorno della settimana, comunica l'orario scolastico delle lezioni di quel giorno

#include <iostream>

using namespace std;

int main()
{
    string giorni[] = {"lunedì", "martedì", "mercoledì", "giovedì", "venerdì"};
    string orario[] = {
        "\nInformatica (2);\nItaliano;\nMatematica;\nTecnologie e progettazione;\nMotoria.",
        "\nItaliano (2);\nTelecomunicazioni (2);\nSistemi e Reti (2);\nInglese.",
        "\nMatematica;\nTecnologie e progettazione;\nInglese;\nItaliano;\nInformatica;\nSistemi e Reti;\nTelecomunicazioni.",
        "\nItaliano;\nMatematica (2);\nMotoria;\nInformatica;\nTecnologie e progettazione;\nReligione.",
        "\nSistemi e Reti;\nInformatica (2);\nInglese;\nItaliano."
    };
    int lung_max = sizeof(giorni)/sizeof(giorni[0]);
    
    while(true){
        string scelta;
        cout<<"Scegli un giorno scolastico per ricevere l'orario scolastico: ";
        cin>>scelta;
        for(int i = 0; i <= lung_max; i++){
            if(giorni[i] == scelta){
                cout<<orario[i];
                return 0;
            }
            else continue;
        }
        cout<<"Giorno non valido, riprova scrivendo un giorno scolastico tutto minuscolo.\n\n";
    }
}
/*
Consegna: Memorizzare in un array di numeri casuali compresi tra zero e nove, 
stamparne il contenuto e dire quanti zeri sono memorizzati all’interno dell’array .
*/

#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int numeri_casuali[10000];
    int zeri = 0;
    
    srand(time(NULL));
    
    for(int i = 0; i < 10000; i++){
        numeri_casuali[i] = rand() % 10;
        cout<<numeri_casuali[i]<<endl;
        if(numeri_casuali[i] == 0) zeri += 1;
    }
    
    cout<<"\nIl numeri di zeri contenuti nell'array numeri_casuali è di: "<<zeri;
    
    return 0;
}
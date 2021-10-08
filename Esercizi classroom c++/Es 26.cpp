#include <iostream>

using namespace std;

int main()
{
    int trattenuto = 18;
    int lordo;
    int netto;
    cout<<"Quante enciclopedie ha venduto? ";
    cin>>lordo;
    lordo = 1000000+(lordo*200000);
    netto = lordo-(lordo/100)*trattenuto;
    cout<<"Questo mese ha quadagnato nettamente: "<<netto<<" lire";
    return 0;
}
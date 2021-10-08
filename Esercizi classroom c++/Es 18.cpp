#include <iostream>

using namespace std;

int main()
{
    double dol_eur = 1.514;
    double stel_eur = 2.52;
    double dollari = 1.75;
    double sterline = 2.80;
    double euro = (dol_eur*dollari)+(stel_eur*sterline);
    cout<<"Il signore possiede in euro: "<<euro;
    return 0;
}
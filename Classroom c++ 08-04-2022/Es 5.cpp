/*Consegna:
Definite 3 variabili sulla funzione main, ordinarle in ordine crescente tramite una funzione esterna
*/

#include <iostream>
using namespace std;

void order(int&, int&, int&);
void swap(int&, int&);

int main(){
   int a, b, c;
   
   cout<<"Inserisci il primo numero: ";
   cin>>a;
   cout<<"Inserisci il secondo numero: ";
   cin>>b;
   cout<<"Inserisci il terzo numero: ";
   cin>>c;
   order(a, b, c);
   cout<<endl<<a<<" "<<b<<" "<< c;
}

void swap(int& n1, int& n2){
    int tmp;
    tmp = n1;
    n1=n2;
    n2=tmp;
}

void order(int& a, int& b, int& c){
   if (a > b){
       swap(a, b);
   }

   if (a > c){
       swap(a, c);
   }

   if (b > c){
       swap(b, c);
   }
}

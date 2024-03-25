/*
Andrei Bojan, 3CIN, 25.03.2024
Funzioni Ricorsive.
*/



#include<iostream>

using namespace std;

int sommaNum (int somma, int n, int m)
{
  if(n <= m)
  {
    somma += n;
    n++;

    return sommaNum(somma, n, m);
  }

  else return somma;

}

int main()
{
   int n, m, somma = 0;

   cout << "Inserisci il primo numero intero!\nn1:";
   cin >> n;

   cout << "Inserisci il secondo numero intero!\nn2:";
   cin >> m;

   somma = sommaNum(somma, n, m);

   cout << "La somma dei numeri compresi tra " << n << " e " << m << " e':\n" << somma;

   return 0;
}
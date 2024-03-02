/*
** prova_struct.cpp
** Andrei Bojan
** 26/02/2024
*/

#include <iostream>

using namespace std;

/* Il tipo di dato "struct" serve per memorizzare dati di tipi uguali o diversi
** nella stessa struttura, per poter accedere a ciascuno dei membri 
** attraverso il nome unico della struttura.
*/

struct persona
{
  string nome;
   int eta;
};

typedef struct
{
  int uno;
  int due;
}
COPPIA;
typedef int numeroanni;

int main()
{
  struct persona mario, balotelli;

  COPPIA coppiaEta;
  coppiaEta.uno = 33;
  coppiaEta.due = 69;

  mario.nome = "SuperMario";
  mario.eta = coppiaEta.uno;

  balotelli.nome = "Nutelloso";
  balotelli.eta = coppiaEta.due;

  cout << " Mario si chiama " << mario.nome << " ed ha " << mario.eta << " anni\n ";
  cout << "Balotelli si chiama " << balotelli.nome << " ed ha " << balotelli.eta << " anni ";
  return 0;
}

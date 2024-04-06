/*
Andrei Bojan, 3^CIN, 06.04.2024
mainPoste della Classe Coda di Interi
*/

#include <iostream>
#include "coda.cpp"
using namespace std;

int main()
{
    Coda c = Coda(1000);

    c.stampa();
    c.enter(100);
    c.enter(120);
    c.enter(85);
    c.exit();
    c.enter(235);
    c.stampa();
}

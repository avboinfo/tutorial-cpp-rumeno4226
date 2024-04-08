/*
Andrei Bojan, 3^CIN, 06.04.2024
mainPoste della Classe Coda di Interi
*/

#include <iostream>
#include "Coda.cpp"
#include "UfficioPostale.cpp"
using namespace std;

int main()
{
    UfficioPostale up = UfficioPostale("Saliceto");

    up.nuovoCliente('R');
    up.nuovoCliente('S');
    up.nuovoCliente('R');
    up.nuovoCliente('F');
    up.nuovoCliente('F');
    up.chiamaCliente('S');
    up.nuovoCliente('R');
    up.chiamaCliente('R');
    up.chiamaCLiente('R');
    up.chiamacliente('F');

}

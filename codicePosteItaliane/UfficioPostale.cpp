/*
Andrei Bojan, 3^CIN, 06.04.2024
Classe Ufficio Postale di Interi
*/

#include <iostream>
#include "Coda.cpp"
using namespace std;

class UfficioPostale
{
private:

    string nome;

    Coda codaS, codaF, codaR;

public:

    char risposta;

    int clienteS, clienteR, clienteF;

    UfficioPostale(string nome)
    {
        this->nome = nome;
        codaS = Coda(1000);
        codaF = Coda(1000);
        codaR = Coda(1000);
    }

    cout <<"Questi sono i servizi che noi offriamo: " << endl;
    cout <<"\nServizio di Spedizione (premi S se ti interessa questo servizio)!" << endl;
    cout <<"\nServizio di Ricezione (premi R se ti interessa questo servizio)!" << endl;
    cout <<"\nServizio Finanziario (premi F se ti interessa questo servizio)!" << endl;
    cin >> risposta;

    if (risposta == S)
    {
       
    }


}
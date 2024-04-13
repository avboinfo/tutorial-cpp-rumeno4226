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

    int nR, nS, nF;

public:

    UfficioPostale(string nome)
    {
        this->nome = nome;
        codaS = Coda("Spedizione", 1000);
        codaF = Coda("Finanziari", 1000);
        codaR = Coda("Ricezione",1000);
        nR = nS = nF = 100;
    }

    void nuovoCliente (char servizio)
    {
        switch (servizio)
        {
            case nR :
                codaR.enter(nR++);
                break;

            case nS :
                codaS.enter(nS++);
                break;

            case nF :
                codaF.enter(nF++);
                break;

            default:
                cout << "Questo servizio te lo fai da solo :p!!" << endl;
        }
    }

    int chiamaCliente(char servizio)
    {
        switch (servizio)
        {
            case nR :
                return codaR.exit(nR++);

            case nS :
                return codaS.exit(nS++);

            case nF :
                return codaF.exit(nF++);

            default:
                cout << "Questo servizio non e' previsto :/!" << endl;
        }
    } 

    void stampaTabellone()
    {
        cout << "Tabellone dell'ufficio postale "<< nome << endl;
        
        codaR.stampa();
        codaS.stampa();
        codaF.stampa();

    }
};
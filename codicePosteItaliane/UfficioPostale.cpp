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
            case R :
                codaR.enter(nR++);
                break;

            case S :
                codaS.enter(cS++);
                break;

            case F :
                codaF.enter(cF++);
                break;

            default:
                cout << "Questo servizio te lo fai da solo :p!!" << endl;
        }
    }

    void chiamaCliente(char servizio)
    {
        switch (servvizio)
        {
            case R :
                return codaR.exit(nR++);

            case S :
                return codaS.exit(cS++);

            case F :
                return codaF.exit(cF++);

            default:
                cout << "Questo servizio non e' previsto :/!" << endl;
    }

    void stampaTabellone()
    {
        cout << "Tabellone dell'ufficio postale "<< nome << endl;
        
        codaR.stampa();
        codaS.stampa();
        codaF.stampa();

    }
};
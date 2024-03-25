#include "mastermind.cpp"

using namespace std;


int main()
{
    mastermind prova = mastermind();

    cout << "Benvenuto nel gioco MASTERMIND!" << endl;

    prova.nuovaGiocata();
    prova.risultatoMossa();

    return 0;
}

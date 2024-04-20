/*
** Bicicletta.cpp
*/

#include <iostream>
using namespace std;

class Bicicletta {
  public:
    int raggio;
    string colore;
     
    Bicicletta()
    {
        raggio = 10;
        colore = " Bianco ";
    }

    Bicicletta( int r, string c ) 
    {
        raggio=r;
        colore=c;
    }
    void presentati() 
    {
        cout << "Buongiorno, sono una bici di colore " << colore << " e con le ruote " << raggio << "!" << endl;
    }
};

int main()
{
    Bicicletta x(16,"verdino");
    Bicicletta y(14,"rossastro");
    Bicicletta w;

    x.presentati();
    y.presentati();
    w.presentati();

    return 0;
}

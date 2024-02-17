/*
Se in griglia c'è ZERO cella vuota
Se in griglia c'è UNO stiamo parlando di una X (giocatore 1)
Se in griglia c'è DUE stiamo parlando in un CERCHIO (giocatore 2)
*/

#include <iostream>
using namespace std;

class Tris
{
public:
    int griglia[3][3]; //Attributi

void resetTabella()
{

    for (int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            griglia[i][j]=0;
        }
    }
}

    void stampaGriglia()
    {
       for (int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cout << griglia[i][j] << "\t";
            }
            cout << endl;
        }
    }

    bool giocatoreUno(int x, int y)
    {
        if( x>2 || x<0)
            return false;

        if( y>2 || y<0)
            return false;

        if (griglia [x][y] == 1 || griglia[x][y] == 2)
            return false;  

        griglia[x][y] = 1;
            return true;     
    }
    bool giocatoreDue(int x, int y){

         if( x>2 || x<0)
            return false;

        if( y>2 || y<0)
            return false;

        if (griglia [x][y] == 1 || griglia[x][y] == 2)
            return false;  

        griglia[x][y] = 2;
            return true;  
    }
};

int main(int argc, char const *argv[])
{
    Tris myTris;

    myTris.resetTabella();

    cout << "Stato iniziale!" << endl;
    myTris.stampaGriglia();

    int x, y;
    bool mossaValida;
    
    do
    {
    cout << "Mossa del giocatore 1." << endl;
    cout << "X: ";
    cin >> x;

    cout << "Y: ";
    cin >> y;

    mossaValida = myTris.giocatoreUno(x,y);
    } while (!mossaValida);

    myTris.stampaGriglia();

    do
    {
    cout << "Mossa del giocatore 2." << endl;
    cout << "X: ";
    cin >> x;

    cout << "Y: ";
    cin >> y;

    mossaValida = myTris.giocatoreDue(x,y);
    } while (!mossaValida);

    myTris.stampaGriglia();
    
    return 0;
}
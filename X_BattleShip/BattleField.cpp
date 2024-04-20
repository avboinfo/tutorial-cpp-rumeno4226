/*
** BattleField
.cpp una classe definita da noi che spupazza le matrici come nessuno mai
** Andrei Bojan - 20/04/2024
*/

#include <iostream>
using namespace std;

const int DIM = 10;

const char SHIP = 'X';

const char MISS = '.';

const char HIT = '*';

const char VOID = '-';

//DIM, AHIP, MISS, HIT, VOID

class BattleField
{

  private:
    char m[DIM][DIM];

  public:
    BattleField
    () 
    {
        for (int i=0; i<DIM; i++)
            for (int j=0; j<DIM; j++)
                m[i][j] = 97 + rand()%26;        
    }

    BattleField
    ( char c ) 
    {
        for (int i=0; i<DIM; i++)
            for (int j=0; j<DIM; j++)
                m[i][j] = c;
    }

    char get( int x, int y ) 
    {
        return m[x][y];
    }

    void put( int x, int y, char c ) 
    {
        m[x][y] = c;
    }

    void stampa() 
    {
        cout << endl << " ------------------------------------------------------ " << endl;
        for (int i=0; i<DIM; i++) {
            for (int j=0; j<DIM; j++) {
                printf("%c ", m[i][j]);
            }
            cout << endl;
        }
        cout << endl << " ------------------------------------------------------ " << endl;
    }

    void placeHorizontalShip( int len ) 
    {
        if ( len<=0 || len>=DIM ) return;
        int x = rand() % ( DIM );
        int y = rand() % ( DIM-len );
        for ( int i=0; i<len; i++ ) m[ x ][ y+i]  = SHIP;
    }

    void placeVerticalShip( int len ) 
    {
        if ( len<=0 || len>=DIM ) return;
        int x = rand() % ( DIM-len );
        int y = rand() % ( DIM );
        for ( int i=0; i<len; i++ ) m[ x+i ][ y ] = SHIP;
    }

};

int main() 
{
    srand(time(NULL));
    BattleField
     mappa = BattleField
    ( VOID );

    BattleField
     campo = BattleField
    ( VOID );

    campo.placeHorizontalShip(3);
    campo.placeVerticalShip(4);

    campo.placeVerticalShip(2);
    campo.placeHorizontalShip(5);

    // lancia 20 bombe a caso
    for (int i=0; i<20; i++)
    {
        int x = rand() % DIM;
        int y = rand() % DIM;

        if ( campo.get( x, y ) == HIT )
            continue;

        if ( campo.get( x, y )==SHIP )
        { 
            mappa.put( x, y, HIT);

            campo.put( x, y, HIT);
        }
        else
            mappa.put ( x, y, MISS );
    }

    mappa.stampa();

    campo.stampa();

}
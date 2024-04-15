/*
Matrice.cpp una classe definita da noi che spupazza la matrice come nessuno mai.
Andrei Bojan - 13.04.2024
*/

#include <iostream>
using namespace std;

const int DIM = 10;


class Matrice
{
    private:
       int m[DIM][DIM];
        
    public:

       Matrice ()
       {
         for ( int i=0; i<DIM; i++)
                for ( int j=0; j<DIM; j++)
                    m[i][j] = 97 + rand()%26;
       }

       Matrice( char c )
       {
            for ( int i=0; i<DIM; i++)
                for ( int j=0; j<DIM; j++)
                    m[i][j] = c;
       }

       char get ( int x, int y )
       {
         return m[x][y];
       }

       void put ( int x, int y, char c)
       {
        m[ x ][ y ] = c;
       }
        
       void stampa()
       {
  
            cout << endl << "--------------------------------------------------------------------------" << endl;

            for ( int i=0; i<DIM; i++)
            {
                for ( int j=0; j<DIM; j++)
                {
                    printf("%3c", m[i][j]);
                }

                cout << endl;
            }

            cout << endl;
            cout << endl << "--------------------------------------------------------------------------" << endl;       
       } 

       void bomb ()
       {
        int x = rand()%DIM;
        int y = rand()%DIM;

        m[x][y] = '*';
       }

       void placeOrizontalShip( int len )
       {

        if ( len <= 0 || len >= DIM)
            return;

        int x = rand()%DIM;
        int y = rand()%( DIM - len );

        for ( int i=0; i<len; i++)
            m[ x ][ y + i ] = 'O';
       }

       void placeVerticalShip( int len )
       {

        if ( len <= 0 || len >= DIM)
            return;

        int x = rand()%( DIM - len );
        int y = rand()%DIM;

        for ( int i=0; i<len; i++)
            m[ x + i ][ y ] = 'O';
       }
};

int main()
{

    srand(time(NULL));

    Matrice mappa  =  Matrice( '-' );
    Matrice campo = Matrice('.');

    campo.placeOrizontalShip( 3 );
    campo.placeVerticalShip( 4 );
    campo.placeVerticalShip( 2 );
    campo.placeOrizontalShip( 5 );

    //Lancia 20 bombe a caso.

    for ( int i=0; i<len; i++)
    {
        int x = rand()%DIM;
        int y = rand()%DIM;
        if (campo.get ( x, y ) == 'O')
            mappa.put( x, y, '*');
        
    }    
    mappa.stampa();
    campo.stampa();    

}
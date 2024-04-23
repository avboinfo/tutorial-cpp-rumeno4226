/*
** BattleShip, una classe per giocare alla battaglia navale.
** Andrei Bojan - 20/04/2024
*/

#include <iostream>
#include "BattleField.cpp"

using namespace std;

class BattleShip
{   
private:

    BattleField mappa;

    BattleField campo;
    
public:

    BattleShip()
    {
        mappa = BattleField( VOID );
        campo = BattleField( VOID );

        campo.placeHorizontalShip( 3 );
        campo.placeVerticalShip( 4 );

        campo.placeVerticalShip( 2 );
        campo.placeHorizontalShip( 5 );
    } 

    void play()
    {
        while ( !gameOver() )
        {
            mappa.stampa();

            if ( !playHand() )
                break;
        }
        
        campo.stampa();
    }

    bool playHand()
    {
        cout << "Inserisci le coordinate di riga e colonna ( 1 - " << DIM << " ) in cui sganciare la BOMBOCLAT!( Inserisci 0 se vuoi terminare il gioco! )";

        int x, y;

        cin >> x;

        if ( x <= 0 || x > DIM )
            return false;
        else 
            x--;    
        
        cin >> y;

        if ( y <= 0 || y > DIM )
            return false;
        else
            y--;    

        if ( campo.get( x, y ) == SHIP )
        { 
            mappa.put( x, y, HIT );

            campo.put( x, y, HIT );
        }
        else
            mappa.put ( x, y, MISS );

        return true;    
    }

    bool gameOver()
    {
        for ( int i = 0; i < DIM; i++ )
        {
            for ( int j = 0; j < DIM; j++)
            {
                if ( campo.get( i, j ) == SHIP )
                    return false;    
            }
        }
    }   
};


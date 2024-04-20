/*
** BattleShip
una classe per giocare alla battaglia navale.
** Andrei Bojan - 20/04/2024
*/

#include <iostream>
#include "BattleField.cpp"

using namespace std;

class BattleShip
{
    BattleField mappa = BattleField ( VOID );

    BattleField campo = BattleField ( VOID );

public:
    BattleShip()
    {
        mappa = BattleField( VOID );
        campo = BattleField( VOID );

        campo.placeHorizontalShip(3);
        campo.placeVerticalShip(4);

        campo.placeVerticalShip(2);
        campo.placeHorizontalShip(5);
    } 

    void play()
    {
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
};


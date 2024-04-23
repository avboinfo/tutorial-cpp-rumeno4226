/*
**Andrei Bojan, 3CIN, 23.04.2024 
**Main delle classi BattleShip e BattleField.
*/

#include <iostream>
#include "BattleShip.cpp"
using namespace std;

int main()
{
    cout << "Gioco della battaglia navale - Buon Divertimento! :)";

    BattleShip gioco = BattleShip();

    gioco.play();

    cout << "GAME OVER!" << endl;
}
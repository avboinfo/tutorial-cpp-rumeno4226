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
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <time.h>

using namespace std;

int main()
{
    string x;

    string pwd = " Bojan ";

    cout << " Prova ad indovinare la Password :" << endl;

    cin >> x;

    if ( x == pwd )
    {
        cout << " Bravo, hai indovinato ";

        return 0;
    }

    else if ( x != pwd )
    {
        cout << " Mi dispiace, riprova. ";

        break;
    }
}
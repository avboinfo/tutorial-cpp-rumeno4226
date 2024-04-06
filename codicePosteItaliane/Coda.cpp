/*
Andrei Bojan, 3^CIN, 06.04.2024
Classe Coda di Interi
*/

#include <iostream>
using namespace std;

class Coda
{
private:

    int size, start, stop;
    int * v;

public:

    Coda(int size)
    {
        this->size = size;
        v = new int[size];
        start = stop = 0;
    }

    void enter(int val)
    {
        if (stop >= size)
        {
            cout << "Coda piena :( ";
            return;
        }
        
        v[stop] = val;
        stop++; 
    }

    int exit()
    {
        if (start >= stop)
        {
            cout << "Coda vuota :)";
            return 0;
        }

        int val = v[start];
        start = start + 1;
        return val; 
    }

    void stampa()
    {
        cout << "Elementi in coda:" << endl;
        for (int i = start; i < stop; i++)

        cout << v[i] << endl;

        cout << "-------------------" << endl;
    }
};


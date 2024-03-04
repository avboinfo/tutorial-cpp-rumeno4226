/*
Andrei Bojan, 3^CIN, 04.03.2024
Classi Vettori di Interi
*/

#include <iostream>
using namespace std;

class Vettore
{

protected:
    int dim, len, delta;
    int * v;

public:
    Vettore(int d, int delta)
    {
        this -> dim = dim;
        this -> delta = delta;

        dim = d;
        delta = 10;
        len = 0;
        v = new int[dim];
    }

    void add(int n)
    {
        if (len == dim)
        {

            cout << "Estendo da " << dim << " a " << dim+delta << " !" << endl;

            int * nuovoV = new int[dim + delta];

            for (int i = 0; i < dim; i++)
                nuovoV[i] = v[i];

            dim += delta;
            delete[] v;
            v = nuovoV;    
        }

        v[len] = n;
        len++;
    }

    void print()
    {

        cout << "Contenuto del Vettore: ";

        for (int i = 0; i < len; i++)
        {
            cout << v[i] << " ";
        }

        cout << endl;
    }
};

int main(int argc, char *argv[])
{
    Vettore vett(10, 2);

    for (int i = 0; i < 100; i++)
        vett.add(i);

            vett.print();
}
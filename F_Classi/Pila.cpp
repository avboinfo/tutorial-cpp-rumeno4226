/*
Andrei Bojan, 3^CIN, 11.03.2024
Classe Pila di Interi
*/

#include <iostream>
using namespace std;

class Pila
{

protected:  //Modificatore di visibilità. 
    int dim, len, delta;

private: 
    int * v;

public:

    Pila(int d, int delta)
    {
        this -> dim = dim;
        this -> delta = delta;

        dim = d;
        delta = 10;
        len = 0;
        v = new int[dim];
    }

    void push(int n)
    {
        if (len == dim)
        {

            //cout << "Estendo da " << dim << " a " << dim+delta << " !" << endl;

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

    int pop()
    {
        if( len == 0 )
        {
            cout << "\nERRORE pila vuota\n";

            return 0;
        }

        return v[--len];

        //int result = v [len - 1];

    }

    int getElement ( int index )
    {
        return v[index];
    }

    void setElement ( int index, int newValue )
    {
        v[index] = newValue;
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
    Pila vett(10, 10);

    for (int i = 0; i < 100; i++)
        vett.push(i);

    for (int i = 0; i < 100; i++)
    {
        cout << vett.pop() << " ";
    } 

    cout << endl;

    vett.print();       

    return 0;        
}
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <time.h>

using namespace std;

class Rettangolo
{
    private:
        int base, alt; 

    public:
        Rettangolo( int base, int alt )
        {
            this->base = base;
            this->alt = alt;
        }  

    int getPerimetro()
    {
        return ( base + alt ) * 2;
    }

    int getArea()
    {
        return base * alt;
    }

    void display()
    {
        for ( int i = 0; i < base; i++ )
        {
            for ( int j = 0; j < alt; j++)
            {
                cout << "*";
            }

            cout << endl;
        }
    }

    void salva()
    {
        ofstream file1 ( "prova.txt" );

        file1 << "Il perimetro e': " << getPerimetro();

        file1.close();
    }   
};

int main()
{
    int v[] = { 10, 2, 4 };

    for ( int i = 0; i < 3; i++ )
    {
        cout << v[i];
    }

    Rettangolo ret1 ( 10, 4 );

    cout << ret1.getPerimetro();

    cout << ret1.getArea();

    ret1.display();

    ret1.salva();

    return 0;

}
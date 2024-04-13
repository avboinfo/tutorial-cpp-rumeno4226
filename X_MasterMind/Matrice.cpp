/*
Matrice.cpp una classe definita da noi che spupazza la matrice come nessuno mai.
Andrei Bojan - 13.04.2024
*/

#include <iostream>
using namespace std;


class Matrice
{
    private:
       int m[10][10];
        
    public:
       Matrice()
       {
            for ( int i=0; i<10; i++)
                for ( int j=0; j<10; j++)
                    m[i][j] = 0;
       }
        
       void stampa()
       {
  
            cout << endl << "-------------------------------------------------------------" << endl;

            for ( int i=0; i<10; i++)
            {
                for ( int j=0; j<10; j++)
                {
                    cout << m[i][j] << "\t";
                }

                cout << endl;
            }

            cout << endl;
            cout << endl << "-------------------------------------------------------------" << endl;       
       } 
};

int main()
{
    Matrice m1 = Matrice();

    m1.stampa();
}
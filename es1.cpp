/*
Andrei Bojan, 3CIN, 16.03.2024
Verifica di Informatica: ESERCIZIO 1
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int colonna = 10;
const int riga = 10;

void riempiTabella(int matrix[colonna][riga])
{
    for (int i=0; i<colonna; i++)
    {
        for (int j=0; j<riga; j++)
        {
            matrix[i][j] = rand()%100;
        }
    }
}

void stampaTabella(int matrix[colonna][riga])
{
    for (int i=0; i<colonna; i++)
    {

        for (int j=0; j<riga; j++)
        {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;

    }
}

int controllaTabella(int matrix[colonna][riga])
{
    for (int i=0; i<colonna; i++)
    {
        int accUno=0;

        for (int j=0; j<riga; j++)
        {
            if(matrix[i][j]==0)
            {
                cout<<"Numero trovato nella tabella!"<<endl;
            }
        }
    }
}

int main()
{
    int matrix[10][10], n;

    riempiTabella(matrix);
    stampaTabella(matrix);

    srand(time(NULL))%100;

    cout<<"Dimmi un numero e ti diro' quante volte viene ripetuto nella tabella!"<<endl;

    cin >> n;

    cout<<"Il numero che hai scritto è stato ripetuto"<< n << "volte"<<endl;

    return 0;

}


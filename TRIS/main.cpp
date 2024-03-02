/*
Se in griglia c'è ZERO: Cella vuota
Se in griglia c'è UNO: Stiamo parlando di una X (giocatore 1)
Se in griglia c'è DUE: Stiamo parlando in un CERCHIO (giocatore 2)
*/

#include <iostream>
using namespace std;

class Tris
{
public:
    int griglia[3][3]; // Attributi

    void resetTabella()
    {

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                griglia[i][j] = 0;
            }
        }
    }

    void stampaGriglia()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << griglia[i][j] << "\t";
            }
            cout << endl;
        }
    }

    bool giocatoreUno(int x, int y)
    {
        if (x > 2 || x < 0)
            return false;

        if (y > 2 || y < 0)
            return false;

        if (griglia[x][y] == 1 || griglia[x][y] == 2)
            return false;

        griglia[x][y] = 1;
        return true;
    }

    bool giocatoreDue(int x, int y)
    {

        if (x > 2 || x < 0)
            return false;

        if (y > 2 || y < 0)
            return false;

        if (griglia[x][y] == 1 || griglia[x][y] == 2)
            return false;

        griglia[x][y] = 2;
        return true;
    }

    int controllaVincitore()
    {
        int risultato;
        for (int i = 0; i < 3; i++)
        {
            risultato = controllaColonna(i);
            if (risultato != 0)
                return risultato;

            risultato = controllaRiga(i);
            if (risultato != 0)
                return risultato;
        }

        /*risultato = controllaDiagonali();
        return risultato;*/

        //Compatto riga 84 e 85 unendole insieme:
        return controllaDiagonali();
    }

private:
    int controllaColonna(int col)
    {
        int accUno = 0;
        int accDue = 0;
        for (int i = 0; i < 3; i++)
        {
            int cella = griglia[i][col];
            if (cella == 1)
                accUno++;
            else if (cella == 2)
                accDue++;
        }

        if (accUno == 3)
            return 1;
        if (accDue == 3)
            return 2;
        return 0;
    }

    int controllaRiga(int riga)
    {
        int accUno = 0;
        int accDue = 0;

        for (int i = 0; i < 3; i++)
        {

            int cella = griglia[riga][i]; // Si ruota la riga con la i, e al posto della colonna mettiamo la i.
            if (cella == 1)
                accUno++;
            else if (cella == 2)
                accDue++;
        }

        if (accUno == 3)
            return 1;
        if (accDue == 3)
            return 2;
        return 0;
    }

    int controllaDiagonali()
    {
        // Controllo della Diagonale Principale

        int accUno = 0;
        int accDue = 0;

        for (int i = 0; i < 3; i++)
        {
            int cella = griglia[i][i];
            if (cella == 1)
                accUno++;
            else if (cella == 2)
                accDue++;
        }

        if (accUno == 3)
            return 1;
        if (accDue == 3)
            return 2;

        // Controllo Diagonale Secondaria

        accUno = 0;
        accDue = 0;

        for (int i = 0; i < 3; i++)
        {
            int cella = griglia[i][2 - i];
            if (cella == 1)
                accUno++;
            else if (cella == 2)
                accDue++;
        }

        if (accUno == 3)
            return 1;
        if (accDue == 3)
            return 2;

        // Ancora nessun'vincitore
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Tris myTris;

    myTris.resetTabella();

    cout << "Stato iniziale!" << endl;
    myTris.stampaGriglia();

    int x, y;
    bool mossaValida;
    int vincitore;
    int pareggio;
    int mosseTotali = 0;
    while (mosseTotali < 9)
    {
        do
        {
            cout << "Mossa del giocatore 1." << endl;
            cout << "X: ";
            cin >> x;

            cout << "Y: ";
            cin >> y;

            mossaValida = myTris.giocatoreUno(y, x);
        } while (!mossaValida);

        myTris.stampaGriglia();
        vincitore = myTris.controllaVincitore();
        if (vincitore != 0)
            break;

        mosseTotali++;
        if(mosseTotali >= 9)
            break;
        do
        {
            cout << "Mossa del giocatore 2." << endl;
            cout << "X: ";
            cin >> x;

            cout << "Y: ";
            cin >> y;

            mossaValida = myTris.giocatoreDue(y, x);
        } while (!mossaValida);

        myTris.stampaGriglia();

        vincitore = myTris.controllaVincitore();

        if (vincitore != 0)
            break;

        mosseTotali = mosseTotali + 1;
    }

    if (vincitore == 1)
        cout << "Il giocatore 1 ha vinto la sfida!" << endl;
    else if (vincitore == 2)
        cout << "Il giocatore 2 ha vinto la sfida!" << endl;
    else if (vincitore == 0)
        cout << "Avete pareggiato!" << endl;

    return 0;
}



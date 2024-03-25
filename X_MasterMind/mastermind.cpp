#include <iostream>
#include <cstdlib>
#include <ctime>

class mastermind
{
private:
    int numeroMosse;
    std::string ultimaMossa;

    static const int DIM_GIOCATA_VALIDA = 4; /*Static: variabile comune a tutti gli oggetti delle classi. Const: si mette per avere un array immutabile*/
    int giocataValida[DIM_GIOCATA_VALIDA];
    int codiceSegreto[DIM_GIOCATA_VALIDA];

    bool sanificaInput()
    {
        if (DIM_GIOCATA_VALIDA != ultimaMossa.size())
            return false;
        for (int i = 0; i < ultimaMossa.size(); i++)
        {
            char c = ultimaMossa[i];

            if (c >= '0' && c <= '9')
                giocataValida[i] = c - '0';

            else if (c == '-')
                giocataValida[i] = -1;

            else
                return false;
        }
        return true;
    }

    void generaCodiceSegreto()
    {
        srand(time(NULL));
        for (int i = 0; i < DIM_GIOCATA_VALIDA; i++)
        {
            codiceSegreto[i] = rand() % 10;

            std::cout << codiceSegreto[i];
        }

        std::cout << std::endl;
    }

    int *copiaVettore(int vettoreOriginale[])
    {
        static int vettoreCoppia[DIM_GIOCATA_VALIDA];
        for (int i = 0; i < DIM_GIOCATA_VALIDA; i++)
        {
            vettoreCoppia[i] = vettoreOriginale[i];
        }

        return vettoreCoppia;
    }

    void copiaVettoreBis(int vettoreOriginale[], int vettoreCopia[], int dimVet)
    {
        for (int i = 0; i < dimVet; i++)
        {
            vettoreCopia[i] = vettoreOriginale[i];
        }
    }

public:
    mastermind()
    {
        numeroMosse = 0;
        ultimaMossa = "";
        generaCodiceSegreto();
    };

    void nuovaGiocata()
    {
        do
        {
            std::cout << numeroMosse + 1 << ": ";

            std::getline(std::cin, ultimaMossa); /*Più preciso rispetto a cin.*/

        } while (!sanificaInput());

        numeroMosse++;
    }

    void risultatoMossa()
    {
        int strike, ball;
        strike = ball = 0;

        // int * codiceSegretoBis = copiaVettore(codiceSegreto, DIM_GIOCATA_VALIDA);

        int codiceSegretoBis[DIM_GIOCATA_VALIDA];

        copiaVettoreBis(codiceSegreto, codiceSegretoBis, DIM_GIOCATA_VALIDA);

        for (int i = 0; i < DIM_GIOCATA_VALIDA; i++)
        {
            for (int j = 0; j < DIM_GIOCATA_VALIDA; j++)
            {
                if (codiceSegreto[i] == codiceSegretoBis[j])
                {
                    if (i == j)
                        strike++;
                    else
                        ball++;
                    codiceSegretoBis[j] = -2;
                    break;
                }
            }


        }

        std::cout << "Il numero di strike e' :" << strike << std::endl;
        std::cout << "Il numero di ball e' :" << ball << std::endl;
    }

    bool puoiContinuare()
    {
        
    }
};
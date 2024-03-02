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

            if (c >= '0' && c<= '9')
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
            codiceSegreto[i] = rand()%10;

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
        /*code*/
    }
};
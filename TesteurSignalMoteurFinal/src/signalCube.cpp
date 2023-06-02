#include "cppgpio.hpp" // Inclure la bibliothèque C++ pour les GPIO
#include <unistd.h>    // Inclure la bibliothèque pour la fonction sleep
#include "signalCube.hpp"
#include "simuMoteurSortie.hpp"

using namespace GPIO;

signalCube::~signalCube(void)
{
    // Le destructeur ne fait rien ici
}

short anomalie;
short seuil = 3;
bool conforme = true;

void signalCube::triggered(unsigned int gpio)
{

    if (signal1.get_pin() == true) // verification du signal1
    {
        if (signal2.get_pin() == false)
        {
            anomalie++;
            if (anomalie <= seuil)
            {
                conforme = false;
                return;
            }
        }
    }
    else if (signal2.get_pin() == false) // verification du signal2
    {    unsigned int Ndirec = 6;
    unsigned int Ndemar = 7;
    DirectIn direction(Ndirec);
    DirectIn demarrage(Ndemar);
        if (signal1.get_pin() == true)
        {
            anomalie++;
            if (anomalie <= seuil)
            {
                conforme = false;
                return;
            }
        }
        return;
    }

    // Si les deux signaux sont conformes:

    conforme = true;

    simuMoteurSortie actionRota(bool signal1, bool signal2);

    if (signal1.get_state() == true) // convertion signal vers bouléen
    {
        signal1 = true; // sens horaire
                        //apppeler ici la classe simu ou définitive pour controller le moteur

    }
    else
    {
        signal1 = false; // sens anti horaire
                        //apppeler ici la classe simu ou définitive pour controller le moteur

    }

    if (signal2.get_state() == true) // convertion signal vers bouléen
    
    {
        signal2 = true; // démarrer moteur
                       //apppeler ici la classe simu ou définitive pour controller le moteur

    }
    else
    {
        signal2 = false; // moteur immobile
                         //apppeler ici la classe simu ou définitive pour controller le moteur

    }
}
#include "cppgpio.hpp" // Inclure la bibliothèque C++ pour les GPIO
#include <unistd.h>    // Inclure la bibliothèque pour la fonction sleep
#include "signalCube.hpp"
#include "Moteur.hpp"

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
    {

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

    Moteur moteur(27, 17);

    if (signal1.get_state() == true) // convertion signal vers bouléen
    {
        // sens horaire
        // apppeler ici la classe simu ou définitive pour controller le moteur
        moteur.tournerHoraire(0);
    }
    else
    {
        // sens anti horaire
        // apppeler ici la classe simu ou définitive pour controller le moteur
        moteur.tournerAntiHoraire(0);
    }

    if (signal2.get_state() == false) // convertion signal vers bouléen

        if (moteur.getEstEnMouvement() == true)
        {
    
        // moteur immobile
                         // apppeler ici la classe simu ou définitive pour controller le moteur
        moteur.arretMoteur();

        }
}
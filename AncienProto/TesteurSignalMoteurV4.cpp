#include "cppgpio.hpp" // Inclure la bibliothèque C++ pour les GPIO
#include <iostream>    // Inclure la bibliothèque pour l'affichage en console
#include <unistd.h>    // Inclure la bibliothèque pour la fonction sleep

using namespace std;
using namespace GPIO;

int main()
{

short numGPIO1 = 3;                  //variable afin de modifier quel GPIO utiliser plus ergonomiquement
short numGPIO2 = 4;                  //variable afin de modifier quel GPIO utiliser plus ergonomiquement

    DigitalIn input1(numGPIO1,GPIO_PULL::UP,chrono::nanoseconds(1000),chrono::nanoseconds(2000));// Initialiser l'entrée GPIO 1 en mode entrée
    DigitalIn input2(numGPIO2,GPIO_PULL::UP,chrono::nanoseconds(1000),chrono::nanoseconds(2000)); // Initialiser l'entrée GPIO 2 en mode entrée

    float entree1;
    float entree2;

    while (1) // Boucle infinie
    {
        input1.
        gpio.read(input1,entree1);                              // Lire l'état de l'entrée GPIO 1 et stocker la valeur dans la variable entree1
        gpio.read(input2,entree2);                              // Lire l'état de l'entrée GPIO 2 et stocker la valeur dans la variable entree2
        cout << "GPIO " << numGPIO1 << ": " << entree1 << endl; // Afficher l'état de l'entrée GPIO 1
        cout << "GPIO " << numGPIO2 << ": " << entree2 << endl; // Afficher l'état de l'entrée GPIO 2

        sleep(120); // Attendre 120 millisecondes avant de lire les entrées à nouveau
    }

    return 0; // Terminer le programme
}
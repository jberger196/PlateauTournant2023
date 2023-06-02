#include <iostream>
#include <pigpio.h> // Inclusion de la bibliothèque pigpio

#define INPUT1 4 // Définition de la première entrée GPIO
#define INPUT2 5 // Définition de la deuxième entrée GPIO

int main()
{
    // Initialisation de la bibliothèque pigpio
    if (gpioInitialise() < 0)
    {
        cout << "Erreur lors de l'initialisation de la bibliothèque pigpio" << endl;
        return 1;
    }

    // Configuration des entrées GPIO en entrée
    gpioSetMode(INPUT1, PI_INPUT);
    gpioSetMode(INPUT2, PI_INPUT);

    while(true) // Boucle infinie pour analyser les entrées en continu
    {
        // Lecture de la valeur de la première entrée GPIO
        int value1 = gpioRead(INPUT1);

        // Lecture de la valeur de la deuxième entrée GPIO
        int value2 = gpioRead(INPUT2);

        // Affichage de la valeur de la première entrée sur la console
        cout << "Entrée 1 : " << value1 << endl;

        // Affichage de la valeur de la deuxième entrée sur la console
        cout << "Entrée 2 : " << value2 << endl;

        // Pause de 100 ms pour laisser le temps à la console de se mettre à jour
        gpioDelay(100000);
    }

    // Termination de la bibliothèque pigpio
    gpioTerminate();

    return 0;
}

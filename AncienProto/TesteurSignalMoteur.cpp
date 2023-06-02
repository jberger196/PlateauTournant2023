#include <iostream>
#include <wiringPi.h> // Inclusion de la bibliothèque wiringPi

#define INPUT1 4 // Définition de la première entrée GPIO
#define INPUT2 5 // Définition de la deuxième entrée GPIO

using namespace std; // Utilisation du namespace std

int main()
{
    // Initialisation de la bibliothèque wiringPi
    wiringPiSetup();

    // Configuration des entrées GPIO en entrée
    pinMode(INPUT1, INPUT);
    pinMode(INPUT2, INPUT);

    while(true) // Boucle infinie pour analyser les entrées en continu
    {
        // Lecture de la valeur de la première entrée GPIO
        int value1 = digitalRead(INPUT1);

        // Lecture de la valeur de la deuxième entrée GPIO
        int value2 = digitalRead(INPUT2);

        // Affichage de la valeur de la première entrée sur la console
        cout << "Entrée 1 : " << value1 << endl;

        // Affichage de la valeur de la deuxième entrée sur la console
        cout << "Entrée 2 : " << value2 << endl;

        // Pause de 100 ms pour laisser le temps à la console de se mettre à jour
        delay(100);
    }

    return 0;
}
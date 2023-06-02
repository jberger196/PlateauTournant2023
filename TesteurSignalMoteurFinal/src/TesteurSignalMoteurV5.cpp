#include "cppgpio.hpp" // Inclure la bibliothèque C++ pour les GPIO
#include <iostream>    // Inclure la bibliothèque pour l'affichage en console
#include <unistd.h>    // Inclure la bibliothèque pour la fonction sleep
#include "signalCube.hpp"

using namespace std;
using namespace GPIO;

int main(){


    unsigned int signal1 = 6;   //variable afin de modifier quel GPIO utiliser plus ergonomiquement
    unsigned int signal2 = 5;   //variable afin de modifier quel GPIO utiliser plus ergonomiquement

    signalCube signal(signal1,signal2,GPIO_PULL::OFF);     //paramètre signalCube pour signaler les fronts montants et descandants sur la broche 3 et 4

    signal.start();          //lance la détéction des fronts
while(1){}
}
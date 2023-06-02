#include <iostream>    // Inclure la bibliothèque pour l'affichage en console
#include <unistd.h>    // Inclure la bibliothèque pour la fonction sleep
#include "../include/SignalCube.hpp"
#include "../include/PlateauTournant.h"

using namespace std;
using namespace GPIO;

int main(){
    PlateauTournant *_plateauTournant = new PlateauTournant();

    unsigned int signal1 = 5;   //variable afin de modifier quel GPIO utiliser plus ergonomiquement
    unsigned int signal2 = 6;   //variable afin de modifier quel GPIO utiliser plus ergonomiquement

    SignalCube signal(_plateauTournant, signal1,signal2,GPIO_PULL::OFF);     //paramètre signalCube pour signaler les fronts montants et descandants sur les broche selectionnés

    signal.start();          //lance la détéction des fronts
    while(true);

}

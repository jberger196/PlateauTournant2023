#include <iostream>    // affiche des sorties écran
#include "signalCube.hpp"
#include "simuMoteurSortie.hpp"

using namespace GPIO;
using namespace std;


simuMoteurSortie::simuMoteurSortie(bool signal1, bool signal2)
{

    signalCube signal(signal1, signal2, GPIO_PULL::OFF); // paramètre signalCube pour signaler les fronts montants et descandants sur la broche 3 et 4

    if (signal1 == true)
    {
        cout << "sens de rotation : horaire     " << (char)0x0D;
    }
    else
    {
        cout << "sens de rotation : anti horaire" << (char)0x0D;
    }

    if (signal2 == true)
    {
        cout << "rotation: en cour... " << (char)0x0D;
    }
    else
    {
        cout << "rotation: stopée    " << (char)0x0D;
    }
}

simuMoteurSortie::~simuMoteurSortie(void){};
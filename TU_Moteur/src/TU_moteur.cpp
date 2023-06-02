#include <cstdlib>
#include <iostream>
#include "../include/Moteur.h"
#include <thread>
#include <unistd.h>
#include <mutex>

using namespace std;

int main()
{
    char sens;
    Moteur *toto = new Moteur;
    do
    {
        cout << "Voulez-vous tourner à droite (d) ou bien tourner à gauche (g) ou arrêter (a)?" << endl;
        cin >> sens;
        if (sens == 'd')
            toto->tournerD();
        else if (sens == 'g')
            toto->tournerG();
        else
            toto->eteindre();
        sleep(2);
    } while ((sens == 'd') || (sens == 'g'));

        return 0;
}

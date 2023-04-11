#include <iostream>
#include <unistd.h>
#include "../include/Interrupteur.h"

int main()
{
    Interrupteur tuInterrupteur(23);

    while(true)
    {
        usleep(3000000);
        tuInterrupteur.actionner();
        std::cout << "GPIO ouverte" << std::endl;
        usleep(3000000);
        tuInterrupteur.desactiver();
        std::cout << "GPIO fermée" << std::endl;
    }
    return 0;
}
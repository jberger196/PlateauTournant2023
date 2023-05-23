#include <iostream>
#include <unistd.h>
#include "../include/Interrupteur.h"

int main()
{
    Interrupteur tuInterrupteur(23);

    char reponse; 
    while(true)
    {
        std::cout<<"Voulez vous actionner l'interrutpeur ? o/n"<<std::endl;
        std::cin>>reponse;
        if(reponse == 'o')
        {
            tuInterrupteur.actionner();
            std::cout << "GPIO ouverte" << std::endl;
        }
        else
        {
            tuInterrupteur.desactiver();
            std::cout << "GPIO fermée" << std::endl;
        }
    }
    return 0;
}
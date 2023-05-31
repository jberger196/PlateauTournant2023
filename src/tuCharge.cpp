#include <iostream>
#include <unistd.h>
#include "../include/Charge.hpp"

int main()
{
    Charge tuCharge(0x40);

    while(true)
    {

    tuCharge.lire();
    float CourantCharge = tuCharge.getCourant();
    std::cout << "Courant: " << CourantCharge << " A" << std::endl;

    float TensionCharge = tuCharge.getTension();
    std::cout << "Tension: " << TensionCharge << " V" << std::endl;
    
    usleep(3000000);
    }
}

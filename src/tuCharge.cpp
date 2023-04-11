#include <iostream>
#include <unistd.h>
#include "../include/Charge.hpp"

int main()
{
    Charge tuCharge(0.1, 2.0, 0x40, RANGE_16V,GAIN_8_320MV,ADC_12BIT,ADC_12BIT);

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

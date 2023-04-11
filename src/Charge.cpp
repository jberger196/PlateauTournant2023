#include "../include/Charge.hpp"
#include <unistd.h>

Charge::Charge(float shunt_resistance, float max_expected_amps, uint8_t address, 
int voltage_range, int gain, int bus_adc, int shunt_adc)
{
    leCapteur = new INA219(shunt_resistance, max_expected_amps, address);
    leCapteur->configure(voltage_range, gain, bus_adc, shunt_adc);
}

void Charge::lire(){

    laTension = leCapteur->voltage();
    leCourant = leCapteur->current()/1000;
    sleep(1);
}

float Charge::getTension()
{
    return laTension;
}

float Charge::getCourant()
{
    return leCourant;
}

Charge::~Charge(){}

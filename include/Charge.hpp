#include "../src/ina219.h"


class Charge
{
    private :

    //Class charge composée d'un objet INA219
    INA219 *leCapteur;

    float leCourant;
    float laTension;

    public :

    Charge(float shunt_resistance, float max_expected_amps, uint8_t address, 
    int voltage_range, int gain, int bus_adc, int shunt_adc);

    void lire();
    void configure(int voltage_range, int gain, int bus_adc, int shunt_adc);
    float getTension();
    float getCourant();

    ~Charge();
};
#include "../src/ina219.h"


class Charge
{
    private :

    //Class charge composée d'un objet INA219
    INA219 *leCapteur;

    float leCourant;
    float laTension;

    public :

    Charge(uint8_t address);

    void lire();
    float getTension();
    float getCourant();

    ~Charge();
};
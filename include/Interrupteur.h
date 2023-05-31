#include "cppgpio/output.hpp"

class Interrupteur
{
    private :
    GPIO::DigitalOut *actionneur;
    bool on;

    public : 
    Interrupteur(unsigned int pin);
    
    void actionner();
    void desactiver();
    bool getEtat();

    ~Interrupteur();
};
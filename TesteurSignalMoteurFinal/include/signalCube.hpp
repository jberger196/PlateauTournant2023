#ifndef __SIGNAL_CUBE_HPP
#define __SIGNAL_CUBE_HPP

#include "cppgpio.hpp" // Inclure la bibliothèque C++ pour les GPIO
#include <unistd.h>    // Inclure la bibliothèque pour la fonction sleep

using namespace GPIO;

class signalCube : public InputDetect
{
private:
    DigitalIn signal1;
    DigitalIn signal2;
    bool conforme;

public:
    signalCube( /// GPIO pin to use
        unsigned int pin1,
        unsigned int pin2,
        
        /// pullup / down / none
        GPIO_PULL pullupdown = GPIO_PULL::OFF,

        /// define the interval that has to pass between two events
        std::chrono::nanoseconds min_trigger_interval = std::chrono::nanoseconds(2 * 1000 * 1000), // 2 ms
        
        /// define the minimum time the gpio pin has to be triggered
        /// before a trigger is detected (to protect against noise on
        /// the line)
        std::chrono::nanoseconds min_hold_interval = std::chrono::nanoseconds(1 * 1000 * 1000)) // 1 ms
        : InputDetect({pin1, pin2}, GPIO_EDGE::BOTH), signal1(pin1, pullupdown, min_trigger_interval, min_hold_interval),
          signal2(pin2, pullupdown, min_trigger_interval, min_hold_interval)
    {
    }


    virtual void triggered(unsigned int gpio);

    ~signalCube(void);

    ;
};


#endif //__SIGNAL_CUBE_HPP
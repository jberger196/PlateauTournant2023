#ifndef BOMBARDEMENT_H
#define BOMBARDEMENT_H

#include "cppgpio/buttons.hpp"

using namespace GPIO;

class Bombardement : public InputDetect
{
public:
	Bombardement(/// GPIO pin to use
               unsigned int pin,
               /// pullup / down / none
               GPIO_PULL pullupdown = GPIO_PULL::OFF,
               /// define the interval that has to pass between two events
               std::chrono::nanoseconds min_trigger_interval = std::chrono::nanoseconds(2 * 1000 * 1000),  // 2 ms
               /// define the minimum time the gpio pin has to be triggered
               /// before a trigger is detected (to protect against noise on
               /// the line)
               std::chrono::nanoseconds min_hold_interval = std::chrono::nanoseconds(1 * 1000 * 1000))     // 1 ms
        : InputDetect({ pin }, GPIO_EDGE::RISING)
        , m_pin(pin,
                pullupdown,
                min_trigger_interval,
                min_hold_interval)
        {}
	~Bombardement(void);
protected:
	DigitalIn m_pin;

	virtual void triggered(unsigned int gpio);
};

#endif

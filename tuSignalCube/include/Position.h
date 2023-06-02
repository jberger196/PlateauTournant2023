#include <exception>
using namespace std;

#ifndef __Position_h__
#define __Position_h__

#include "../include/cppgpio/buttons.hpp"

// class InputDetect;
class Position;

class Position: public InputDetect
{
	private: DigitalIn _capteur1;
	private: DigitalIn _capteur2;

	public: void triggered(unsigned int aGpio);

	public: void setCapteur1(DigitalIn aCapteur1);

	public: DigitalIn getCapteur1();
};

#endif

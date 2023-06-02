#include <exception>
using namespace std;

#ifndef __Interrupteur_h__
#define __Interrupteur_h__

#include "DigitalOut.h"

class DigitalOut;
class Interrupteur;

class Interrupteur
{
	private: bool _on;
	private: DigitalOut _actionneur;

	public: void actionner();

	public: void desactiver();

	public: void setActionneur(DigitalOut aActionneur);

	public: DigitalOut getActionneur();
};

#endif

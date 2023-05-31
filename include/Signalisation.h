#include <exception>
using namespace GPIO;

#ifndef __Signalisation_h__
#define __Signalisation_h__

#include "cppgpio/output.hpp"

class Signalisation
{
	private: bool _on_off;
	private: DigitalOut _voyantVert;
	private: DigitalOut _voyantJaune;
	private: DigitalOut _voyantRouge;

	public: bool getOn_off();

	public: void setOn_off(bool aOn_off);

	public: void signalerProblemeBatterie();

	public: void finirProblemeBatterie();

	public: void signalerDemarragMoteur();

	public: void setVoyantVert(DigitalOut aVoyantVert);

	public: DigitalOut getVoyantVert();

	public: void setVoyantJaune(DigitalOut aVoyantJaune);

	public: DigitalOut getVoyantJaune();

	public: void setVoyantRouge(DigitalOut aVoyantRouge);

	public: DigitalOut getVoyantRouge();
};

#endif

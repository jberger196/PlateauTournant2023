#include "cppgpio/output.hpp"
#include <thread>
#include <chrono>

using namespace GPIO; // vert 9, jaune 11, rouge 24
using namespace std;

class Signalisation
{
public:
	Signalisation(int pinVoyantVert, int pinVoyantJaune, int pinVoyantRouge);

	void signalerChargeBatterie();
	void finSignalerChargeBatterie();

	void signalerPbAlim();
	void finSignalerPbAlim();
	thread tSignalerPbAlim();

	void signalerPbSecurite();
	void finSignalerPbSecurite();

	void signalerMiseEnMouvement();
	void finirMiseEnMouvement();

	/*void arretUrgence();
	void finArretUrgence();*/

	bool getChargeEnCours();
	void setChargeEnCours(bool charge);

private:
	DigitalOut *voyantVert;
	DigitalOut *voyantJaune;
	DigitalOut *voyantRouge;
	bool clePbAlim;
};
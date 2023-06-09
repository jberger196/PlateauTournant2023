#include "cppgpio/output.hpp"
#include <thread>
#include <chrono>

using namespace GPIO; // vert 9, jaune 11, rouge 24
using namespace std;

class Signalisation
{
public:
	Signalisation(int pinVoyantVert, int pinVoyantJaune, int pinVoyantRouge);

	void signalerChargeBatterie(); //allumer vert constant, utilisé dans Ares::alimenterBatterie
	void finSignalerChargeBatterie();

	void signalerPbAlim(); //jaune clignotant, PAS UTILISEE
	void finSignalerPbAlim();
	thread tSignalerPbAlim();

	void signalerPbSecurite(); //allumer rouge constant, PAS UTILISEE
	void finSignalerPbSecurite();

	void signalerMiseEnMouvement(); //allumage successif vert jaune rouge, utilisé dans PlateauTournant::tournerHoraire/tournerAntiHoraire
	void finirMiseEnMouvement();

	/*void arretUrgence();
	void finArretUrgence();*/

	bool getChargeEnCours();
	void setChargeEnCours(bool charge);

	void allumerJaune();
	void eteindreJaune();

private:
	DigitalOut *voyantVert;
	DigitalOut *voyantJaune;
	DigitalOut *voyantRouge;
	bool clePbAlim;
};
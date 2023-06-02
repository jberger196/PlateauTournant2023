#include <exception>
#include <vector>
using namespace std;

#ifndef __AlimentationBatterie_h__
#define __AlimentationBatterie_h__

// #include "Interrupteur.h"
#include "Charge.h"

class Interrupteur;
class Charge;
class AlimentationBatterie;

class AlimentationBatterie
{
	private: Interrupteur* _lInterrupteur;
	private: std::vector<Charge*> _laCharge;

	public: void alimenter();

	public: void releverDonneesCharge();

	public: void couper();

	public: void obtenirDonnees(float& aCourant, float& aTension);
};

#endif

#include <exception>
using namespace std;

#ifndef __Cerbere_h__
#define __Cerbere_h__

// #include "C_CourantMoteur.h"
// #include "C_Fixation.h"
// #include "C_Force.h"
#include "Journal.h"
#include "Ares.h"
#include "Consigne.h"
#include "Cube.h"
#include "Signalement.h"

/**
 * Classe g�n�rale de l'application de diagnostic et s�curit� du plateau.
 * Fournit le thread de gestion de la s�curit�
 */
class Cerbere
{
	private: C_CourantMoteur* _leCourantMoteur;
	private: C_Fixation* _laFixation;
	private: C_Force* _laPresence;
	private: Journal* _lesJournaux;
	private: Ares* _lOperation;

	public: void lancerSurveillance();

	private: void verifierCourant();

	public: void verifierPresence();

	public: void verifierFixation();

	public: Cerbere(Consigne aConsigne, Cube aCube, Signalement aSignalement);

	public: Ares *getAres();

	public: void setAres(Ares* aAres);
};

#endif
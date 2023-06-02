using namespace std;

#ifndef __Ares_h__
#define __Ares_h__

#include "Cerbere.h"
#include "Moteur.h"
#include "HautParleur.h"
#include "Signalisation.h"
#include "AlimentationBatterie.h"
#include "Sauvegarde.h"
#include "Position.h"
#include "Cube.h"
#include "Signalement.h"
#include "Consigne.h"

class Ares
{
	private: Cerbere* _laSecurite;
	private: Moteur* _lePilote;
	private: HautParleur* _leSonore;
	private: Signalisation* _laSignalisation;
	private: AlimentationBatterie* _lAlimentationB;
	private: Sauvegarde* _laSauvegarde;
	private: Position* _laPosition;
    private: Consigne* _laConsigne;
    private: Signalement* _leSignalement;

	public: void commuterAlimentation();

	public: void mesurerCourantCharge();

	public: void alerteChargeOn();

	public: void alerteChargeOff();

	public: void lireDate();

    public: void tournerHoraire();

    public: void tournerAntiHoraire();

    public: void immobiliser();

	public: Ares(Cube aCube, Signalement aSignalement, Consigne aConsigne);

};

#endif
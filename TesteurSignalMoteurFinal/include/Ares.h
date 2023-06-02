#ifndef __Ares_h__
#define __Ares_h__

#include "Cerbere.hpp"
#include "Moteur.h"
#include "HautParleur.h"
#include "Signalisation.h"
#include "AlimentationBatterie.h"
#include "Sauvegarde.h"
#include "Position.h"
#include "Cube.h"
#include "Signalement.h"
#include "Consigne.hpp"

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
	private: Journal* _leJournal;
	private: float courant;
	private: float seuiCourantChargeInvalide;
	private: float seuilCourantChargeValide;

	public: void alerteChargeOn();

	public: void alerteChargeOff();

    public: void tournerHoraire();

    public: void tournerAntiHoraire();

    public: void immobiliser();

	public: void alimenterBatterie();

	public: thread tAlimenterBatterie();

	public: Ares(Cube aCube, Signalement aSignalement, Consigne aConsigne);

	public: Cerbere* getCerbere();

	public: void setCerbere(Cerbere *aCerbere);
};

#endif
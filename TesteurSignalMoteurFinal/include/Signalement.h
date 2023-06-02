#include <exception>
using namespace std;

#ifndef __Signalement_h__
#define __Signalement_h__

// #include "PlateauTournant.h"

class PlateauTournant;
class Signalement;

class Signalement
{
	private: bool _alerteMoteur;
	private: bool _alerteBatterie;
	private: bool _alerteFixation;
	private: bool _alertePresence;
	public: PlateauTournant* _unnamed_PlateauTournant_;

	public: bool getAlerteMoteur();

	public: void setAlerteMoteur(bool aAlerteMoteur);

	public: bool getAlerteBatterie();

	public: void setAlerteBatterie(bool aAlerteBatterie);

	public: bool getAlerteFixation();

	public: void setAlerteFixation(bool aAlerteFixation);

	public: bool getAlertePresence();

	public: void setAlertePresence(bool aAlertePresence);

	public: void signalerProbleme();
};

#endif

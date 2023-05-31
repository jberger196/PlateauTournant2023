#include <exception>
using namespace std;

#ifndef __Signalement_h__
#define __Signalement_h__

class Signalement
{
	private: bool _alerteMoteur;
	private: bool _alerteBatterie;
	private: bool _alerteFixation;
	private: bool _alertePresence;

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
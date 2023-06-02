#include <exception>
using namespace std;

#ifndef __Charge_h__
#define __Charge_h__

class Charge;

class Charge
{
	private: INA219 _leCapteur;
	private: float _courant;
	private: float _tension;

	public: void lire();

	public: void setLeCapteur(INA219 aLeCapteur);

	public: INA219 getLeCapteur();

	public: void setCourant(float aCourant);

	public: float getCourant();

	public: void setTension(float aTension);

	public: float getTension();
};

#endif

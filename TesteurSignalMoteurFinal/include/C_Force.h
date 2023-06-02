#include <exception>
using namespace std;

#ifndef __C_Force_h__
#define __C_Force_h__

#include "i2c.h"

// class i2c;
class C_Force;

class C_Force: public i2c
{
	private: float _relevePied1;
	private: float _relevePied2;
	/**
	 * Adresse I2C du convertisseur Analogique Numérique permettant le relevé des 2 capteurs de force.
	 */
	private: string _adresseCAN;

	public: bool lire(char aNCapteur);

	public: C_Force(char aAdresseCAN, char aEntreeCForce1, char aEntreeCapteur2);
};

#endif

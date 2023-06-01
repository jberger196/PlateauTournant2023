#include <exception>
using namespace std;

#include "../include/Consigne.h"

Consigne::Consigne()
{
	seuilPresence = 2800;
	seuilAbscence = 10000;
	ValMinMot = 35;	 // en mA et en valeure absolue
	ValMaxMot = 230; // en mA et en valeur absolue
	seuilCourantChargeInvalide = 0.05;
	seuilCourantChargeValide = 0.08;
}

bool Consigne::obtenirSeuilCourantMoteur()
{
	throw "Not yet implemented";
}

bool Consigne::obtenirSeuilsPresence(float &aSeuilMin, float &aSeuilMax)
{
	throw "Not yet implemented";
}

bool Consigne::lireConsignes()
{
	throw "Not yet implemented";
}

float Consigne::getSeuilmin()
{
	return seuilPresence;
}
float Consigne::getSeuilmax()
{
	return seuilAbscence;
}

Consigne::~Consigne()
{
}

void Consigne::setValMinMot(int val)
{

}

void Consigne::setValMaxMot(int val)
{

}

int Consigne::getValMinMot()
{
		return this->ValMinMot;
}

int Consigne::getValMaxMot()
{
		return this->ValMaxMot;
}
float Consigne::getSeuilCourantChargeInvalide(){
	return 	this->seuilCourantChargeInvalide;
}
float Consigne::getSeuilCourantChargeValide(){
	return this->seuilCourantChargeValide;
}
#include <exception>
using namespace std;

#include "../include/Consigne.h"

Consigne::Consigne()
{
	seuilPresence = 2800;
	seuilAbscence = 10000;
	ValMinMot = 35;	 // en mA et en valeure absolue
	ValMaxMot = 230; // en mA et en valeur absolue
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
	return this->setValMinMot;
}

void Consigne::setValMaxMot(int val)
{
	return this->setValMaxMot;
}

int Consigne::getValMinMot()
{
}

int Consigne::getValMaxMot()
{
}
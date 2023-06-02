#include <exception>
using namespace std;

#include "Charge.h"
void Charge::lire() {
	throw "Not yet implemented";
}

void Charge::setLeCapteur(INA219 aLeCapteur) {
	this->_leCapteur = aLeCapteur;
}

INA219 Charge::getLeCapteur() {
	return this->_leCapteur;
}

void Charge::setCourant(float aCourant) {
	this->_courant = aCourant;
}

float Charge::getCourant() {
	return this->_courant;
}

void Charge::setTension(float aTension) {
	this->_tension = aTension;
}

float Charge::getTension() {
	return this->_tension;
}


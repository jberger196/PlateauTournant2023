#include <exception>
using namespace std;

#include "Interrupteur.h"
#include "DigitalOut.h"

void Interrupteur::actionner() {
	throw "Not yet implemented";
}

void Interrupteur::desactiver() {
	throw "Not yet implemented";
}

void Interrupteur::setActionneur(DigitalOut aActionneur) {
	this->_actionneur = aActionneur;
}

DigitalOut Interrupteur::getActionneur() {
	return this->_actionneur;
}


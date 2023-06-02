#include <exception>
using namespace std;

#include "Signalisation.h"
#include "DigitalOut.h"

bool Signalisation::getOn_off() {
	return this->_on_off;
}

void Signalisation::setOn_off(bool aOn_off) {
	this->_on_off = aOn_off;
}

void Signalisation::signalerProblèmeBatterie() {
	throw "Not yet implemented";
}

void Signalisation::finirProblemeBatterie() {
	throw "Not yet implemented";
}

void Signalisation::signalerDémarragMoteur() {
	throw "Not yet implemented";
}

void Signalisation::setVoyantVert(DigitalOut aVoyantVert) {
	this->_voyantVert = aVoyantVert;
}

DigitalOut Signalisation::getVoyantVert() {
	return this->_voyantVert;
}

void Signalisation::setVoyantJaune(DigitalOut aVoyantJaune) {
	this->_voyantJaune = aVoyantJaune;
}

DigitalOut Signalisation::getVoyantJaune() {
	return this->_voyantJaune;
}

void Signalisation::setVoyantRouge(DigitalOut aVoyantRouge) {
	this->_voyantRouge = aVoyantRouge;
}

DigitalOut Signalisation::getVoyantRouge() {
	return this->_voyantRouge;
}


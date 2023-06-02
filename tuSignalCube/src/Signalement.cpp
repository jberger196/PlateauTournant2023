#include <exception>
using namespace std;

#include "Signalement.h"
bool Signalement::getAlerteMoteur() {
	return this->_alerteMoteur;
}

void Signalement::setAlerteMoteur(bool aAlerteMoteur) {
	this->_alerteMoteur = aAlerteMoteur;
}

bool Signalement::getAlerteBatterie() {
	return this->_alerteBatterie;
}

void Signalement::setAlerteBatterie(bool aAlerteBatterie) {
	this->_alerteBatterie = aAlerteBatterie;
}

bool Signalement::getAlerteFixation() {
	return this->_alerteFixation;
}

void Signalement::setAlerteFixation(bool aAlerteFixation) {
	this->_alerteFixation = aAlerteFixation;
}

bool Signalement::getAlertePresence() {
	return this->_alertePresence;
}

void Signalement::setAlertePresence(bool aAlertePresence) {
	this->_alertePresence = aAlertePresence;
}

void Signalement::signalerProbleme() {
	throw "Not yet implemented";
}


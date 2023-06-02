#include "../include/Ares.h"
#include "../include/Cerbere.hpp"
#include "../include/Moteur.h"
#include "../include/HautParleur.h"
#include "../include/Signalisation.h"
#include "../include/AlimentationBatterie.h"
#include "../include/Sauvegarde.h"
#include "../include/Position.h"
#include "../include/Cube.h"
#include "../include/Signalement.h"
#include "../include/Consigne.hpp"

using namespace std;

void Ares::commuterAlimentation() {

}

void Ares::mesurerCourantCharge() {

}

void Ares::alerteChargeOn() {

}

void Ares::alerteChargeOff() {

}

void Ares::lireDate() {

}


void Ares::tournerHoraire(){
	_lePilote -> tournerHoraire(5);
}

void Ares::tournerAntiHoraire(){
	_lePilote ->  tournerAntiHoraire(5);
}

void Ares::immobiliser(){
	_lePilote ->  arretMoteur();
	thread tAlimenterBatterie -> alimenter();
	tAlimenterBatterie.detach;
}


Ares::Ares(Cube aCube, Signalement aSignalement, Consigne aConsigne) {
}

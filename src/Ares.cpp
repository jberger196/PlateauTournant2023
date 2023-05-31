#include "../include/Ares.h"

Ares::Ares(Cube aCube, Signalement aSignalement, Consigne aConsigne)
{

}

void Ares::commuterAlimentation()
{
    _lAlimentationB->alimenter();
}

void Ares::mesurerCourantCharge()
{
    _lAlimentationB->releverDonneesCharge();
}

void Ares::alerteChargeOn()
{
    
}

void Ares::alerteChargeOff()
{

}

void Ares::immobiliser()
{

}

void Ares::tournerAntiHoraire()
{

}

void Ares::tournerHoraire()
{

}
Ares::~Ares()
{

}
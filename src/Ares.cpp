#include "../include/Ares.h"

Ares::Ares()
{
_lAlimentationB = new AlimentationBatterie(23, 0x44);
}

void Ares::commuterAlimentation()
{

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

void Ares::lireDate()
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
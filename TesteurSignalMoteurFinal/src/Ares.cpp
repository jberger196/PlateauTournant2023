#include "../include/Ares.h"
#include <unistd.h>

Ares::Ares(Cube aCube, Signalement aSignalement, Consigne aConsigne)
{
_lAlimentationB = new AlimentationBatterie(23,0x44);
}
void Ares::alerteChargeOn(){
    
}
void Ares::alerteChargeOff(){

}
void Ares::immobiliser(){

}
void Ares::tournerAntiHoraire(){

}
void Ares::tournerHoraire(){

}
void Ares::alimenterBatterie(){
    usleep(2000000);
    _lAlimentationB->alimenter();
    _lAlimentationB->releverDonneesCharge();
    _lAlimentationB->obtenirDonnees();
    _lAlimentationB->getCourant();
    if (courant < seuiCourantChargeInvalide){
        this->alerteChargeOff();
        _lAlimentationB->couper();
    }
    else{
        while(courant > seuilCourantChargeValide){
            /*this->alerteChargeOn();*/
            _lAlimentationB->releverDonneesCharge();
            _lAlimentationB->obtenirDonnees();
            _lAlimentationB->getCourant();
        }
    }
    _lAlimentationB->couper();
}
thread Ares::tAlimenterBatterie()
{
    return thread([this]{
        alimenterBatterie();
    });
}
Ares::~Ares()
{
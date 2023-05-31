#include "../include/Signalisation.h"
#include <unistd.h>

Signalisation::Signalisation(int pinVoyantVert, int pinVoyantJaune, int pinVoyantRouge){
    this->voyantVert = new PWMOut(pinVoyantVert);
    this->voyantVert->set_range(200);

    this->voyantJaune = new PWMOut(pinVoyantJaune);
    this->voyantJaune->set_range(200);

    this->voyantRouge = new PWMOut(pinVoyantRouge);
    this->voyantRouge->set_range(200);
}

void Signalisation::chargeBatterie(){
    this->voyantVert->set_ratio(200);
}

void Signalisation::finChargeBatterie(){
    this->voyantVert->set_ratio(0);
}
















void Signalisation::miseEnMouvement(){
    while(true){
        this->voyantVert->on();
        usleep(500000); //0.5s
        this->voyantVert->off();
        usleep(500000); //0.5s
    }
}

void Signalisation::finMiseEnMouvement(){
    this->voyantVert->off();
}





void Signalisation::allumerVert(){
    this->voyantVert->on();
}

void Signalisation::allumerJaune(){
    this->voyantJaune->on();
}

void Signalisation::allumerRouge(){
    this->voyantRouge->on();
}

void Signalisation::eteindreVert(){
    this->voyantVert->off();
}

void Signalisation::eteindreJaune(){
    this->voyantJaune->off();
}

void Signalisation::eteindreRouge(){
    this->voyantRouge->off();
}


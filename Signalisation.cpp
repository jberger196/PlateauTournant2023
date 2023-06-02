#include "../include/Signalisation.h"
#include <unistd.h>

Signalisation::Signalisation(int pinVoyantVert, int pinVoyantJaune, int pinVoyantRouge){
    this->voyantVert = new DigitalOut(pinVoyantVert);
    this->voyantJaune = new DigitalOut(pinVoyantJaune);
    this->voyantRouge = new DigitalOut(pinVoyantRouge);
    this->clePbAlim = false;
}

void Signalisation::signalerChargeBatterie(){
    this->voyantVert->on();
}

void Signalisation::finSignalerChargeBatterie(){
    this->voyantVert->off();
}




void Signalisation::signalerPbAlim(){
    while(this->clePbAlim == false){
        this->voyantJaune->on();
        usleep(250000); //0.25s
        this->voyantJaune->off();
        usleep(250000); //0.25s
    }
}

void Signalisation::finSignalerPbAlim(){
    this->clePbAlim = true;
}

thread Signalisation::tSignalerPbAlim(){
    return thread([this]{
            signalerPbAlim();
    });
}



void Signalisation::signalerPbSecurite(){
    this->voyantRouge->on();
}

void Signalisation::finSignalerPbSecurite(){
    this->voyantRouge->off();
}


/*void Signalisation::miseEnMouvement(){
    while(true){
        this->voyantVert->on();
        usleep(500000); //0.5s
        this->voyantVert->off();
        usleep(500000); //0.5s
    }
}*/

/*void Signalisation::finMiseEnMouvement(){
    this->voyantVert->off();
}*/




















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


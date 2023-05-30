#include "../include/Moteur.h"
#include <iostream>

using namespace GPIO;
using namespace std;

Moteur::Moteur(unsigned int pinEnable, unsigned int pinPhase, unsigned int periode, unsigned int rapportCyclique){ //unsigned short int est codé sur 2 octets, enable et phase sont le numéro des pins utilisées
    this->objPhase = new DigitalOut(pinPhase); //objet permettant de changer le sens de rotation du moteur, prend en argument la pin
    this->objEnablePWM = new PWMOut(pinEnable); //objet permettant de contrôller le PWM moteur, prend en argument la pin
    this->objEnablePWM->set_range(periode); //range = période du signal (précision du PWM)
    this->rapportCyclique = rapportCyclique; //attribut ratio
}

Moteur::~Moteur(){
    delete this->objPhase;
    delete this->objEnablePWM;
}

//1000000000
void Moteur::tournerHoraire(unsigned int rapportCyclique){ //fais tourner le moteur dans un sens avec l'attribut ratio
    if(this->estEnMouvement == false){ //si le plateau n'est pas en mouvement
        this->estEnMouvement = true; //le plateau est en mouvement
        this->objPhase->on(); //allumer phase (sens rotation)
        this->objEnablePWM->set_ratio(rapportCyclique);
    }
    else{
        this->objEnablePWM->set_ratio(0);
        usleep(100000);
        this->estEnMouvement = true; //le plateau est en mouvement
        this->objPhase->on(); //allumer phase (sens rotation)
        this->objEnablePWM->set_ratio(rapportCyclique);
    }
}

void Moteur::tournerAntiHoraire(unsigned int rapportCyclique){ //fais tourner le moteur dans l'autre sens avec l'attribut ratio
    if(this->estEnMouvement == false){  
        this->estEnMouvement = true; //le plateau est en mouvement
        this->objPhase->off(); //éteindre phase (sens rotation) 
        this->objEnablePWM->set_ratio(rapportCyclique);
    }
    else{
        this->objEnablePWM->set_ratio(0);
        usleep(100000);
        this->estEnMouvement = true; //le plateau est en mouvement
        this->objPhase->off(); //éteindre phase (sens rotation) 
        this->objEnablePWM->set_ratio(rapportCyclique);
    }
}

void Moteur::arretMoteur(){ //eteint phase et enable
    this->estEnMouvement = false;
    this->objEnablePWM->set_ratio(0); //objet objEnablePWM éteint, ratio 0
    this->objEnablePWM->set_range(0); //objet objEnablePWM éteint, range 0
    this->objPhase->off(); //objet objPhase éteint
}

void Moteur::modifierEtatPhase(bool etat){ //modifie l'état de phase
    etat ? this->objPhase->on() : this->objPhase->off();
}

void Moteur::modifierValeurRatio(unsigned int ratio){ //modifie la valeur du ratio du PWM, voir si le traitement pour estEnMouvement est à faire ici ?
    this->rapportCyclique = rapportCyclique;
    this->objEnablePWM->set_ratio(rapportCyclique);
    if(rapportCyclique != 0){ //si le PWM n'est pas nul
        this->estEnMouvement = true;
    }
    else{ //si le PWM est nul
        this->estEnMouvement = false;
    }
}

bool Moteur::getEstEnMouvement(){ //getter de l'attribut estEnMouvement
    return this->estEnMouvement;
}

void Moteur::setEstEnMouvement(bool etat){ //setter setEstEnMouvement, pas vraiment utile
    this->estEnMouvement = etat;
}

int Moteur::getRatio(){ //getter de l'attribut ratio, pas vraiment utile
    return this->rapportCyclique;
}

void Moteur::setRatio(unsigned int rapportCyclique){ //setter de l'attribut ratio, pas vraiment utile
    this->rapportCyclique = rapportCyclique;
}
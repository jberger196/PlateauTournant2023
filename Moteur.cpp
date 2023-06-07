#include "../include/Moteur.h"
#include <signal.h>


using namespace GPIO;


Moteur::Moteur(unsigned int pinPWM, unsigned int pinSensMoteur, unsigned int periode){ //unsigned short int est codé sur 2 octets, enable et phase sont le numéro des pins utilisées

    this->objPhase = new DigitalOut(pinSensMoteur); //objet permettant de changer le sens de rotation du moteur, prend en argument la pin
    this->objEnablePWM = new PWMOut(pinPWM); //objet permettant de contrôller le PWM moteur, prend en argument la pin
    if ((periode-2<1024) && (periode-2>0)) //
    {
        this->periode = periode -2;
    }
    else {
        this->periode = 5;
    }
    this->objEnablePWM->set_range(periode); //range = rapport de division à partir duquel la période est calculée
    this->ratio = 0; //attribut ratio
}

Moteur::~Moteur(){
    delete this->objPhase;
    delete this->objEnablePWM;
}

void Moteur::tournerHoraire(unsigned int rapportCyclique){ //fais tourner le moteur dans un sens avec le paramètre rapportCyclique
    this->ratio = (rapportCyclique* this->periode)/100 ;
    this->objEnablePWM->set_range(this->periode);
    if(this->estEnMouvement == true){ //si le plateau est déja en mouvement (probleme)
        this->objEnablePWM->set_ratio(0);
        this->estEnMouvement = true;
        usleep(100000); //attendre 0.1s
    }
    this->estEnMouvement = true; //le plateau est en mouvement
    this->modifierSensMoteur(true); //allumer phase (sens rotation)
    for(unsigned int valRatio = 1; valRatio <= this->ratio; valRatio++){ //augmentation progressive de la vitesse moteur (augmentation progressive PWM)
        this->objEnablePWM->set_ratio(valRatio);
        usleep(10000); //augmentation du PWM toutes les 10ms, 10*valRatioms d'augmentation de la PWM au total
    }
}

void Moteur::tournerAntiHoraire(unsigned int rapportCyclique){ //fais tourner le moteur dans l'autre sens avec l'attribut ratio
    this->ratio = (rapportCyclique* this->periode)/100 ;
    this->objEnablePWM->set_range(this->periode);
    if(this->estEnMouvement == true){ //si le plateau est déja en mouvement (probleme)
        this->objEnablePWM->set_ratio(0);
        this->estEnMouvement = false;
        usleep(100000); //attendre 0.1s
    }
    this->estEnMouvement = true; //le plateau est en mouvement
    this->modifierSensMoteur(false); //changer de sens rotation, eteindre phase (sens rotation)
    for(unsigned int valRatio = 1; valRatio <= this->ratio; valRatio++){ //augmentation progressive de la vitesse moteur (augmentation progressive PWM)
        this->objEnablePWM->set_ratio(valRatio);
        usleep(10000); //augmentation du PWM toutes les 10ms, 10*valRatioms d'augmentation de la PWM au total
    }
}

void Moteur::arretMoteur(){ //eteint phase et enable
    this->estEnMouvement = false;
    this->objEnablePWM->set_ratio(0); //objet objEnablePWM éteint, ratio 0
    this->objEnablePWM->set_range(0); //objet objEnablePWM éteint, range 0
    this->objPhase->off(); //objet objPhase éteint
}

/*void Moteur::fonction(){
    signal(SIGUSR1, Moteur::arretUrgence);
}*/

void Moteur::arretUrgence(){
    for(unsigned int valRatio = this->ratio; valRatio >= 0; valRatio--){ //augmentation progressive de la vitesse moteur (augmentation progressive PWM)
        this->objEnablePWM->set_ratio(valRatio);
        usleep(100000); //augmentation du PWM toutes les 10ms, 10*valRatioms d'augmentation de la PWM au total
    }
}

void Moteur::modifierSensMoteur(bool etat){ //modifie l'état de phase
    etat ? this->objPhase->on() : this->objPhase->off();
}

bool Moteur::getEstEnMouvement(){ //getter de l'attribut estEnMouvement
    return this->estEnMouvement;
}

void Moteur::setEstEnMouvement(bool etat){ //setter setEstEnMouvement, pas vraiment utile
    this->estEnMouvement = etat;
}

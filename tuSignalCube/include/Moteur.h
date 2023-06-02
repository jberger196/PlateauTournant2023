
#ifndef __Moteur_h__
#define __Moteur_h__

#include "cppgpio/output.hpp"

using namespace GPIO;

class Moteur{
    public:
      Moteur(unsigned int pinEnable=27, unsigned int pinPhase=17, unsigned int range = 1024, unsigned int ratio = 0);
      ~Moteur();
      void tournerHoraire(unsigned int ratio); //fais tourner le moteur dans un sens avec l'attribut ratio
      void tournerAntiHoraire(unsigned int ratio); //fais tourner le moteur dans l'autre sens avec l'attribut ratio
      void arretMoteur(); //eteint phase et enable
      void modifierEtatPhase(bool etat); //modifie l'état de phase
      void modifierValeurRatio(unsigned int ratio); //modifie la valeur du ratio du PWM
      bool getEstEnMouvement(); //getter de l'attribut estEnMouvement
      void setEstEnMouvement(bool etat); //setter setEstEnMouvement, pas vraiment utile
      int getRatio(); //getter de l'attribut ratio, pas vraiment utile
      void setRatio(unsigned int ratio); //setter de l'attribut ratio, pas vraiment utile
    
    private:
        bool estEnMouvement;
        DigitalOut* objPhase;
        PWMOut* objEnablePWM;
        unsigned int range;
        unsigned int ratio;
};

#endif

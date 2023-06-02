#include "cppgpio/output.hpp"
#include <unistd.h>

using namespace GPIO;

class Moteur2{
    public:
      Moteur2(unsigned int pinPWM, unsigned int pinSensMoteur, unsigned int periode = 1024);
      ~Moteur2();
      void tournerHoraire(unsigned int rapportCyclique); //fais tourner le moteur dans un sens avec l'attribut ratio
      void tournerAntiHoraire(unsigned int rapportCyclique); //fais tourner le moteur dans l'autre sens avec l'attribut ratio
      void arretMoteur(); //eteint phase et enable
      void modifierSensMoteur(bool etat); //modifie l'état de phase
      void modifierValRapportCyclique(unsigned int rapportCyclique); //modifie la valeur du ratio du PWM
      bool getEstEnMouvement(); //getter de l'attribut estEnMouvement
      void setEstEnMouvement(bool etat); //setter setEstEnMouvement, pas vraiment utile
      int getRatio(); //getter de l'attribut ratio, pas vraiment utile
      void setRatio(unsigned int rapportCyclique); //setter de l'attribut ratio, pas vraiment utile
    
    private:
        bool estEnMouvement;
        DigitalOut* objPhase;
        PWMOut* objEnablePWM;
        unsigned int periode;
        unsigned int ratio;
};

#include "cppgpio/output.hpp"
#include <unistd.h>

using namespace GPIO;

class Moteur{
    public:
      Moteur(unsigned int pinEnable, unsigned int pinPhase, unsigned int periode = 1024, unsigned int rapportCyclique = 0);
      ~Moteur();
      void tournerHoraire(unsigned int rapportCyclique); //fais tourner le moteur dans un sens avec l'attribut ratio
      void tournerAntiHoraire(unsigned int rapportCyclique); //fais tourner le moteur dans l'autre sens avec l'attribut ratio
      void arretMoteur(); //eteint phase et enable
      void modifierEtatPhase(bool etat); //modifie l'état de phase
      void modifierValeurRatio(unsigned int rapportCyclique); //modifie la valeur du ratio du PWM
      bool getEstEnMouvement(); //getter de l'attribut estEnMouvement
      void setEstEnMouvement(bool etat); //setter setEstEnMouvement, pas vraiment utile
      int getRatio(); //getter de l'attribut ratio, pas vraiment utile
      void setRatio(unsigned int rapportCyclique); //setter de l'attribut ratio, pas vraiment utile
    
    private:
        bool estEnMouvement;
        DigitalOut* objPhase;
        PWMOut* objEnablePWM;
        unsigned int periode;
        unsigned int rapportCyclique;
};


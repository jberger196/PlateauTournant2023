#include "cppgpio/output.hpp"

using namespace GPIO; //vert 9, jaune 11, rouge 24

class Signalisation{
    public:
        Signalisation(int pinVoyantVert, int pinVoyantJaune, int pinVoyantRouge);
        bool getOn_off();
        void setOn_off();

        /*void signalerProblemeBatterie();
        void finProblemeBatterie();

        void chargeBatterie();
        void finChargeBatterie();

        void miseEnMouvement();
        void finMiseEnMouvement();

        void arretUrgence();
        void finArretUrgence();

        void absenceCube();
        void finAbsenceCube();

        void pasAlim();
        void finPasAlim();


        void allumerJaune();
        void allumerRouge();

        void eteindreVert();
        void eteindreJaune();
        void eteindreRouge();

        void clignoterVert();
        void clignoterJaune();
        void clignoterRouge();*/
    
    private:
        bool on_off;
        /*DigitalOut* voyantVert;
        DigitalOut* voyantJaune;
        DigitalOut* voyantRouge;*/

        PWMOut* voyantVert;
        PWMOut* voyantJaune;
        PWMOut* voyantRouge;
};
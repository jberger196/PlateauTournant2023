#include "../include/C_CourantMoteur.hpp"

C_courantMoteur::C_courantMoteur() {
        float SHUNT_OHMS = 0.1;
        float MAX_EXPECTED_AMPS = 3.2;
        //float INTERVAL = 10.0;
        capteur = new INA219(SHUNT_OHMS, MAX_EXPECTED_AMPS);
        capteur -> configure(RANGE_16V, GAIN_8_320MV, ADC_12BIT, ADC_12BIT);
}

C_courantMoteur::~C_courantMoteur() {
        delete capteur;
}

float C_courantMoteur::getReleve() {
        return releve;
}

void C_courantMoteur::lire() { 
        releve = capteur -> current();
}
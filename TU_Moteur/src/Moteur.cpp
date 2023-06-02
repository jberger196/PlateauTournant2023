#include <iostream>
#include "../include/Moteur.h"

using namespace std;
using namespace GPIO;

Moteur::Moteur() {
}
void Moteur::tournerG(){
    sleep->on();
    direction->on();
    speed->on(std::chrono::nanoseconds (200000000));
}

void Moteur::tournerD(){
    sleep->on();
    direction->off();
    speed->on(std::chrono::nanoseconds (200000000));
}

void Moteur::veille(){
    sleep->off();
}

void Moteur::nveille(){
    sleep->on();
}

void Moteur::eteindre(){
    speed->off();
}

Moteur::~Moteur() {
    
}
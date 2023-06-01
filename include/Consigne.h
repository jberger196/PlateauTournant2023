#include <exception>
using namespace std;

#ifndef __Consigne_h__
#define __Consigne_h__

class Consigne
{
private:
	float seuilPresence;
    float seuilAbscence;
    int ValMinMot;
    int ValMaxMot;
    float seuilCourantChargeValide;
    float seuilCourantChargeInvalide;

public:
    Consigne();
	bool lireConsignes();
    bool obtenirSeuilCourantMoteur();
    bool obtenirSeuilsPresence(float& seuilMin ,float& seuilMax);
	float getSeuilmin();
    float getSeuilmax();	
    void setValMinMot(int val);
    void setValMaxMot(int val);
    int getValMinMot();
    int getValMaxMot();
    float getSeuilCourantChargeValide();
    float getSeuilCourantChargeInvalide();
    ~Consigne();

};

#endif 	
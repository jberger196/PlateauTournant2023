#include <exception>
#include "../include/PlateauTournant.h"

PlateauTournant::PlateauTournant()
{
    _leSegmentVol = new Cube();
    _laSecurite = new Cerbere();
    _lOperation = new Ares();
    _lesConsignes = new Consigne();
    _lessignalements = new Signalement();
	leJournal = new Journal();
	estEnMouvementHoraire = false;
	estEnMouvementAntiHoraire = false;	   
}
PlateauTournant::~PlateauTournant()
{
}
void PlateauTournant::tournerHoraire()
{
	estEnMouvementHoraire = true;	
	estEnMouvementAntiHoraire = false;
	throw "Not yet implemented"; 
	_laSecurite->setFinRotation(false); 
		_laSecurite->verifierCourant();  
			   
}
void PlateauTournant::tournerAntiHoraire()
{
	estEnMouvementHoraire = false;	
	estEnMouvementAntiHoraire = true;
	throw "Not yet implemented";   
	_laSecurite->setFinRotation(false); 
	_laSecurite->verifierCourant();      
}
void PlateauTournant::immobiliser()
{
	estEnMouvementHoraire = false;	
	estEnMouvementAntiHoraire = false	   
	throw "Not yet implemented";   
	_laSecurite->setFinRotation(true);   
}
void PlateauTournant::signalerProbleme(int code)
{
	throw "Not yet implemented"; 
}
Cerbere *PlateauTournant::getCerbere()
{
}
Cube *PlateauTournant::getCube()
{
}
Ares *PlateauTournant::getAres()
{
}
Consigne *PlateauTournant::getConsigne()
{
}
Signalement *PlateauTournant::getSignalement()
{
}
void PlateauTournant::setCerbere(Cerbere *_laSecurite)
{
}
void PlateauTournant::setCube(Cube *_leSegmentVol)
{
}
void PlateauTournant::setAres(Ares *_lOperation)
{
}
void PlateauTournant::setConsigne(Consigne *_lesConsignes)
{
}
void PlateauTournant::setSignalement(Signalement *_lessignalements)
{
}
bool PlateauTournant::getEstEnMouvementHoraire()
{
    return estEnMouvementHoraire;
}
bool PlateauTournant::getEstEnMouvementAntiHoraire()
{
    return estEnMouvementAntiHoraire;
}
#include <exception>
#include <string>
using namespace std;

#ifndef __Journal_h__
#define __Journal_h__

class Journal
{
	private: string _cheminBDD;

	public: void enregistrer(float aCourantMoteur, string aHeureDate);

	public: int enregistrerEvenement(string aTypeEvenement, float aValeur, string aHeureDate);

	private: void insererBDD();

	public: Journal(string aCheminBDD);

	public: void enregistrerFinEvenement(string aType, string aHeurDate);

	public: void enregsitrerDonneesBatterie(float aCourant, float aTension, string aHeureDate);
};

#endif
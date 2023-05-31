
#ifndef __Cube_h__
#define __Cube_h__

// #include "PlateauTournant.h"
// #include "Batterie.h"
// #include "SignalCube.h"

class Cube
{
	private: bool _present;
	private: bool _fixe;
	public: PlateauTournant* _lePlateau;
	private: Batterie* _laBatterie;
	private: SignalCube* _lesSignaux;
};

#endif
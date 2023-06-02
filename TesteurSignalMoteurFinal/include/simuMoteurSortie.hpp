#ifndef __Simu_moteur_sortie_HPP
#define __Simu_moteur_sortie_HPP


#include "cppgpio.hpp" // Inclure la bibliothèque C++ pour les GPIO


class simuMoteurSortie
{
    public:
    
    simuMoteurSortie(bool signal1,bool signal2);

    ~simuMoteurSortie(void);
}
;

#endif //__Simu_moteur_sortie_HPP
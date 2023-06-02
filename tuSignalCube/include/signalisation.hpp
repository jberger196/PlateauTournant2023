#ifndef __SIGNALISATION_HPP
#define __SIGNALISATION_HPP

#ifndef __Signalement_h__
#define __Signalement_h__

// #include "PlateauTournant.h"  (en intégrer une fois concu)

class PlateauTournant;
class Signalement;

class Signalement
{
private:
    bool _alerteMoteur;
    bool _alerteBatterie;
    bool _alerteFixation;
    bool _alertePresence;

public:
    PlateauTournant *_unnamed_PlateauTournant_;

    bool getAlerteMoteur();
    void setAlerteMoteur(bool aAlerteMoteur);

    bool getAlerteBatterie();
    void setAlerteBatterie(bool aAlerteBatterie);
    
    bool getAlerteFixation();
    void setAlerteFixation(bool aAlerteFixation);

    bool getAlertePresence();
    void setAlertePresence(bool aAlertePresence);

    void signalerProbleme();
};

#endif

#endif // __SIGNALISATION_HPP
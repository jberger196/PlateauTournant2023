#include "../include/cppgpio.hpp" // Inclure la bibliothèque C++ pour les GPIO
#include <iostream>    // Inclure la bibliothèque pour l'affichage en console
#include <unistd.h>    // Inclure la bibliothèque pour la fonction sleep

using namespace std;
using namespace GPIO;

int main()
{
    short modeSignal;
    short hautBas;
    short reponseMode;
    short reponseMoteur;

    DigitalOut sensMoteur(19);
    DigitalOut rotaMoteur(18);

    while (true)
    {

        cout << " entrez 1 pour vérifier simplement le signal la présence des signaux, 0 pour simuler des signaux moteur." << endl;
        cin >> modeSignal;
        cout << "_____________________________________________________________________________________________" << endl;
        cout << "_____________________________________________________________________________________________" << endl;

        if (modeSignal == 1)
        {
            cout << "entre 1 pour alimenter les sorties, 0 pour les rendre inactives" << endl;
            cin >> hautBas;
            cout << "_____________________________________________________________________________________________" << endl;
            cout << "_____________________________________________________________________________________________" << endl;
            if (hautBas == 1)
            {
                cout << "sorties alimentés" << endl;
                sensMoteur.on();
                rotaMoteur.on();
                cout << "_____________________________________________________________________________________________" << endl;
                cout << "_____________________________________________________________________________________________" << endl;
            }

            else if (hautBas == 0)
            {
                cout << "sorties inactives" << endl;
                sensMoteur.off();
                rotaMoteur.off();
                cout << "_____________________________________________________________________________________________" << endl;
                cout << "_____________________________________________________________________________________________" << endl;
            }
            else
            {
                cout << "entrez une reponse valide" << endl;
                cout << "_____________________________________________________________________________________________" << endl;
                cout << "_____________________________________________________________________________________________" << endl;
            }
        }
        else if (modeSignal == 0)
        {

            cout << " entrez 1 pour mettre en rotation le moteur, 0 pour simuler une panne ou 2 pour remettre les sorties à 0." << endl;
            cin >> reponseMode;
            cout << "_____________________________________________________________________________________________" << endl;
            cout << "_____________________________________________________________________________________________" << endl;

            if (reponseMode == 1)
            {
                cout << " entrez 1 pour tourner dans le sense horaire, O pour le sens anti horaire " << endl;
                cin >> reponseMoteur;
                cout << "_____________________________________________________________________________________________" << endl;
                cout << "_____________________________________________________________________________________________" << endl;

                if (reponseMoteur == 1)
                {

                    cout << "mise en rotation horaire" << endl;
                    sensMoteur.on();
                    rotaMoteur.on(std::chrono::nanoseconds(200000000));
                    cout << "_____________________________________________________________________________________________" << endl;
                    cout << "_____________________________________________________________________________________________" << endl;
                }
                else if (reponseMoteur == 0)
                {

                    cout << "mise en rotation anti horaire" << endl;
                    sensMoteur.off();
                    rotaMoteur.on(std::chrono::nanoseconds(200000000));
                    cout << "_____________________________________________________________________________________________" << endl;
                    cout << "_____________________________________________________________________________________________" << endl;
                }
                else
                {
                    cout << "entrez une reponseMoteur valide" << endl;
                    cout << "_____________________________________________________________________________________________" << endl;
                    cout << "_____________________________________________________________________________________________" << endl;
                }
            }
            else if (reponseMode == 0)
            {
                for (int i = 0; i < 5; i++)
                {
                    sensMoteur.off();
                    rotaMoteur.on(std::chrono::nanoseconds(200000000));
                }
            }
            else if (reponseMode == 2)
            {
                sensMoteur.off();
                rotaMoteur.off();
                cout << "sorties a 0" << endl;
                cout << "_____________________________________________________________________________________________" << endl;
                cout << "_____________________________________________________________________________________________" << endl;
            }
            else
            {
                cout << "entrez une reponse valide" << endl;
                cout << "_____________________________________________________________________________________________" << endl;
                cout << "_____________________________________________________________________________________________" << endl;
            }
        }
        else
        {
            cout << "entrez une reponse valide" << endl;
            cout << "_____________________________________________________________________________________________" << endl;
            cout << "_____________________________________________________________________________________________" << endl;
        }
    }
}
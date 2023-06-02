#include "../include/cppgpio.hpp"
#include <thread>
#include <iostream>

using namespace GPIO;
using namespace std;

int main() {
  // Initialisation de la broche GPIO pour la LED GPIO23 est une led verte du module audio
  DigitalOut led(23);

  int reponse = 0;
    
while(1){
    cout << "entrer 0 pour éteindre la led 1 pour l'allumer" << endl;
    cin >> reponse;

    if (reponse == 0){
      led.off(); 
      cout << "Led éteinte" << endl;
      cout << "-----------" << endl;

    }
    else if (reponse == 1){
     led.on(); 
     cout << "Led allumée" << endl;
     cout << "-----------" << endl;

    }
}
  return 0;
}
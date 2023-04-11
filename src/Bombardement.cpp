#include "../include/Bombardement.h"

////////////////////////// inclusion à supprimer pour application
#include <iostream>
#include "../include/cppgpio.hpp"

using namespace std;
/////////////////////////////////////////////////////



Bombardement::~Bombardement(void)
{
}

void Bombardement::triggered(unsigned int gpio)
{
    // check if this is really a new event, or still a bouncing switch

    if (!m_pin.triggered()) return;
    
    // now call the virtual functions to trigger some action

    if (m_pin.get_state()) {

		///////////////////// Code à modifier
		DigitalOut phase(5);
		DigitalOut enable(12);
		DigitalOut pause(6);

		pause.off();
		phase.on();
		enable.on();

		pause.on();
		cout<<"pause == on"<<endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		pause.off();
			cout<<"pause == off"<<endl;
		///////////////////////////////

    }
    

}
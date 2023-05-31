#include "ina219.h"
#include <iostream>
#include <unistd.h> // for usleep

int main()
{
    // Create a new INA219 object with a shunt resistance of 0.1 ohms
    // and a maximum expected current of 2 amps
    INA219 ina219(0.1, 2.0);
    
    // Set the ADC resolution to 12-bit and the conversion time to 532us
    ina219.configure(RANGE_16V,GAIN_8_320MV,ADC_12BIT,ADC_12BIT);
    
    while (true)
    {
        // Read the bus voltage (in volts)
        float bus_voltage = ina219.voltage();
        std::cout << "Bus Voltage: " << bus_voltage << " V" << std::endl;
        
        // Read the shunt voltage (in volts)
        float shunt_voltage = ina219.shunt_voltage() / 1000.0;
        std::cout << "Shunt Voltage: " << shunt_voltage << " V" << std::endl;
        
        // Read the current (in amps)
        float current = ina219.current() / 1000.0;
        std::cout << "Current: " << current << " A" << std::endl;
        
        // Read the power (in watts)
        float power = ina219.power();
        std::cout << "Power: " << power << " mW" << std::endl;
        
        // Wait for 1 second before taking another measurement
        usleep(1000000);
    }
    
    return 0;
}
   

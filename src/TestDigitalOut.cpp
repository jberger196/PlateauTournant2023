#include <iostream>     
#include "../include/cppgpio/output.hpp"

using namespace GPIO ;

int main()
{
    DigitalOut monDigitalOut(23);

    char reponse = 'n';
    while (true)
    {
    std::cout <<"Voulez vous alimenter ? o/n" <<std::endl;
    std::cin>>reponse;
    if(reponse == 'o')
        monDigitalOut.on();

    else
        monDigitalOut.off();
    }
    return 0;
}
                          
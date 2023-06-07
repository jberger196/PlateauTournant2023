#include "../include/Signalisation.h"
#include <unistd.h>

Signalisation::Signalisation(int pinVoyantVert, int pinVoyantJaune, int pinVoyantRouge)
{
	this->voyantVert = new DigitalOut(pinVoyantVert);
	this->voyantJaune = new DigitalOut(pinVoyantJaune);
	this->voyantRouge = new DigitalOut(pinVoyantRouge);
	this->clePbAlim = false;
}

void Signalisation::signalerChargeBatterie()
{
	this->voyantVert->on();
}

void Signalisation::finSignalerChargeBatterie()
{
	this->voyantVert->off();
}

void Signalisation::signalerPbAlim()
{
	while (this->clePbAlim == false)
	{
		this->voyantJaune->on();
		usleep(250000); // 0.25s
		this->voyantJaune->off();
		usleep(250000); // 0.25s
	}
}

void Signalisation::finSignalerPbAlim()
{
	this->clePbAlim = true;
}

thread Signalisation::tSignalerPbAlim()
{
	return thread([this]
				  { signalerPbAlim(); });
}

void Signalisation::signalerPbSecurite()
{
	this->voyantRouge->on();
}

void Signalisation::finSignalerPbSecurite()
{
	this->voyantRouge->off();
}

void Signalisation::signalerMiseEnMouvement()
{
	this->voyantVert->on();
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
	this->voyantJaune->on();
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
	this->voyantRouge->on();
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
}

void Signalisation::finirMiseEnMouvement()
{
	this->voyantVert->off();
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
	this->voyantJaune->off();
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
	this->voyantRouge->off();
}

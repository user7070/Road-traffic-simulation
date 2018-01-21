#pragma once
#include "Fahrzeug.h"
class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad();
	Fahrrad(string name, double maxspeed);
	virtual ~Fahrrad();
	double dTankken(double dMenge); //macht kein, deswegen return 0.0 
    void vAbfertigung();
    double dGechwindigkeit();
    void  vAusgabe();
};


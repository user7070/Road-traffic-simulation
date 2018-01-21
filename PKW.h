#pragma once
#include "Fahrzeug.h"
class PKW :
	public Fahrzeug
{
public:

	PKW(); //standard Konstruktor
	PKW(string name, double maxspeed, double verbrauch, double tankvolume); //zweite konstruktor
	PKW(string name, double maxspeed);
	virtual ~PKW(); // destruktor 
	double dVerbrauch(); //besherigen gesmatverbrauch ermittelt 
    double dTankken(double dMenge = -1); //nachträglichen betanken des PKW warum -1 weil macht kein sin 0 lites zu addieren und zuvolltanken
	void vAbfertigung();  //actulaisierung von tankeninhalt
    void  vAusgabe(); //pkw data ausgeben
    double dGechwindigkeit();

private:
	double p_dVerbrauch; //verbrauch/ 100 km
	double p_dTankinhalt; // in litres
	double p_dtankvolumen; //55litres falls nicht anderes inialisiert 

};


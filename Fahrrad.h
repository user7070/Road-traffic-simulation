#pragma once
#include "Fahrzeug.h"

class Wege;

class Fahrrad :
	public Fahrzeug
{
public:

	//konstructors and destructor
	Fahrrad();
	Fahrrad(string name, double maxspeed);
	 virtual ~Fahrrad();

	//functions f�r tanken und abfertigung und geschwindikeit abnahme
	double dTankken(double dMenge);   
    void vAbfertigung();
    double dGechwindigkeit();

	//ausgabe functions
    void  vAusgabe();
	ostream& ostreamAusgabe(ostream& ausgabe);

	//eingabe function 
	virtual istream& istreamEingabe(istream& eingabe);

	//draw fahhrad auf dem strasse
	virtual void vZeichnen(Wege*);
};


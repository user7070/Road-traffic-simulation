#pragma once
#include "Fahrzeug.h"

class Wege;
class FzgVerhalten;

class PKW :
	public Fahrzeug
{
public:

	//konstructors and destrcutor 
	PKW(); 
	PKW(string name, double maxspeed);
	PKW(string name, double maxspeed, double verbrauch, double tankvolume); 
	virtual ~PKW(); 

	//Functions fur tanken, geschwindikeit, abfertigen und verbrauch ermittlen
	double dVerbrauch(); 
    virtual  double dTankken(double dMenge = -1); 
	void vAbfertigung();  
	virtual double dGechwindigkeit();

	//Ausgabe functions
    void  vAusgabe();
	ostream& ostreamAusgabe(ostream& ausgabe);

	//eingabe function 
	virtual istream& istreamEingabe(istream& eingabe);

	//Pkw zeichnen
	virtual void vZeichnen(Wege* wegger) ;

private:

	double p_dVerbrauch; 
	double p_dTankinhalt; 
	double p_dtankvolumen;
	

};


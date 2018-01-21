#include "PKW.h"
#include "FzgVerhalten.h"
#include "Wege.h"
#include "FzgFahren.h"
#include "FzgParken.h"


PKW::PKW() : Fahrzeug()
{
	p_dtankvolumen = 55.00;
	p_dTankinhalt = 0.5*p_dtankvolumen;
	p_dVerbrauch = 0.0;
}

PKW::PKW(string name,double maxspeed,double verbrauch,double tankvolume):Fahrzeug(name,maxspeed),p_dVerbrauch(verbrauch),p_dtankvolumen(tankvolume)
{
	p_dTankinhalt = 0.5* p_dtankvolumen;
}

PKW::PKW(string name, double maxspeed) : Fahrzeug(name, maxspeed)
{
	
}

PKW::~PKW()
{
}

double PKW::dVerbrauch()
{
	double verbrauch =  ((p_dVerbrauch / 100)* p_dGesamtStrecke);
	return verbrauch;
}

double PKW::dTankken(double dMenge)
{
	double dEmpty = p_dtankvolumen - p_dTankinhalt;
	if ( dMenge > dEmpty )
	{
		p_dTankinhalt = p_dtankvolumen;
			return dEmpty;
	}
	else if ( dMenge <= dEmpty)
	{
		p_dTankinhalt = p_dTankinhalt + dMenge;
		return dMenge;
	}
	else p_dTankinhalt = p_dtankvolumen;
	return  dEmpty ;
}

void PKW::vAbfertigung()
{
	if (p_dTankinhalt > 0.0)
	{
		double strecke = p_dGesamtStrecke;

		Fahrzeug::vAbfertigung();

		double dNewStrecke = p_dGesamtStrecke - strecke; //strecker zeit dem letzeten abfertigung
		p_dTankinhalt = p_dTankinhalt - dNewStrecke* (p_dVerbrauch / 100); //aktualiqierung von tank inhalt 
		if (p_dTankinhalt < 0.0)
		{
			p_dTankinhalt = 0.0;
		}
	}
	else
	{
		p_dTankinhalt = 0.0;
		Fahrzeug::vAbfertigung();
	}
}

void PKW::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << fixed << setw(20) << setiosflags(ios::left) << dVerbrauch()
	 	 << setw(10) << resetiosflags(ios::left) << setiosflags(ios::left) << p_dTankinhalt << endl;
}

double PKW::dGechwindigkeit()
{
	if (p_dTankinhalt <= 0.0 )
	{
		return  0;
	}

	double gechwindikeit = p_dMaxGechwindikeit;

	if (p_pverhalten == NULL) { return gechwindikeit; }  // if verhalten ist NULL return max speed

	double speed = p_pverhalten->getweg()->getlimit(); //read the road limit
	
	//check the road Limit 
	if (speed == 50)   { gechwindikeit = 50; }
	if (speed == 100)  { gechwindikeit = 100; }
	if (speed == -1)   { gechwindikeit = p_dMaxGechwindikeit; }

		return gechwindikeit;
}

ostream & PKW::ostreamAusgabe(ostream & ausgabe)
{
	Fahrzeug::ostreamAusgabe(ausgabe);
	ausgabe << fixed << setw(20) << setiosflags(ios::left) << dVerbrauch()
	    	<< setw(10) << resetiosflags(ios::left) << setiosflags(ios::left) << p_dTankinhalt << endl;
	return ausgabe;
}

istream & PKW::istreamEingabe(istream & eingabe)
{
	// TODO: hier Rückgabeanweisung eingeben
	Fahrzeug::istreamEingabe(eingabe);
	eingabe >> p_dVerbrauch;
	eingabe >> p_dtankvolumen;
	return eingabe;
}

void PKW::vZeichnen(Wege * wegger) 
{
	double RelPosition = p_dAbschnittStrecke / wegger->Getlenght(); //position between 0--1

	if( RelPosition >= 1)
	{
		RelPosition = 1;
	}

	//call draw function from simuclient
	bZeichnePKW( p_sName , wegger->getName(),  RelPosition , dGechwindigkeit() ,p_dTankinhalt) ;

}

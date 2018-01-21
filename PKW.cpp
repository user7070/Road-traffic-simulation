#include "PKW.h"



PKW::PKW()
{
	p_dtankvolumen = 55.00;
	p_dTankinhalt = 0.5*p_dtankvolumen;
	p_dVerbrauch = 0.0;

}

PKW::PKW(string name, double maxspeed, double verbrauch, double tankvolume) : Fahrzeug(name, maxspeed ), p_dVerbrauch (verbrauch) , p_dtankvolumen(tankvolume)
{
	p_dTankinhalt = 0.5* p_dtankvolumen;
}

PKW::PKW(string name, double maxspeed)
{
	p_sName = name;
	p_dMaxGechwindikeit = maxspeed;
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
	if ( dMenge == -1 )
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
	else
	{
		return p_dMaxGechwindikeit;
	}	
}

#include "Fahrrad.h"
#include "Wege.h"

Fahrrad::Fahrrad() : Fahrzeug()
{
}

Fahrrad::Fahrrad(string name, double maxspeed) :Fahrzeug(name, maxspeed)
{
	
}

Fahrrad::~Fahrrad()
{
}

double Fahrrad::dTankken(double dMenge)
{
	return 0.0;   //fahhrad hat kein tank
}

void Fahrrad::vAbfertigung()
{
	Fahrzeug::vAbfertigung();
}
double Fahrrad::dGechwindigkeit()
{
	
	int pDiv = int(p_dGesamtStrecke / 20);  // takes the integer of a double 

		double pNewSpeed = p_dMaxGechwindikeit * pow(0.9, pDiv); // 10% abnehmen => speed * 9/10  power of pdiv each time pdiv augments
		if (pNewSpeed <12.00)
		{
			pNewSpeed = 12.00;
		}
		return pNewSpeed;
}
void Fahrrad::vAusgabe()
{	
	Fahrzeug::vAusgabe();
	cout << fixed << setw(15) << setiosflags(ios::left) << p_dMaxGechwindikeit << endl;	

}
ostream & Fahrrad::ostreamAusgabe(ostream & ausgabe)
{
	Fahrzeug::ostreamAusgabe(ausgabe);
	ausgabe << fixed << setw(15) << setiosflags(ios::left) << p_dMaxGechwindikeit << endl;
	return ausgabe;
}

void Fahrrad::vZeichnen(Wege* weg) 
{
	double RelPosition = p_dAbschnittStrecke / weg->Getlenght();   //position between 0--1

	if (RelPosition > 1)
	{
		RelPosition = 1;
	}


	//call draw function from simuclient
	bZeichneFahrrad( p_sName, weg->getName(), RelPosition, dGechwindigkeit());
}

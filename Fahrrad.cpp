#include "Fahrrad.h"



Fahrrad::Fahrrad()
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
	return 0.0;
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

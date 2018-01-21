
#include "Losfahren.h"
#include "Fahrzeug.h"
#include "Wege.h"
#include <string>

Losfahren::Losfahren() :FahrAusname()
{
}

Losfahren::Losfahren(Fahrzeug * fahr, Wege* weg) : FahrAusname(fahr,weg)
{
	
}

Losfahren::~Losfahren()
{
}


void Losfahren::vBearbeiten()
{
	p_weg->vAbgabe( p_fahrzeug);  //delet the car from list 
	p_weg->vAnnahme(p_fahrzeug);  //add car as a moving car

  /*	cout << endl;
	cout << (*p_fahrzeug).getName() << " achieved the start point on " << p_weg->getName() << endl;
	cout << endl; */
}




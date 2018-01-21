#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Wege.h"
#include<string>



Streckenende::Streckenende() :FahrAusname()
{
}

Streckenende::Streckenende(Fahrzeug * fahr, Wege* weg) : FahrAusname(fahr , weg)
{
}

Streckenende::~Streckenende()
{
}

void Streckenende::vBearbeiten()
{
	p_weg->vAbgabe(p_fahrzeug);  //delet the car from the road 
	//p_weg->vAnnahme(p_fahrzeug); 

	/* cout << endl;
    cout << (*p_fahrzeug).getName() << " achieved the end of " << p_weg->getName() << endl;
    cout << endl; */
		
}




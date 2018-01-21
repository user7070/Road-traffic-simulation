#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Wege.h"
#include<string>
#include "kreuzung.h"



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
	//p_weg->getzeilKreuzung()->vAnnahme(p_fahrzeug, 0.0);  // put the car on the next kreuzung 
	

	kreuzung* pKreuzung = p_weg->getzeilKreuzung();  // kreuzung the car is heading to

	if (pKreuzung != nullptr)
	{
		Wege* pNeuerWeg = pKreuzung->ptZufaelligerWeg(p_weg); //suche ein neue zufall weg
		pKreuzung->vtanken(p_fahrzeug);   // auto tanken 
		pNeuerWeg->vAnnahme(p_fahrzeug); //auto zu neue weg addieren

		cout << "ZEIT     : " << dGlobalZeit << endl
			 << "KREUZUNG : " << pKreuzung->getName() << " " << pKreuzung->dTankinhalt() << endl
			 << "WECHSEL  : " << p_weg->getName() << " --> " << pNeuerWeg->getName() << endl
			 << "FAHRZEUG : " << *p_fahrzeug << endl;
	}
	else
	{
		cout << "No ZielKreuzung is found" << endl;
		
	}  


	cout << endl;
    cout << (*p_fahrzeug).getName() << " achieved the end of " << p_weg->getName() << endl;
    cout << endl; 
		
}




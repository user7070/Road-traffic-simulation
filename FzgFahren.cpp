#include "FzgFahren.h"
#include "Fahrzeug.h"
#include "Wege.h"
#include"Streckenende.h"


FzgFahren::FzgFahren(): FzgVerhalten ()
{
}
FzgFahren::FzgFahren(Wege* weg) : FzgVerhalten (weg)
{
}
FzgFahren::~FzgFahren()
{
}



double FzgFahren::dStrecke(Fahrzeug * fahrzeug, double zeitraum)
{
	//available distance to drive on a specifique road
	double  availablestrecke = p_theweg->Getlenght() - fahrzeug->getshnitstreke();

	//the current drivven distance given a specifique time 
	double currentstrecker = fahrzeug->dGechwindigkeit() * zeitraum;

	//check if we still have enought distance on the road 
	if (availablestrecke > 0)
	{
		//than check if this distance is bigger than currentstrecker
		if (currentstrecker <= availablestrecke)
		{
			return  currentstrecker;
		}

		return availablestrecke;
	}

	else
	{
		//exit(1);

		/* if the road has come to an end then throw new ausnahame : hier end of the road ( streckenende)
		 and catch this ausnahme in weg and there we call streckende class that will delete the car from the list using vabgabe */
		cout << " streckende is erreiched" << endl;
		throw new Streckenende(fahrzeug, p_theweg);
	} 
}



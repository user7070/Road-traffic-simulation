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



/* double FzgFahren::dStrecke(Fahrzeug * fahrzeug, double zeitraum)
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
		 and catch this ausnahme in weg and there we call streckende class that will delete the car from the list using vabgabe
		//cout << " streckende is erreiched" << endl;
		throw new Streckenende(fahrzeug, p_theweg);
	} 
}  */

double FzgFahren::dStrecke(Fahrzeug * fahrzeug, double zeitraum)
{

	double  availablestrecke = p_theweg->Getlenght() - fahrzeug->getshnitstreke();
	double currentstrecker = fahrzeug->dGechwindigkeit() * zeitraum;

	//gets the momentane strecke limit 
	double schranke = p_theweg->getSchranke();
	bool verbot = p_theweg->getVerbote();

	//set schranke with new car 
	p_theweg->SetSchranke(fahrzeug->getshnitstreke() + currentstrecker);

	if (availablestrecke > 0)
	{
		if (currentstrecker <= availablestrecke)     //still enought road 
		{
			/*if (fahrzeug->getshnitstreke() > schranke ) 
			{
				return currentstrecker;
			}*/

			//if the car is slower than the front car : do nothing special : return normal current strecke 
			if (currentstrecker + fahrzeug->getshnitstreke() < schranke)    
			{
				return currentstrecker;
			}
			//if not 
			else  
			{
				//and we have uberholverbot : than return the difference between schranke and the car shnit strecke 
				if ((verbot == true)  && (fahrzeug->getshnitstreke() < schranke))
				{
					return schranke - fahrzeug->getshnitstreke(); //neu current strecke 
				}
				//or else behave normal 
				return currentstrecker;
			 }
		}
		return availablestrecke;;
		
	}

	else
	{
		throw new Streckenende(fahrzeug, p_theweg);
	}
	
} 
// problem ist : nach list kommt zu ende und machen wir erneut abfertigung : erste fahrzeug hangt won schranke des letzte fahrzeug 
//und das ist falsh 


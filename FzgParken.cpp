#include "FzgParken.h"
#include<iostream>
#include "Wege.h"
#include"Fahrzeug.h"
#include "Losfahren.h"

using namespace std;


FzgParken::FzgParken() :FzgVerhalten ()
{
}

FzgParken::FzgParken(Wege* weg, double startpunkt) : FzgVerhalten(weg) ,p_dStartPunkt(startpunkt)
{

}
FzgParken::~FzgParken()
{
}




double FzgParken::dStrecke(Fahrzeug * fahrzeug, double zeitraum)
{
	//if start point not achieved => driven distance is 0
	//if ((p_dStartPunkt - dGlobalZeit) > 0.001)
	if ((p_dStartPunkt - dGlobalZeit) > 0.001)
	{
		return 0.0;
	}
	else
		//cout << " start punkt ist erreicht " << endl;
	   // exit(2);

		/* once we achieved the start point throw an ausnahme : hier Losfahren
		and catch this ausnahme in weg and there we call lozsfahren class that will delete the car from the list using vabgabe and re added again as a moving car  */
		
		throw new Losfahren(fahrzeug, p_theweg); 
}



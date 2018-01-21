#pragma once
#include "FzgVerhalten.h"



class FzgParken :
	public FzgVerhalten
{
public:

	//konstructors and destrucktor
	FzgParken();
	FzgParken(Wege* weg , double startpunkt);
	virtual ~FzgParken();



	//function that assurce the fahrzeug is stopped until the start punkt of the fahzeug then a exception will be thrown
	virtual double dStrecke( Fahrzeug* fahrzeug, double zeitraum);


private:

	//start point of the vehicule
	double p_dStartPunkt;
};


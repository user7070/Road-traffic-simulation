#pragma once
#include "FzgVerhalten.h"

class Fahrzeug;
class Wege;


class FzgFahren :
	public FzgVerhalten
{
public:

	//konctructors and destructor
	FzgFahren();
	FzgFahren(Wege* weg);
	~FzgFahren();



	//fucntion to calculate the distance until the end of the road then throw exception
	virtual double dStrecke(Fahrzeug* fahrzeug, double zeitraum);
	
};


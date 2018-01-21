#pragma once
#include "FahrAusname.h"


class Losfahren :
	public FahrAusname
{
public:
	// konstructors and destructor 
	Losfahren();
	Losfahren(Fahrzeug* fahr, Wege* weg);

	virtual ~Losfahren();

	//functions that prints the car and the road who had an exception : hier start time is achieved 
	 void vBearbeiten();
	
};


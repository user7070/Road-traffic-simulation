#pragma once
#include "FahrAusname.h"

class Streckenende :
	public FahrAusname
{
public:
	// konstructors and destructor 
	Streckenende();
	Streckenende(Fahrzeug* , Wege* );
	virtual ~Streckenende();

	//functions that prints the car and the road who had an exception : hier end of the road 
	 void vBearbeiten();
	
};


#pragma once
#include "SimuClient.h"
#include <iostream>
#include"FzgVerhalten.h"

class Wege;
class Fahrzeug;
class FahrAusname
{
public:
	// konstructors and destructor 
	FahrAusname();
	FahrAusname( Fahrzeug* , Wege*  );
    virtual ~FahrAusname();

	//rein virtual function that prints a message by an exception
	virtual void vBearbeiten() = 0;
	

protected:

	// pointer to the road and vehicule that meets a specifque exception 
	Wege* p_weg;
    Fahrzeug* p_fahrzeug;
};


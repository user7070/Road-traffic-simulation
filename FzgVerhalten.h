 #pragma once

class Wege;
class Fahrzeug;

class FzgVerhalten
{
public:

	//konstructors and destructor 
	FzgVerhalten();
	FzgVerhalten(Wege* weg );
	virtual ~FzgVerhalten();

	/* rein virtuelle fucntion that calculates driven strecke
	 gibt wie weit kann eine fahrzeug fahren von eine gegebene zeitraum */
	virtual double dStrecke(Fahrzeug* fahrzeug, double zeitraum) = 0; 
	
	//function to return the actual road 
	virtual Wege* getweg( ) ;

	
protected:

	//pointer to the actual road
	Wege* p_theweg ;
	
};


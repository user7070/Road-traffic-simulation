#include "FahrAusname.h"



FahrAusname::FahrAusname()
{
}

FahrAusname::FahrAusname(Fahrzeug * fahr, Wege* weg) 
{
	p_fahrzeug = fahr;
	p_weg = weg;
}

FahrAusname::~FahrAusname()
{
}

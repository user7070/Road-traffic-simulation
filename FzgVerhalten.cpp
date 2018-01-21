#include "FzgVerhalten.h"
#include "Fahrzeug.h"
#include "Wege.h"



FzgVerhalten::FzgVerhalten()
{
}
FzgVerhalten::FzgVerhalten(Wege* weg) : p_theweg(weg)
{

}
FzgVerhalten::~FzgVerhalten()
{
}

Wege* FzgVerhalten::getweg( )
{
	return (p_theweg) ;
}


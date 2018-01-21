#pragma once
#include <istream>
#include <list>
#include <fstream>
using namespace std;
class kreuzung;

class Welt
{
public:
	Welt();
	virtual ~Welt();

	void vEinlesen(istream& eingabe);
	void vSimulation();
	void vEinlesenGrafik(istream& eingabe);
private:

	//damit alle krezungen sind bekkant zu welt : um diese krezungen abzufertigen
	list<kreuzung*> pkreuzung;

};


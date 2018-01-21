#pragma once
#include "AktivesVO.h"
#include <list>
#include"LazyListe.h"

class  Fahrzeug;
class FahrAusname;
class  FzgParken;

using namespace std;



// enum contains all different road types and their speed limit
typedef enum  Begrenzung
{
	Innerorts = 50,
	landstrasse = 100,
	Autobahn = -1    //no limit speed 
} Begrenzung;
 
class Wege : public AktivesVO
{
public:
	
	// constrcutors and destructor
	Wege();
	Wege(string name, double lange, Begrenzung speedlimit = Autobahn);
	~Wege();

	//functions to read private data 
	double Getlenght();
	double getlimit();
	virtual string getName();

	//function for abfertigung 
	virtual void vAbfertigung();

	//Ausgabe functions 
	virtual ostream& ostreamAusgabe(ostream& ausgabe);
	virtual void vAusgabe();

	// add a given fahrzeug to the road : running or stopped 
	void vAnnahme(Fahrzeug* );
	void vAnnahme(Fahrzeug* , double startpunkt);

	//delete fahrzeug from the list
	void vAbgabe(Fahrzeug*);
	
protected:

	virtual void vInitialisierung();
	double p_dLaenge; //lange in km des weg
	LazyListe <Fahrzeug*>  p_pFahrzeuge;
	Begrenzung p_eLimit; //raod speed limit 
 // list <Fahrzeug*> p_pFahrzeuge;
};


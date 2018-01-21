#pragma once
#include "AktivesVO.h"
#include <list>
#include"LazyListe.h"


class  Fahrzeug;
class FahrAusname;
class  FzgParken;
class kreuzung;
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
	Wege(string name, double lange, Begrenzung speedlimit , bool verbot = true);
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

	//eingabe function 
	virtual istream& istreamEingabe(istream& eingabe);

	// add a given fahrzeug to the road : running or stopped 
	void vAnnahme(Fahrzeug* );
	void vAnnahme(Fahrzeug* , double startpunkt);

	//delete fahrzeug from the list
	void vAbgabe(Fahrzeug*);

	//getter und setter fur schranke 
	double getSchranke();
	void SetSchranke(double distance);

	//getter for verbot 
	bool getVerbote();

	//set ruckweg
	void vSetZu(Wege*);

	//ziel kreuzung 
	void vSetKreuzung( kreuzung*);

	kreuzung* getzeilKreuzung();

	//get ruckweg 
	Wege* getruckwg();

	//fahrzeuge auf weg zeichnen
	void wegzeichnen();
	
	
protected:

	bool p_bUberholverbot; // zu steurung von überholtverbot
	virtual void vInitialisierung();
	double p_dLaenge; //lange in km des weg
	double p_dSchranke = 10;
	LazyListe <Fahrzeug*>  p_pFahrzeuge;
	Begrenzung p_eLimit; //road speed limit 
	Wege* WEG_ZU;
	kreuzung* al_kreuzung;   //ziel kreuzung
   // list <Fahrzeug*> p_pFahrzeuge;
};


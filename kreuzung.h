#pragma once
#include "AktivesVO.h"
#include "Fahrzeug.h"
#include <list>
#include <iomanip>
#include <string>
#include "Wege.h"
class Wege;

class kreuzung : public AktivesVO
{
public:

	// konstructors and destructor 
	kreuzung();
	kreuzung(string name);
	kreuzung(string name , double tankstelle) ;
	virtual ~kreuzung();

	//angegeben fahrzeug tanken und tankinhalt aktualisieren
	void vtanken(Fahrzeug* fahr);

	//to relate between zwei kreuzungen 
	void vVerbinde(string name_hin, string name_zu, double lange_hin_zu, kreuzung* verbinkreu, Begrenzung limit, bool verbot);

	//take fahrzeuge and place them on hin weg 
	void vAnnahme(Fahrzeug*, double);

	void vAbfertigung();

	//ausgabe function
	virtual ostream& ostreamAusgabe(ostream& ausgabe);

	//eingabe function 
	virtual istream& istreamEingabe(istream& eingabe);

	void Kreuzungzecihen();

	//return inhalt von tankstelle 
	double dTankinhalt();

	//gibt zuffalig weg
    Wege* ptZufaelligerWeg(Wege*);

protected:

	list <Wege*> p_lWege;  //alle wegführende wege 
	double p_dTankstelle;  // volume in litre das eine kreuzeung zum auftanken zur verfügung stellt 
};


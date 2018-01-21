#pragma once

#include "AktivesVO.h"

#include<iostream>
#include<iomanip>
#include <string>


using namespace std;

class Wege;
class FzgVerhalten;

class Fahrzeug : public AktivesVO
{
public:

	//contrcutos and destructor 
	Fahrzeug(); 
	Fahrzeug(string name); 
	Fahrzeug(string name2, double maxspeed);
	Fahrzeug(const Fahrzeug& copyfahr); 
	virtual ~Fahrzeug(); 

	//function to get private data
	virtual string getName();
	void vGetSpeed( double speed ); 
	void vReadName(); 
	double getshnitstreke();

	//functions für abfertigung , tanken und geschwindkeit rechnen
	virtual void vAbfertigung();
	virtual double dTankken(double dMenge); 
	virtual double dGechwindigkeit();   

	//functions für operator überladung
	bool operator<(Fahrzeug& element);
	void operator =(Fahrzeug& fahred);

	//ausgabe functions
	virtual void vAusgabe();
	virtual ostream& ostreamAusgabe(ostream& ausgabe); 
	
	//functions for creation new car object on a given road in a unique statue ( going , stopped )
	void vNeueStrecke(Wege*);
	void vNeueStrecke(Wege*, double startpunkt);

	//function für fahrzeug zeichnen
    virtual	void vZeichnen(Wege*) = 0;
	

	
protected: 

	void vInitialisierung();
	double p_dMaxGechwindikeit; 
	double p_dGesamtStrecke; 
	double p_dGesamtZeit;  
	double p_dAbschnittStrecke; // nur auf dem weg züruck gelegte strecke
	FzgVerhalten* p_pverhalten; // zeiger zu fahrzeug verhaltniss ( moving , stopped )
};


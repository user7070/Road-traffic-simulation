#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
extern double dGlobalZeit;
class Fahrzeug
{
public:
	Fahrzeug(); //standard constructor
	Fahrzeug(string name); // second constructor 
	Fahrzeug(string name2, double maxspeed); // third constructor
	Fahrzeug(const Fahrzeug& copyfahr); //copy constructor 
	virtual ~Fahrzeug();  //destructor 
	void vGetName(string name); //get the name of the fahrzeug 
	void vGetSpeed(double speed); //get the speed of the fahrzeug
	//void vGetID();   //get the ID of the Fahrzeug: nicht mehr notwendig nach p_imaxid
	void vReadName();  // cin fahrzeug Name 
	virtual void vAusgabe(); // cout fahrzeug data : speed ,name,... fahrzeugspezifiche daten ausgeben
	virtual void vAbfertigung(); // fortbewegung des fahrzeug: aktualisierunf von zustände
	virtual double dTankken(double dMenge);  //fahrzeug tanken 
	virtual double dGechwindigkeit();   //geschwindkeit des fahrzeug 
	virtual ostream& ostreamAusgabe(ostream& ausgabe); //ausgabe funktion
	bool operator<(Fahrzeug& element); //vergleich operator overload 
	void operator =(Fahrzeug& fahred); // assignemnt operator overload 
private:
	
	static int p_iMaxID; //damit jede fahrzeug bekommet eine eindeutige ID NUMMER :
	                     //Statisches Objekt ist ein Objekt, das von der Konstruktion bis zum Ende des Programms bestehen bleibt.
	void vInitialisierung(); // initialise all private members in one private fucntion

protected:

	//alle diese varaibeln sinf von untere klassen zugreifbar 
	string p_sName;// name des fahrzeug
	int p_iID;   // id des fahzeug
	double p_dMaxGechwindikeit; // max gechwindikeit des fahrzeug
	double p_dGesamtStrecke; // gesamt fahrende strecke
	double p_dGesamtZeit; // gesamt fahrzeit
	double p_dZeit;  //letzte abfertigung zeit


};
//operator overloading
ostream& operator<<(ostream& ausgabe, Fahrzeug& element); // uberladung von operator ausserhalb klasse da den ostream operand kein element des klasse ist 

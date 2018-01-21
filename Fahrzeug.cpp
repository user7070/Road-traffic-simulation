#include "Fahrzeug.h"
#include "Wege.h"
#include "FzgVerhalten.h"
#include "FzgFahren.h"
#include "FzgParken.h"


Fahrzeug::Fahrzeug() :AktivesVO()
{
	vInitialisierung();
}
Fahrzeug::Fahrzeug(string name) :AktivesVO()
{
	vInitialisierung();
	p_sName = name;
	
}
Fahrzeug::Fahrzeug(string name2, double maxspeed) : AktivesVO()
{
	vInitialisierung();
	p_sName = name2;
	p_dMaxGechwindikeit = maxspeed;
}
Fahrzeug::Fahrzeug(const Fahrzeug & copyfahr) 
{
	vInitialisierung(); // damit jeder hat sein eigenes ID
	p_sName = copyfahr.p_sName;
	p_dMaxGechwindikeit = copyfahr.p_dMaxGechwindikeit;
	p_dGesamtStrecke = copyfahr.p_dGesamtStrecke;
	p_dGesamtZeit = copyfahr.p_dGesamtZeit;
} 


void Fahrzeug::vInitialisierung()
{
	p_dMaxGechwindikeit = 0;
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dAbschnittStrecke = 0;
	p_pverhalten = NULL;   //p_pverhalten Auf Null inialisiert 

}


Fahrzeug::~Fahrzeug()
{
}

string Fahrzeug::getName( )
{
	return p_sName ;
}

void Fahrzeug::vGetSpeed( double speed)
{
p_dMaxGechwindikeit = speed;
}

void Fahrzeug::vReadName()
{
	cin >> p_sName;
}

double Fahrzeug::getshnitstreke()
{
	return p_dAbschnittStrecke;
}


double Fahrzeug::dTankken(double dMenge)
{
	return 0.0; //defaullt value 
}

double Fahrzeug::dGechwindigkeit()
{
	return p_dMaxGechwindikeit;
}

void Fahrzeug::vAbfertigung()
{
	if (p_dZeit == dGlobalZeit) 
		return;

	if ( p_dZeit < dGlobalZeit)
	{
		double dNewZeit = dGlobalZeit - p_dZeit;
		p_dGesamtStrecke = p_dGesamtStrecke + dGechwindigkeit() * dNewZeit;
		p_dGesamtZeit = p_dGesamtZeit + dNewZeit;
		//p_dAbschnittStrecke += dGechwindigkeit() * dNewZeit;
		p_dAbschnittStrecke += p_pverhalten->dStrecke(this , dNewZeit );  //dStrecke calculates the distance tha the car cann go in the given time 
		                                                                  //this points to fahrzeug
		p_dZeit = dGlobalZeit;
	}
}


void Fahrzeug::vAusgabe()
{
	AktivesVO::vAusgabe();
	cout << setw(15) << setprecision(3) << resetiosflags(ios::right) << setiosflags(ios::left) << dGechwindigkeit()
		<< setw(22) << p_dGesamtStrecke
		<< setw(20) << setprecision(3) << resetiosflags(ios::right) << setiosflags(ios::left) << p_dGesamtZeit;
}
ostream& Fahrzeug::ostreamAusgabe(ostream& ausgabe) 
{
	AktivesVO::ostreamAusgabe(ausgabe);
	ausgabe << setw(15) << setprecision(3) << resetiosflags(ios::right) << setiosflags(ios::left) << dGechwindigkeit()
		<< setw(22) << p_dGesamtStrecke
		<< setw(20) << setprecision(3) << resetiosflags(ios::right) << setiosflags(ios::left) << p_dGesamtZeit
		<< setw(20) << setprecision(3) << resetiosflags(ios::left) << setiosflags(ios::left) << p_dAbschnittStrecke;

	return ausgabe;
}

istream & Fahrzeug::istreamEingabe(istream & eingabe)
{
	// TODO: hier Rückgabeanweisung eingeben
	AktivesVO::istreamEingabe(eingabe);
	eingabe >> p_dMaxGechwindikeit;
	return eingabe;
}


bool Fahrzeug::operator<(Fahrzeug & element)
{
	if (this->p_dGesamtStrecke < element.p_dGesamtStrecke)
	{
		return true;
	}
	return false;
}

void Fahrzeug::operator=(Fahrzeug & fahred)
{
	//this->p_iID = fahred.p_iID; // sichert dass beide haben gleich ID 
	this->p_sName = fahred.p_sName;
	this->p_dMaxGechwindikeit = fahred.p_dMaxGechwindikeit;
	this->p_dGesamtStrecke = fahred.p_dGesamtStrecke;
	this->p_dGesamtZeit = fahred.p_dGesamtStrecke;

}


void Fahrzeug::vNeueStrecke(Wege*  weg )
{
	// fahrzeug enters a new road => delete the latest object created before entering a new road
		delete p_pverhalten;
	
		

    //creat the new object 		
	p_pverhalten = new FzgFahren (weg);
	
	//set abschnit strecke to zero ; because latest object will enter an other road
	p_dAbschnittStrecke = 0;
	p_dZeit = dGlobalZeit;

}
void Fahrzeug::vNeueStrecke(Wege*  weg , double startpunkt)
{

		delete p_pverhalten;

	p_pverhalten = new FzgParken(weg, startpunkt);

	p_dAbschnittStrecke = 0;
	p_dZeit = dGlobalZeit;
}



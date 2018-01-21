#include "Fahrzeug.h"
#include <string>

int Fahrzeug::p_iMaxID = 0;
Fahrzeug::Fahrzeug()
{
	//p_sName = "";
	vInitialisierung();
	cout << " using standard constructor " << endl;
	cout << " Fahrzeug mit ID " << p_iID << " und Name " << p_sName << " created " << endl;
}

Fahrzeug::Fahrzeug(string name)
{
	vInitialisierung();
	p_sName = name;
     cout << " using constructor1 " << endl;
	cout << " Fahrzeug mit ID " << p_iID << " und Name " << p_sName <<" created " <<  endl;
}

Fahrzeug::Fahrzeug(string name2, double maxspeed)
{
	vInitialisierung();
	p_sName = name2;
	p_dMaxGechwindikeit = maxspeed;
	cout << " using constructor2" << endl;
	cout << " Fahrzeug mit ID " << p_iID << " und Name " << p_sName << " created " << endl;
}

Fahrzeug::Fahrzeug(const Fahrzeug & copyfahr)
{
	vInitialisierung(); // damit jeder hat sein eigenes ID
	//p_iID = copyfahr.p_iID;     // sichert das beide haben den glecihen ID 
	p_sName = copyfahr.p_sName;
	p_dMaxGechwindikeit = copyfahr.p_dMaxGechwindikeit;
	p_dGesamtStrecke = copyfahr.p_dGesamtStrecke;
	p_dGesamtZeit = copyfahr.p_dGesamtZeit;
}


Fahrzeug::~Fahrzeug()
{
	//cout << " Fahrzeug mit ID " << p_iID << " und Name " << p_sName << " deleted " << endl;
}

void Fahrzeug::vGetName(string name)
{
	p_sName = name;
}
void Fahrzeug::vGetSpeed(double speed)
{
	p_dMaxGechwindikeit = speed;
}
//nicht meht notwendig da wir haben vInitialisierung
/*void Fahrzeug::vGetID()
{
	p_iMaxID++;
	p_iID = p_iMaxID;
}*/
void Fahrzeug::vReadName()
{
	cin >> p_sName;
}

void Fahrzeug::vAusgabe()
{
	cout << fixed << setw(6) << setiosflags(ios::left) << p_iID  //erst lef bündig
		<< setw(8) << resetiosflags(ios::left) << setiosflags(ios::right) << p_sName << "          :   " //rechtbündig
		<< setw(15) << setprecision(3) << resetiosflags(ios::right) << setiosflags(ios::left) << dGechwindigkeit()
		<< setw(22) << p_dGesamtStrecke
		<< setw(20) << setprecision(3) << resetiosflags(ios::right) << setiosflags(ios::left) << p_dGesamtZeit << endl ;

}

void Fahrzeug::vAbfertigung()
{
	if (p_dZeit == dGlobalZeit) //einfach für sicherheit 
		return;
	if ( p_dZeit < dGlobalZeit)
	{
		double dNewZeit = dGlobalZeit - p_dZeit;
		p_dGesamtStrecke = p_dGesamtStrecke + dGechwindigkeit() * dNewZeit;
		p_dGesamtZeit = p_dGesamtZeit + dNewZeit;
		p_dZeit = dGlobalZeit;
	}

}

double Fahrzeug::dTankken(double dMenge)
{
	return 0.0; //defaullt value 
}

double Fahrzeug::dGechwindigkeit()
{
	return p_dMaxGechwindikeit;
}

ostream& Fahrzeug::ostreamAusgabe(ostream& ausgabe) 
{
	ausgabe << fixed << setw(6) << setiosflags(ios::left) << p_iID  //erst lef bündig
		<< setw(8) << resetiosflags(ios::left) << setiosflags(ios::right) << p_sName << "          :   " //rechtbündig
		<< setw(15) << setprecision(3) << resetiosflags(ios::right) << setiosflags(ios::left) << dGechwindigkeit()
		<< setw(22) << p_dGesamtStrecke
		<< setw(20) << setprecision(3) << resetiosflags(ios::right) << setiosflags(ios::left) << p_dGesamtZeit;

	   
	

	return ausgabe;
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

void Fahrzeug::vInitialisierung()
{
	p_iMaxID++;   // damit ID fangt mit 1 p_iMaxID++ bevor p
	p_sName = "";
	p_iID = p_iMaxID;
	p_dMaxGechwindikeit = 0;
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dZeit = 0;
}

ostream & operator<<(ostream & ausgabe, Fahrzeug& element)
{
	// TODO: hier Rückgabeanweisung eingeben
	return element.ostreamAusgabe(ausgabe);
}

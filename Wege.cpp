#include "Wege.h"
#include "Fahrzeug.h"
#include"FahrAusname.h"
#include"Losfahren.h"
#include "FzgVerhalten.h"
#include <string>
#include "kreuzung.h"
 
Wege::Wege() : AktivesVO()
{
	vInitialisierung();
}
Wege::Wege(string name, double lange, Begrenzung speedlimit , bool verbot ) : AktivesVO() , p_eLimit(speedlimit) ,p_bUberholverbot(verbot)
{
	p_sName = name;
	p_dLaenge = lange;
	p_eLimit = Autobahn;
	
}
Wege::~Wege()
{
}


void Wege::vInitialisierung()
{
	p_dLaenge = 0;
    p_eLimit = Autobahn;
	p_dSchranke = 10;
}

void Wege::vAbfertigung()
{
	LazyListe <Fahrzeug*> ::iterator it;    //crazy list iterator

	//aktualisiren von list 
	//p_pFahrzeuge.vAktualisieren();

										
	for (it= p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		//abfertigung von fahrzeuge bis auftreten von exception
		try
		{
			(*it)->vAbfertigung();
			(*it)->vZeichnen(this);
			
		} 

		//if exception is found => catch this exception  here hand print a message 

			catch (FahrAusname* ausname)
			{
				ausname->vBearbeiten();
			}	
	}

	//aktualisiren von list 
	p_pFahrzeuge.vAktualisieren();
}

ostream & Wege::ostreamAusgabe(ostream & ausgabe)
{
	LazyListe<Fahrzeug*> ::iterator it;
	p_pFahrzeuge.vAktualisieren();

	AktivesVO::ostreamAusgabe(ausgabe);

	ausgabe << setprecision(0) << setw(4) << resetiosflags(ios::right) << setiosflags(ios::left) << p_dLaenge << "        ( ";
	for (it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		ausgabe << (*it)->getName( ) << " ";
	}	 
	ausgabe << ") " << endl ;

		return ausgabe;
}
void Wege::vAusgabe()
{
	AktivesVO::vAusgabe();
	cout << resetiosflags(ios::right) << setiosflags(ios::left) << p_dLaenge << endl;
}

istream & Wege::istreamEingabe(istream & eingabe)
{
	// TODO: hier Rückgabeanweisung eingeben
	AktivesVO::istreamEingabe(eingabe);
	return eingabe;
}



void Wege::vAnnahme(Fahrzeug* fahr)
{
	fahr->vNeueStrecke(this);                     //first creat a car object : hier fahrend 
	p_pFahrzeuge.push_back(fahr);                 //than add fahrzeug to list of cars on the raod 

}

void Wege::vAnnahme(Fahrzeug * fahr, double startpunkt)
{
	fahr->vNeueStrecke(this,startpunkt);      //first creat a car object : hier parkend 
	p_pFahrzeuge.push_front(fahr);            //than add fahrzeug to list of cars on the raod 
}

void Wege::vAbgabe(Fahrzeug * fahr)
{
	LazyListe<Fahrzeug*> ::iterator it;

	for (it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end() ; it++)
	{
		if ( (*it) == fahr) 
		{
			p_pFahrzeuge.erase(it);   //search for the car to delete than delete it 

			break;
		}
	}	
}

double Wege::getSchranke()
{
	//if there is uberholverbot than return schranke 
	if ( p_bUberholverbot == true)
	{
		return p_dSchranke;
	}
	else 
	{
		return p_dLaenge;
	}
}

void Wege::SetSchranke(double distance)
{
	p_dSchranke = distance;
}

bool Wege::getVerbote()
{
	return p_bUberholverbot;
}

void Wege::vSetZu(Wege* weg_zu)
{
	WEG_ZU = weg_zu;
}

void Wege::vSetKreuzung(kreuzung* kreu)
{
	al_kreuzung = kreu;
}

kreuzung* Wege::getzeilKreuzung()
{
	return al_kreuzung;
}

Wege * Wege::getruckwg()
{
	return WEG_ZU;
}

void Wege::wegzeichnen()
{
	LazyListe<Fahrzeug*> ::iterator it;
	for ( it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end() ; it ++) 
	{
		(*it)->vZeichnen(this);
	}
}

string Wege::getName( )
{
   return p_sName ;
}

double Wege::Getlenght()
{
	return p_dLaenge;
}

double Wege::getlimit()
{
	return p_eLimit;
}




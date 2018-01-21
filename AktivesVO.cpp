#include "AktivesVO.h"

//weil static
int AktivesVO ::p_iMaxID = 0;
map<string, AktivesVO*> AktivesVO::themap;

AktivesVO::AktivesVO()
{
	vInitialisierung();
}

AktivesVO::AktivesVO(string name)
{
	vInitialisierung();
	p_sName = name;


	//konstraktor 
	// Überprüfe, ob ein VO obeject mit diesem Namen bereits existiert:
	if (themap.find(p_sName) == themap.end())
	{
		// nicht gefunden: füge neues VO object in map einfugen
		themap[p_sName] = this;
	}
	else if (p_sName != "")
	{
		throw new string("Es gibt bereits ein VO mit dem Namen: " + p_sName);
	}
}

AktivesVO::~AktivesVO()
{
}

ostream & AktivesVO::ostreamAusgabe(ostream & ausgabe)
{
	ausgabe << fixed << setw(6) << setiosflags(ios::left) << p_iID 
		    << setw(8) << resetiosflags(ios::left) << setiosflags(ios::right) << p_sName << "          :   " ;
	return ausgabe;
}

istream & AktivesVO::istreamEingabe(istream & eingabe)
{
	// TODO: hier Rückgabeanweisung eingeben
	if (p_sName == "")

	{
		eingabe >> p_sName;

		// überprüfe, ob bereits ein VO mit diesem Namen existiert:
		if (themap.find(p_sName) == themap.end())
		{
			// nicht gefunden: füge dieses VO neu hinzu
			//map[key] = value; mit key ist name und value ist zeiger zu aktivesvo
			themap[p_sName] = this;
		}
		else
		{
			throw new string("Es gibt bereits ein VO mit dem Namen: " + p_sName);
		}
	}
	else 
	{
		throw new string(" Fehler ! Name schone existiert ");
	}
	return eingabe;
}

void AktivesVO::vAusgabe()
{
	cout << fixed << setw(6) << setiosflags(ios::right) << p_iID 
		<< setw(8) << resetiosflags(ios::left) << setiosflags(ios::right) << p_sName << "          :   ";
}

void AktivesVO::vInitialisierung()
{
	p_iMaxID++;   
	p_sName = "";
	p_iID = p_iMaxID;
	p_dZeit = 0;
}

string AktivesVO::getName()
{
	return p_sName;
}

AktivesVO* AktivesVO::ptObjekt(string name)
{
	//map ieterator 
	map<string, AktivesVO*>::iterator itMap;
	itMap = themap.find(name);   //Searches the container for an element with a key equivalent to name and returns an iterator to it if found
	if (itMap == themap.end())   //end point to the element after the last one => point to nothing 
	{
		throw new string("Object not found ! please check Name");
	}
	else
	{
	//	cout << "object found " << endl;
		return itMap->second;  //second points to the pointer of verkehr object and not name 
	}
}

ostream& operator<<(ostream& ausgabe, AktivesVO& element)
{
	element.ostreamAusgabe(ausgabe);
	return ausgabe;
}

istream& operator >> (istream& einagbe, AktivesVO& element)
{
	// TODO: hier Rückgabeanweisung eingeben
	element.istreamEingabe(einagbe);
	return einagbe;
}

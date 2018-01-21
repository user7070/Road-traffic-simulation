#include "AktivesVO.h"

int AktivesVO ::p_iMaxID = 0;

AktivesVO::AktivesVO()
{
	vInitialisierung();
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

void AktivesVO::vAusgabe()
{
	cout << fixed << setw(6) << setiosflags(ios::left) << p_iID 
		<< setw(8) << resetiosflags(ios::left) << setiosflags(ios::right) << p_sName << "          :   ";
}


void AktivesVO::vInitialisierung()
{
	p_iMaxID++;   
	p_sName = "";
	p_iID = p_iMaxID;
	p_dZeit = 0;
}

ostream& operator<<(ostream& ausgabe, AktivesVO& element)
{
	element.ostreamAusgabe(ausgabe);
	return ausgabe;
}

#include "kreuzung.h"
#include "Wege.h"
#include <string>
#include <time.h> 

kreuzung::kreuzung() : AktivesVO()
{
}

kreuzung::kreuzung(string name) :AktivesVO()
{
	p_sName = name;
}

kreuzung::kreuzung(string name, double tankstelle) : AktivesVO()
{
	p_sName = name;
	p_dTankstelle = tankstelle;
}

kreuzung::~kreuzung()
{
}

void kreuzung::vtanken(Fahrzeug* fahr)
{
	if (p_dTankstelle > 0) 
	{
		//fahrzeug tanken
		//tankinhalt aktualisiren
		p_dTankstelle = p_dTankstelle - fahr->dTankken(p_dTankstelle);

		if (p_dTankstelle < 0)
		{
			p_dTankstelle = 0;
		}
	}
}

void kreuzung::vVerbinde(string name_hin, string name_zu, double lange_hin_zu, kreuzung* verbinkreu, Begrenzung limit, bool verbot)
{ 
	//PS: hin : gehend , zu : kommend 
	//erste weg erstellen 
	Wege* weg_hin =  new Wege ( name_hin,  lange_hin_zu,  limit,  verbot);
    Wege* weg_zu  = new Wege  (name_zu, lange_hin_zu, limit, verbot);

	//wege unter einander bekant 
	weg_hin->vSetZu(weg_zu);
	weg_zu->vSetZu(weg_hin);

	//weg kennt auf welchem kruzung er führt  
	weg_hin->vSetKreuzung(verbinkreu);
	weg_zu->vSetKreuzung(this);

	// add hin wege for list of both krezung 
	p_lWege.push_back(weg_hin); //hin weg for this kreuzung 
	verbinkreu->p_lWege.push_back(weg_zu);  //weg zu ist der hin weg fur auf zuverbindende kreuzung 

}

void kreuzung::vAnnahme(Fahrzeug* fahr , double start)
{
	//erst fahrzeug tanken 
	vtanken(fahr);

	if (p_lWege.size() == 0)
	{
		throw new string(" kreuzung hat keine str!");

	}
	else 
	{
		list <Wege*> ::iterator begin = p_lWege.begin();  //ersten abgehended weg

		(*begin)->vAnnahme(fahr, start);

	}
	
}

void kreuzung::vAbfertigung()
{
	list<Wege*> ::iterator it;
	for (it =  p_lWege.begin() ; it != p_lWege.end(); it++) 
	{
		(*it)->vAbfertigung();
	}
}

ostream & kreuzung::ostreamAusgabe(ostream & ausgabe)
{
	list<Wege*>::iterator it;
	AktivesVO::ostreamAusgabe(ausgabe);

	ausgabe << setprecision(2) << setw(62) << resetiosflags(ios::right) << setiosflags(ios::right) << p_dTankstelle << "          ( ";

	for (it = p_lWege.begin(); it != p_lWege.end(); it++)
	{
		ausgabe <<resetiosflags(ios::right) << setiosflags(ios::left) << (*it)->getName() << " ";
	}
	ausgabe << ")  " << endl ;

	for (it = p_lWege.begin(); it != p_lWege.end(); it++)
	{
	(*it)->ostreamAusgabe(ausgabe);
	}
	return ausgabe;
}

istream & kreuzung::istreamEingabe(istream & eingabe)
{
	// TODO: hier Rückgabeanweisung eingeben
	AktivesVO::istreamEingabe(eingabe);
	eingabe >> p_dTankstelle;
	return eingabe;
}

void kreuzung::Kreuzungzecihen()
{
	list <Wege*> ::iterator itr;
	for (itr = p_lWege.begin() ; itr != p_lWege.end() ; itr ++) 
	{
		(*itr)->wegzeichnen();
	}
}

double kreuzung::dTankinhalt()
{
	return p_dTankstelle;
}

Wege* kreuzung::ptZufaelligerWeg(Wege* weg)
{
	// bei einer Sackgasse muss der gleiche strasse zurückgefahren werden:
	if (p_lWege.size() == 1 )
	{
		weg->getruckwg();  // return the other side road 
	}

	//else suche ein zufall str
	Wege* weg_luck = nullptr;
	
	do
	{
		//fur wahl zwichen elle wege einer ziel krezung 
		srand(time(NULL));
		int zufall = rand() %  p_lWege.size()   ;  //zahl im range 0__size-1 
	
		int j = 0; //sichert dass wir haben einzel wahl aus wege
		
		list <Wege*> ::iterator itr ;

		for (itr = p_lWege.begin(); itr != p_lWege.end(); itr++)
		{
			if (zufall <= j) //wenn if ist richtig => wir haben ein weg auswahl gemacht 
			{
				weg_luck = *itr;

				break;
			}	
			j++;
		}
	}
	while (weg_luck == weg->getruckwg()); //while wir sind in der selbe str 

	return weg_luck;
} 

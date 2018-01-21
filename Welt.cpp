#include "Welt.h"
#include "Fahrrad.h"
#include "PKW.h"
#include "kreuzung.h"
#include <istream>
#include "SimuClient.h"
#include "Wege.h"
#include <string>
#include "AktivesVO.h"

Welt::Welt()
{
}


Welt::~Welt()
{
}

void Welt::vEinlesen(istream& eingabe)
{
	
	string key ;
	//eingabe ist unsere eingabe strom die enthalt alle benotigte elemente 
	//while file didn't come to an end 
	while (!eingabe.eof())
	{
		//read string 
		eingabe >> key;

		//first line is KREUSUNG
		if (key == "KREUZUNG")
		{
			//creat new empty krezung
			kreuzung* KREU = new kreuzung();

			//read krezung data 
			eingabe >> *KREU;

			//add kreuzung to list  alle krezungen 
			pkreuzung.push_back(KREU);
		}

		else if (key == "STRASSE")  //erlaubt uns zwei kreuzungen zu verbinden
		{
			//quelle krezung
			string NameQ;

			//ziel krezung
			string NameZ;

			//weg von quelle zu ziel
			string NameW1;

			//weg von ziel zu quelle
			string NameW2;

			//weg lange 
			int lange;

			// enum mit werte 1,2,3
			int ilimit;
			//enum mit werte 0,1
			int iverbot;

			//speed limit and uberholverbot
			Begrenzung limit;
			bool verbot;

			//read all data 
			eingabe >> NameQ >> NameZ >> NameW1 >> NameW2 >> lange >> ilimit >> iverbot;


			switch (ilimit)
			{
			case 1:
				limit = Innerorts;
				break;
			case 2:
				limit = landstrasse;
				break;
			case 3:
				limit = Autobahn;
				break;
			default:
				throw new string("No limit given ");
			}

			switch (iverbot)
			{
			case 0:
				verbot = false;
				break;
			case 1:
				verbot = true;
				break;
			default:
				throw new string(" Uberhol verbot unbekkant");
			}

			// cast names to kreuzung types
			//make sure that nameQ and NameZ belongs to krezungen
			kreuzung* kreu1 = dynamic_cast<kreuzung*> (AktivesVO::ptObjekt(NameQ));
			kreuzung* kreu2 = dynamic_cast<kreuzung*> (AktivesVO::ptObjekt(NameZ));


			//check if kreuzung exist
			if (kreu1 == nullptr  || kreu2 == nullptr) 
			{
				throw new string(" kreuzungen nicht gefunden! ");
			}

			//kreuzungen verbinden 
			kreu1->vVerbinde(NameW1, NameW2, lange, kreu2, limit, verbot);
			


		}
		else if (key == "PKW")
		{
			//names des kreuzung und start punkt 
			string NameS;
			double starttime;

			//creat new PKW empty obj
			PKW* THEcar = new PKW();


			// read data : PKW data and name of startkrezung and start time 
			eingabe >> *THEcar >> NameS >> starttime;

			//add pkw to kreuzung; for that we need first to cast the kreuzung name 
			// change string type to kreuzung 
			kreuzung* kreu = dynamic_cast <kreuzung*> (AktivesVO::ptObjekt(NameS));

			if (kreu == nullptr)
			{
				throw new string(" No kreuzung found, car can't be added !");
			}

			//add pkw to krezung
			kreu->vAnnahme(THEcar, starttime);


		}
		else	if (key == "FAHRRAD")
		{
			//names des kreuzung und start punkt 
			string NameS;
			double starttime;

			//creat new fahhrad empty obj
			Fahrrad* THEfahrrrad = new Fahrrad();

			// read data : fahhrad data and name of startkrezung and start time 
			eingabe >> *THEfahrrrad >> NameS >> starttime;


			//add pkw to kreuzung; for that we need first to cast the kreuzung name 
			// change string type to kreuzung 
			kreuzung* kreu = dynamic_cast <kreuzung*> (AktivesVO::ptObjekt(NameS));

			if (kreu == nullptr)
			{
				throw new string(" No kreuzung found, Fahrrad can't be added !");
			}

			//add pkw to krezung
			kreu->vAnnahme(THEfahrrrad, starttime);

		}
		else 
		{
			throw new string("Data unKhnown, Please verify Entry");
		}

	}
}

void Welt::vSimulation()
{
	list<kreuzung*>::iterator itr;

	// Start die Abfertigung für alle Kreuzungen:
	for (itr  = pkreuzung.begin(); itr != pkreuzung.end(); itr++)
	{
		(*itr)->vAbfertigung();
		cout << *(*itr) << endl;
	}
}

void Welt::vEinlesenGrafik(istream& eingabe)
{
	
	//while file didn't come to an end 
	string key ;
	while (!eingabe.eof())
	{
		//read string 
		eingabe >> key;

		//first line is KREUSUNG
		if (key == "KREUZUNG")
		{
			//creat new empty krezung
			kreuzung* KREU = new kreuzung();

			//koordinaten x ,y
			double x, y;

			//read krezung data 
			eingabe >> *KREU >> x >> y;

			//add kreuzung to list 
			pkreuzung.push_back(KREU);

			// zeichne Kreuzung 
			bZeichneKreuzung(x, y);
		}

		else if (key == "STRASSE")
		{

			string NameQ;
			string NameZ;
			string NameW1;
			string NameW2;
			double lange;
			int korrdAnzahl;
			int ilimit;
			int iverbot;
			Begrenzung limit;
			bool verbot;
			int koordinaten[100];

			//read all data 
			eingabe >> NameQ >> NameZ >> NameW1 >> NameW2 >> lange >> ilimit >> iverbot >> korrdAnzahl;

			//read array element 
			for (int b = 0;b < (korrdAnzahl * 2); b++)
			{
				eingabe >> koordinaten[b];
			}


			switch (ilimit)
			{
			case 1:
				limit = Innerorts;
				break;
			case 2:
				limit = landstrasse;
				break;
			case 3:
				limit = Autobahn;
				break;
			default:
				throw new string("No limit given ");
			}

			switch (iverbot)
			{
			case 0:
				verbot = false;
				break;
			case 1:
				verbot = true;
				break;
			default:
				throw new string(" Uberhol verbot unbekkant");
			}

			// cast names to kreuzung types
			kreuzung* kreu1 = dynamic_cast<kreuzung*> (AktivesVO::ptObjekt(NameQ));
			kreuzung* kreu2 = dynamic_cast<kreuzung*> (AktivesVO::ptObjekt(NameZ));


			//check if kreuzung exist
			if (kreu1 == nullptr  || kreu2 == nullptr) 
			{
				throw new string(" kreuzungen nicht gefunden! ");
			}

			//kreuzungen verbinden 
			kreu1->vVerbinde(NameW1, NameW2, lange, kreu2, limit, verbot);
			//strasse zeichen
			bZeichneStrasse(NameW1, NameW2, lange, korrdAnzahl, koordinaten);

		}
		else if (key == "PKW")
		{
			//names des kreuzung und start punkt 
			string NameS;
			double starttime;

			//creat new PKW empty obj
			PKW* THEcar = new PKW();


			// read data : PKW data and name of startkrezung and start time 
			eingabe >> *THEcar >> NameS >> starttime;

			//add pkw to kreuzung; for that we need first to cast the kreuzung name 
			// change string type to kreuzung 
			kreuzung* kreu = dynamic_cast <kreuzung*> (AktivesVO::ptObjekt(NameS));

			if (kreu == nullptr)
			{
				throw new string(" No kreuzung found, car can't be added !");
			}

			//add pkw to krezung
			kreu->vAnnahme(THEcar, starttime);


		}
		else	if (key == "FAHRRAD")
		{
			//names des kreuzung und start punkt 
			string NameS;
			double starttime;

			//creat new fahhrad empty obj
			Fahrrad* THEfahrrrad = new Fahrrad();

			// read data : fahhrad data and name of startkrezung and start time 
			eingabe >> *THEfahrrrad >> NameS >> starttime;


			//add pkw to kreuzung; for that we need first to cast the kreuzung name 
			// change string type to kreuzung 
			kreuzung* kreu = dynamic_cast <kreuzung*> (AktivesVO::ptObjekt(NameS));

			if (kreu == nullptr)
			{
				throw new string(" No kreuzung found, Fahrrad can't be added !");
			}

			//add pkw to krezung
			kreu->vAnnahme(THEfahrrrad, starttime);

		}
		else 
		{
			throw new  string("Data unKhnown, Please verify Entry");
		}

	}
}


		
			


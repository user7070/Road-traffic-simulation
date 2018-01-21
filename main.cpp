#include "Fahrzeug.h"
#include<string>
#include<iostream>
#include <vector>
#include <math.h>
#include "PKW.h"
#include "Fahrrad.h"
#include "AktivesVO.h"
#include "Wege.h"
#include "SimuClient.h"
#include <stdlib.h>
#include "LazyListe.h"
#include "kreuzung.h"
#include<fstream>
#include "Welt.h"


using namespace std;

double dGlobalZeit = 0.0; // Global UHR : hold the value throughout the life-time of the program. can be accesed by any function

//tabel form
void vTableForm()
{
	cout << " " << endl;
	cout << "ID       Name           :   MaxKmh         GesamtStrecke         GesamtZeit" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << " " << endl;
}
 /*void vAufgabe_1() 
{
	system("color 02");
	cout << " testing ..........  " << endl;
	cout << " Aufgabe 1 " << endl;

	//static erzeugen
	//erste construktor
	Fahrzeug fahr1;
	fahr1.vGetName();
	fahr1.vGetSpeed(350);
	//zweites construktor
	Fahrzeug fahr2(" polo ");
	fahr2.vGetSpeed(130);
	//dritte constructor 
	Fahrzeug fahr12(" VW", 120);
	
	//dynamisch erstellen 
	//erste construktor
	Fahrzeug* fahr3 = new Fahrzeug;
	fahr3->vGetName();
	fahr3->vGetSpeed(220);
	//zweites construktor
	Fahrzeug* fahr4= new Fahrzeug("") ;
	fahr4->vGetSpeed(55);
	cout << " Bitte geben sie den Fahrzeug name " << endl;
	fahr4->vReadName();
	//dritte constructor
	Fahrzeug* fahr34 = new Fahrzeug("", 250);
	cout << " Bitte geben sie den zweiten Fahrzeug name " << endl;
	fahr34->vReadName();

	
	

	
	vTableForm();
	for (dGlobalZeit = 0.0 ;dGlobalZeit <= 6; dGlobalZeit += 1.5 )
	{
		
		//erste abfertigung 
		fahr1.vAbfertigung();
		fahr2.vAbfertigung();
		fahr12.vAbfertigung();
		fahr3->vAbfertigung();
		fahr4->vAbfertigung();
		fahr34->vAbfertigung();

		//danach ausgabe 
		fahr1.vAusgabe();
		fahr2.vAusgabe();
		fahr12.vAusgabe();
		fahr3->vAusgabe();
		fahr4->vAusgabe();
		fahr34->vAusgabe();

	}
	
	//delete all dynamic fahrzeuge
	delete fahr34;
	delete fahr4;
	delete fahr3;

}
void vAufagbe_1_deb()
{
	//4 verschieden statisch erstellete fahrzeuge 
	Fahrzeug one(" one", 150);
	Fahrzeug two(" two", 150);
	Fahrzeug three(" three", 100);
	Fahrzeug four(" four", 200);

	Fahrzeug* Feld[4]; // Feld als zeiger zu unserer  zugestelte Fahrzeuge 

	// Feld [i] : i:0..3  nimmt adresse von fahzeug one, two , three , four 
	Feld[0] = &one;
	Feld[1] = &two;
	Feld[2] = &three;
	Feld[3] = &four;

	vTableForm();
	for ( int i= 0 ; i< 4; i++)
	{
		Feld[i]->vAusgabe();
	}

    Feld[2] = 0;

	cout << "\n" << "\n" << endl;

	vTableForm();
	for (int i = 0; i< 4; i++)
	{
		Feld[i]->vAusgabe();  
		//problem ist : Ausgelöste Ausnahme: Lesezugriffsverletzung   : "this" war "nullptr".
		//proble geschiert wenn program versucht eine id zu Feld[2] zu geben 
		// um dises problem zu lösen feld [i=2] muss geweschselt 

	}
}
void vAufgabe_2() 
{
	system("color 05");
	vector <Fahrzeug*> v1;//creat vector that contains all pkw and fahrrad data
	cout << " wie viele PKW sollen erstellt werden ? " << endl;
	int iPKWZahl;
	cin >> iPKWZahl;
	cout << " wie viele fahrräder sollen erstellt werden ? " << endl;
	int iFahrraderZahl;
	cin >> iFahrraderZahl;
	for ( int i = 1 ; i <= iPKWZahl ; i++)
	{
		string name;
		double maxspeed;
		double verbrauch;
		double tankvolume;
		cout << " PKW Name : ";
		cin >> name;
		cout << " Pkw max speed :  ";
		cin >> maxspeed;
		cout << "PKW Verbrauch : ";
		cin >> verbrauch;
		cout << "pkw tank volume : ";
		cin >>  tankvolume;
		PKW* pkw = new PKW(name, maxspeed, verbrauch, tankvolume);
		v1.push_back(pkw);
		
	}
	for (int j = 1; j <= iFahrraderZahl; j++)
	{
		string name2;
		double maxspeed2;
		cout << " Fahrrad Name : ";
		cin >> name2;
		cout << " Fahrrad max speed :  ";
		cin >> maxspeed2;
		Fahrrad* fahrrad = new Fahrrad(name2, maxspeed2);
		v1.push_back(fahrrad);

	}
	cout << "ID       Name           :   MaxKmh         GesamtStrecke         GesamtZeit          verbrauch         tankinhalt " <<  endl;
	cout << "ID       Name           :   gechwindikeit  GesamtStrecke         GesamtZeit          MaxKmh             " << endl;
	for (dGlobalZeit = 0.0; dGlobalZeit <= 6; dGlobalZeit += 0.5)
	{
		for (int i = 0; i < v1.size(); i++)
		{
			v1[i]->vAbfertigung();
			if (fabs(dGlobalZeit - 3) < 0.001)
			{
				v1[i]->dTankken(-1);
			}
			v1[i]->vAusgabe();
			
		}

	}
	for (int j = 0; j < v1.size(); j++)
	{
		delete v1[j];
	}
}

void vAufgabe_3()
{
	system("color 06");
	
	
	//test von ausgabe operator 
	PKW apkw("lambo", 120,25,40);
	Fahrrad aFahrrad("meine", 25);
	cout << " test von Ausgabe operator \n" << " pKw \n";
	cout << "ID       Name           :   MaxKmh         GesamtStrecke        GesamtZeit"<< endl;
	cout << apkw << endl;
	cout << " Fahrrad \n";
	cout << "ID       Name           :   MaxKmh         GesamtStrecke        GesamtZeit" << endl;
	cout << aFahrrad << endl;

	//testing vergleich operator 
	PKW fiat(" fiat", 90, 25, 40);
	PKW ponto(" ponto", 120, 30, 45);
	cout << "testing operator < " << endl;
	for (dGlobalZeit = 0.0; dGlobalZeit < 6; dGlobalZeit += 1.00)
	{

		fiat.vAbfertigung();
		ponto.vAbfertigung();
	}
	if(fiat < ponto)
	{

		cout << "ponto faster than the fiat" << endl << endl;
	}
		else
		{
			cout << "ponto is behind the fiat" << endl << endl;
		}

	


	//testing difference between copy constructor and Assignement operator
	Fahrzeug aFahr("aFahr", 150);
	Fahrzeug aCopy(aFahr); //copyconstructor
	Fahrzeug ASSIGNEMENT("assi", 148);
	cout << "testing copy constructor " << endl;
	cout << "Erste Fahrzeug " << endl;
	cout << "ID       Name           :   MaxKmh          " << endl;

	cout << aFahr << endl;

	cout << "Copy Fahrzeug " << endl;
	cout << "ID       Name           :   MaxKmh          " << endl;

	cout << aCopy << endl; //hier jeder nimmt sein eigenes ID : benetzung von Cinialiserung
	          // wenn wir kein copy contructor erstellte hätten, wenn er implizeirt ertellt wurde beide object werden den gleich ID haben

	cout << "testing assignemnt operator" << endl;
	cout << "Assignement Fahrzeug before " << endl;
	cout << "ID       Name           :   MaxKmh          " << endl;

	cout << ASSIGNEMENT << endl;

	ASSIGNEMENT = aFahr; //zuweisung operator 

	cout << "Assignement Fahrzeug after " << endl;
	cout << "ID       Name           :   MaxKmh          " << endl;

	cout << ASSIGNEMENT << endl;  

 //Ein Kopierkonstruktor wird verwendet, um ein zuvor nicht initialisiertes Objekt aus den Daten eines anderen Objekts zu initialisieren.
//Ein Zuweisungsoperator verwendet die Daten eines zuvor initialisierten Objekts mit den Daten eines anderen Objekts. ...
//Die erste ist die Kopierinitialisierung, die zweite ist  einfach die Zuweisung.

} */
void vAufgabe_4()
{
	// creat weg object
	Wege* weg1 = new Wege("weg1",1000,Autobahn);

	//creat fahrzeug objects
	PKW *pkw1 = new PKW(" pkw1 ", 150, 20, 200);
	Fahrrad *fahrrad1 = new Fahrrad("fahrrad1", 150);
	PKW *fahrparkend = new PKW("parkend", 200,30,300);

	//add fahrzeug to weg 
	weg1->vAnnahme(pkw1);
	weg1->vAnnahme(fahrrad1);                   
	weg1->vAnnahme(fahrparkend, 3);

	cout << "ID        Name          :   lange                  " << endl;
	cout << (*weg1) << endl;
	
	cout << "ID       Name           :   MaxKmh         GesamtStrecke         GesamtZeit          abschnitstecke     verbrauch        tankinhalt " << endl;
	cout << "ID       Name           :   gechwindikeit  GesamtStrecke         GesamtZeit          abschnitstecke      MaxKmh             " << endl;
	
	//frage 4.5
	/* for (dGlobalZeit = 0.0;dGlobalZeit <= 6; dGlobalZeit += 1)
	{
		
		(*pkw1).vAbfertigung();
		cout << *pkw1 << endl;
		(*fahrrad1).vAbfertigung();
		cout << *fahrrad1 << endl;
	} 
	*/

	//frage 4.7
	for (dGlobalZeit = 0.0;dGlobalZeit <= 6; dGlobalZeit += 1)
	{
		weg1->vAbfertigung();
		cout << *pkw1 << endl;
		cout << *fahrrad1 << endl;
		cout << *fahrparkend << endl;
		
	}
	cout << (*weg1) << endl;
	 

	
} 
void vAufgabe_5() 
{

	//for debugger Frage 
	//Beim debugger es handelt sich um genaugikeit 2.999 != zu 3 , deswegen die start zeit punkt nicht gleich ist 
	//creat all needed objects
	
/*	Wege weg1("Rohrbach str", 300, Autobahn);
	//PKW* pkw1 = new PKW(" Audi", 100, 20, 400);
	PKW* pkw2 = new PKW(" Bmw", 200, 20, 400);

	//put the vehicule objects on the given road
	//weg1.vAnnahme(pkw1);
	weg1.vAnnahme(pkw2,3);

	cout << "ID        Name          :   lange                  " << endl;
	cout << weg1 << endl;

	cout << "ID       Name           :   MaxKmh         GesamtStrecke         GesamtZeit          abschnitstecke     verbrauch        tankinhalt " << endl;
	
	
	for (dGlobalZeit = 0.0;dGlobalZeit <= 4; dGlobalZeit += 0.25)
	{
		weg1.vAbfertigung();
		//cout << *pkw1 << endl;
		cout << *pkw2 << endl;
	
	} */
	

	//creat all objects
	Wege* diecembre = new Wege ("diecembre",500, Autobahn );
	Wege* novemvre = new Wege ("novemvre",500, landstrasse);
	PKW* lambo = new PKW(" lambo ",300,40,999);
	PKW* VW = new PKW("VW", 120, 20, 500);
	Fahrrad* beskla = new Fahrrad("beskla", 120);
	int Koordinaten[32] = { 320,200,150,60,80,90,70,250,170,300,320,300,320,420,350,510,500,570,680,570,970,500,970,390,850,300,680,300,680,40,320,150 };

    //add fahrzeug to road
	diecembre->vAnnahme(lambo);
	diecembre->vAnnahme(VW);
	novemvre->vAnnahme(beskla,5);
	

	//Erstelle Grafik
	bInitialisiereGrafik(1000, 1000);
	bZeichneStrasse(diecembre->getName(), novemvre->getName(), 500, 16, Koordinaten);
	vSetzeZeit(dGlobalZeit);

	//prints wege
	cout << "ID        Name          :   lange                  " << endl;
	cout << (*diecembre) << endl;
	cout << (*novemvre) << endl;
	
	
	cout << "ID       Name           :   MaxKmh         GesamtStrecke         GesamtZeit          abschnitstecke     verbrauch        tankinhalt " << endl;
	cout << "ID       Name           :   gechwindikeit  GesamtStrecke         GesamtZeit          abschnitstecke      MaxKmh             " << endl;

	for (dGlobalZeit = 0.0;dGlobalZeit <= 8; dGlobalZeit += 0.15)
	{
		//draw fahrzeuge 
		lambo->vZeichnen(diecembre);
		VW->vZeichnen(diecembre);
		beskla->vZeichnen(novemvre);

		//strasse abfertigung
		diecembre->vAbfertigung();
		novemvre->vAbfertigung();

		vSetzeZeit(dGlobalZeit);
		vSleep(500);
		
		//prints all fahrzeuge
		cout << *lambo << endl;
		cout << *VW << endl;
		cout << *beskla << endl;
		
	}

	//end grafik
	vBeendeGrafik();

	//delete all dynamic data
	delete diecembre;
	delete novemvre;
	delete lambo;
	delete beskla;
	delete VW; 
}
void vAufage_6()
{
	//creat all objects
	Wege* alweg = new Wege("alweg", 500, landstrasse);
	Wege* delweg = new Wege("delweg", 500, landstrasse);

	PKW* lambo = new PKW(" lambo ", 120, 10, 300);
	PKW* VW = new PKW("VW", 60, 20, 200);
	Fahrrad* Avanti = new Fahrrad("Avanti", 75);
	Fahrrad* Ariel = new Fahrrad("Ariel", 20);
	Fahrrad* Alan = new Fahrrad("Alan", 100);
	Fahrrad* Abici = new Fahrrad("Abici", 60);
	Fahrrad* Alcyon = new Fahrrad("Alcyon", 150);

	int Koordinaten[4] = { 100,180,230,240 };

	//Erstelle Grafik
	bInitialisiereGrafik(500, 500);
	bZeichneStrasse("alweg", "delweg", 500, 2, Koordinaten);
	vSetzeZeit(dGlobalZeit);

	//add fahrzeug to road alweg
	alweg->vAnnahme(lambo);
	alweg->vAnnahme(VW,1.2);
	//add fahrzeug to road delweg
	delweg->vAnnahme(Avanti,1.75);
	delweg->vAnnahme(Ariel,2.25);
	delweg->vAnnahme(Alan,3.0);
	delweg->vAnnahme(Abici);
	delweg->vAnnahme(Alcyon);

	//prints wege
	cout << "ID        Name          :   lange                  " << endl;
	cout << (*alweg) << endl;
	cout << (*delweg) << endl;


	cout << "ID       Name           :   MaxKmh         GesamtStrecke         GesamtZeit          abschnitstecke     verbrauch        tankinhalt " << endl;
	cout << "ID       Name           :   gechwindikeit  GesamtStrecke         GesamtZeit          abschnitstecke      MaxKmh             " << endl;
	cout << endl;

	for (dGlobalZeit = 0.0;dGlobalZeit <= 6; dGlobalZeit += 0.25)
	{
		vSetzeZeit(dGlobalZeit);
		vSleep(500);    //sleep pauses the program for 500 ms 

		//draw fahrzeuge 
	    lambo->vZeichnen(alweg);
		 VW->vZeichnen(alweg);
		Avanti->vZeichnen(delweg);
		Ariel->vZeichnen(delweg);
		Alan->vZeichnen(delweg);
		Abici->vZeichnen(delweg);
		Alcyon->vZeichnen(delweg); 


		//strasse abfertigung
		alweg->vAbfertigung();
	    delweg->vAbfertigung();


		cout << (*alweg) << endl;
		cout << (*delweg) << endl;

		//print all fahrzeuge data
		/*cout << *lambo << endl;
	    cout << *VW << endl;
		cout << *Avanti << endl;
		cout << *Ariel << endl;
		cout << *Alan << endl;
		cout << *Abici << endl;
		cout << *Alcyon << endl; */ 
	}

	//end grafik
	vBeendeGrafik();




}
void vAufgabe_6a ()
{
	//creat a list  of integers
	LazyListe<int> integers;

	//creat list ietrator 
	LazyListe<int> ::iterator it;

	//creat the random integers and fill the list 
	for ( int i = 0 ; i < 10 ; i++) 
	{
		int random = rand() % 10 + 1;  //gibt randoms zwichen 1-10
		integers.push_back(random);   // add number to list 
	}

	//transfer changes from lazy aktion to lazylist
	integers.vAktualisieren();

	cout << " List of random numbers between 1 --- 10  " << endl;

	//print the list 
	for ( it = integers.begin(); it != integers.end(); it++)
	{
		cout << (*it) << " ";

		// delete all elemnts bigger than 5
		if ((*it) > 5)
		{
			integers.erase(it);
		}
	}

	cout << endl;
	
	for (it = integers.begin(); it != integers.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
	cout << " List of random numbers smaller than or equal to 5 " << endl;

	//transfer changes in lazy aktion to lazylist
	integers.vAktualisieren();

	//print the list a second Time 
	for (it = integers.begin(); it != integers.end(); it++)
	{
		cout << (*it) << " ";
	}

	cout << endl;

	//add 2 random numbers between 0--99
	int anfang = rand() % 100;
	int end    = rand() % 100;
	integers.push_front(anfang);
	integers.push_back(end);

	//transfer changes in lazy aktion to lazylist
	integers.vAktualisieren();

	cout << " Last list of random numbers  " << endl;

	//print the list a third Time 
	for (it = integers.begin(); it != integers.end(); it++)
	{
		cout << (*it) << " ";
	}

}

void vAufgabe_7_2 ()
{

	//frage 7.2
	//Wege Erstellen
     Wege* Roherbach = new Wege("Roherbach", 250, Autobahn,false);
	Wege* Bismarkt = new Wege("Bismarkt", 250, Autobahn);

	// Fahrzeuge erstellen
	PKW* buggati = new PKW("Buggati", 180, 10, 600);
	PKW* Jeep = new PKW("Jeep", 150, 5, 600);
	Fahrrad* Asteron = new Fahrrad ("Asteron" ,70);

	Roherbach->vAnnahme(Asteron, 0.5);
	Roherbach->vAnnahme(buggati, 3.5);

	int Koordinaten[4] = { 500,20,400,800 };

	//Erstelle Grafik
	bInitialisiereGrafik(1000, 1000);
	bZeichneStrasse("Roherbach", "Bismarkt", 250, 2, Koordinaten);
	vSetzeZeit(dGlobalZeit);

	//assure  that annahme will be excuted one time 
	int i = 0;

	//abfertigung der Weg
	for (dGlobalZeit = 0.0;dGlobalZeit <= 10; dGlobalZeit += 1)
	{
		if (abs( (dGlobalZeit -5) )< 0.0001  && i < 1) 
		{
			Roherbach->vAnnahme(Jeep,6);
			Jeep->vZeichnen(Roherbach);
			i++;
		} 
		
		vSetzeZeit(dGlobalZeit);
		vSleep(500);    //sleep pauses the program for 500 ms 

		//weg abfertigung 
		Roherbach->vAbfertigung();

		//draw fahrzeuge 
		buggati->vZeichnen(Roherbach);
		Jeep->vZeichnen(Roherbach);
		Asteron->vZeichnen(Roherbach);

		cout << *Roherbach  << dGlobalZeit << endl;
	}  
	}
void vAufgabe_7_3()
{
	// frage 7.3 : uberhole verbote
	Wege* Roherbach = new Wege("Roherbach", 400, Autobahn, true);
	Wege* Bismarkt = new Wege("Bismarkt", 400, Autobahn, true);

	// Fahrzeuge erstellen
	PKW* buggati = new PKW("Buggati", 200, 10, 600);
	PKW* Jeep = new PKW("Jeep", 100, 5, 600);
	PKW* ferrari = new PKW("ferrari", 50, 5, 600);



	//change between to proove uberholverbot
	Roherbach->vAnnahme(Jeep);
	Roherbach->vAnnahme(buggati);
	Roherbach->vAnnahme(ferrari);




	int Koordinaten[4] = { 500,20,400,800 };

	//Erstelle Grafik
	bInitialisiereGrafik(1000, 1000);
	bZeichneStrasse("Roherbach", "Bismarkt", 400, 2, Koordinaten);
	vSetzeZeit(dGlobalZeit);

	cout << *Roherbach << endl;
	cout << "ID       Name           :   MaxKmh         GesamtStrecke         GesamtZeit          abschnitstecke     verbrauch        tankinhalt " << endl;

	for (dGlobalZeit = 0.0;dGlobalZeit <= 5; dGlobalZeit += 0.25)
	{
	vSetzeZeit(dGlobalZeit);
	vSleep(500);    //sleep pauses the program for 500 ms

	//draw fahrzeuge

	buggati->vZeichnen(Roherbach);
	ferrari->vZeichnen(Roherbach);
	Jeep->vZeichnen(Roherbach);


	//weg abfertigung
	Roherbach->vAbfertigung();

	cout << *buggati << endl;
	cout << *Jeep << endl;
	cout << *ferrari << endl;
	}
}
void vAufgabe_8()
{
	//erste Kreuzungen erstellen 
	kreuzung* Kr1 = new kreuzung("kr1");
	kreuzung* Kr2 = new kreuzung("Kr2", 1000);
	kreuzung* Kr3 = new kreuzung("Kr3");
	kreuzung* Kr4 = new kreuzung("Kr4");


	//Verbinden der Kreuzungen mit erstellen der Wege
	Kr1->vVerbinde("W12", "W21", 40, Kr2, Innerorts, true);
	Kr2->vVerbinde("W23a", "W32a", 115, Kr3, Autobahn, false);
	Kr2->vVerbinde("W23b", "W32b", 40, Kr3, Innerorts, true);
	Kr2->vVerbinde("W24", "W42", 55, Kr4, Innerorts, true);
	Kr3->vVerbinde("W34", "W43", 85, Kr4, Autobahn, false);
	Kr4->vVerbinde("W44a", "W44b", 130, Kr4, landstrasse, false);


	//Erstellen der PKW's
	PKW* lambo = new PKW("lambo", 80, 10, 80);
	PKW* buggati = new PKW("buggati", 120, 30, 100);

	//Erstellen der Fahrräder
	Fahrrad* Aslo = new Fahrrad("Aslo", 35);
	Fahrrad* Femto = new Fahrrad("Femto", 40);


	//Annehmen der Fahrzeuge an der Kreuzung 1
	Kr1->vAnnahme(buggati, 0.75);
	Kr1->vAnnahme(lambo, 2);

	//Annahme von fahrräder auf der kreuzung 1
	Kr1->vAnnahme(Aslo, 1.5);
	Kr1->vAnnahme(Femto, 1);


	//Grafikausgabe
	bInitialisiereGrafik(1000, 1000);

	int Koordinaten1[4] = { 680, 40, 680, 300 };
	int Koordinaten2[12] = { 680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570 };
	int Koordinaten3[4] = { 680, 570, 680, 300 };
	int Koordinaten4[4] = { 680, 300, 320, 300 };
	int Koordinaten5[10] = { 680, 570, 500, 570, 350, 510, 320, 420, 320, 300 };
	int Koordinaten6[14] = { 320, 300, 320, 150, 200, 60, 80, 90, 70, 250, 170, 300, 320, 300 };


	//strassen zeichnen 
	bZeichneStrasse("W12", "W21", 40, 2, Koordinaten1);
	bZeichneStrasse("W23a", "W32a", 115, 6, Koordinaten2);
	bZeichneStrasse("W23b", "W32b", 40, 2, Koordinaten3);
	bZeichneStrasse("W24", "W42", 55, 2, Koordinaten4);
	bZeichneStrasse("W34", "W43", 85, 5, Koordinaten5);
	bZeichneStrasse("W44a", "W44b", 130, 7, Koordinaten6);

	//krezungen zeichnen 																						
	bZeichneKreuzung(680, 40);
	bZeichneKreuzung(680, 300);
	bZeichneKreuzung(680, 570);
	bZeichneKreuzung(320, 300); 

	//Kontrolle Kreuzung
	cout << "ID        Name          :   lange        Enthaltene Fahrzeuge                     Tank Inhalt       Enthaltene Wege            " << endl;
	cout << endl;
	cout << *Kr1 << endl;
	cout << *Kr2 << endl;
	cout << *Kr3 << endl;
	cout << *Kr4 << endl; 



	//Abfertigung
	for (dGlobalZeit = 1; dGlobalZeit < 6; dGlobalZeit += 0.25)
	{
		vSetzeZeit(dGlobalZeit);
		vSleep(500);

		//kreuzungen abfertigung : => wege abfertigen => fahrzeuge abfertigen
		Kr1->vAbfertigung();
		Kr2->vAbfertigung();
		Kr3->vAbfertigung();
		Kr4->vAbfertigung();

		//kreuzungen zeichen 
	    Kr1->Kreuzungzecihen();
		Kr2->Kreuzungzecihen();
		Kr3->Kreuzungzecihen();
		Kr4->Kreuzungzecihen();



	}

	vBeendeGrafik(); 
}

void vAufgabe_9()
{

	//open VO.dat as ifstream
   /* ifstream userstream("VO.dat");
	 char a[80];

	//if file don't open print error
	if (!userstream)
	{
	cout << "While opening a file an error is encountered" << endl;
	}
	else
	{
	cout << "File is successfully opened" << endl;

	}

	/*	while (!userstream.eof())

	{

	userstream >> a;

	cout << a << endl;

	} 

    try
	{
	//Erzeugen der drei Objekte und einlesen der Daten
	string Name1;
    string name2, name3 ;
	double Speed1,Speed2, verbrauch,tankenvolume, kreuzungtankvolume;

	//read text from file stream
	//PKW
	userstream >> Name1 >> Speed1 >> verbrauch >> tankenvolume;
	//Fahrrad
	userstream >> name2 >> Speed2;
	//Kreuzung
	userstream >> name3 >> kreuzungtankvolume;

	//asssign data to objects
	PKW* Pkw = new PKW(Name1, Speed1, verbrauch, tankenvolume);
	Fahrrad* fahrrad = new Fahrrad(name2, Speed2);
	kreuzung* kreuz = new kreuzung(name3, kreuzungtankvolume);

	cout << "ID       Name           :   MaxKmh         GesamtStrecke         GesamtZeit          abschnitstecke     verbrauch        tankinhalt " << endl;
	cout << "ID       Name           :   gechwindikeit  GesamtStrecke         GesamtZeit          abschnitstecke      MaxKmh             " << endl;
	cout << endl;
	//print all objects
	cout << *Pkw << endl;
	cout << *fahrrad << endl;

	cout << " Crossing Data " << endl;
	cout << *kreuz << endl;
	}
	catch (string exception )
	{
	cout << exception << endl;
	}  */

	//map test 

	try
	{
		string name = "";

		cout << "Please print name " << endl;
		cin >> name;

		AktivesVO* obj = AktivesVO::ptObjekt(name);
		cout << obj << endl << *obj << endl;
	}
	catch (string* Fehlermeldung)
	{
		cout << *Fehlermeldung << endl;
	}  
}

void vAufageb_9_Simu ()
{
	ifstream userstream("Simu.dat");
	if (!userstream)
	{
		cout << "While opening a file an error is encountered" << endl;
	}
	else
	{
		cout << "File is successfully opened" << endl;

	}
	
	try
	{
		Welt* THEwelt = new Welt();
		THEwelt->vEinlesen(userstream);
		THEwelt->vSimulation();
	}
	catch (string* Fehlermeldung)
	{
		cout << *Fehlermeldung << endl;
	}
	

}
void vAufageb_9_Grafik()
{
	ifstream userstream("SimuDisplay.dat");
	if (!userstream)
	{
		cout << "While opening a file an error is encountered" << endl;
	}
	else
	{
		cout << "File is successfully opened" << endl;

	}
	//grafik inialisierung
	bInitialisiereGrafik(1000, 1000);
	try {
	
		Welt* world = new Welt();
		world->vEinlesenGrafik(userstream);
		cout << "ID        Name          :   lange        Enthaltene Fahrzeuge                     Tank Inhalt       Enthaltene Wege            " << endl;
		cout << endl;
		for (dGlobalZeit = 1; dGlobalZeit < 6; dGlobalZeit += 0.05)
		{
			vSetzeZeit(dGlobalZeit);
			vSleep(500);
			world->vSimulation();
		}

	}
	catch (string* Fehlermeldung)
	{
		cout << *Fehlermeldung << endl;
	}
	vBeendeGrafik();

}
int main () 
{
	//vAufgabe_1();
	//vAufagbe_1_deb();
	//vAufgabe_2();1
	//vAufgabe_3();
	//vAufgabe_4();
	//vAufgabe_5();
	//vAufage_6();
	//vAufgabe_6a();
	//vAufgabe_7_2();
	//vAufgabe_7_3();
	//vAufgabe_8();
	//vAufgabe_9();  
     // vAufageb_9_Simu();
	vAufageb_9_Grafik();

	return 0;
}
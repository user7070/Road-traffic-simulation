#include "Fahrzeug.h"
#include<string>
#include<iostream>
#include <vector>
#include <math.h>
#include "PKW.h"
#include "Fahrrad.h"
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
void vAufgabe_1() 
{
	system("color 02");
	cout << " testing ..........  " << endl;
	cout << " Aufgabe 1 " << endl;

	//static erzeugen
	//erste construktor
	Fahrzeug fahr1;
	fahr1.vGetName("lambo");
	fahr1.vGetSpeed(350);
	//zweites construktor
	Fahrzeug fahr2(" polo ");
	fahr2.vGetSpeed(130);
	//dritte constructor 
	Fahrzeug fahr12(" VW", 120);
	
	//dynamisch erstellen 
	//erste construktor
	Fahrzeug* fahr3 = new Fahrzeug;
	fahr3->vGetName(" merce");
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

}
int main () 
{
	//vAufgabe_1();
	//vAufagbe_1_deb();
	vAufgabe_2();
	//vAufgabe_3();
	return 0;
}
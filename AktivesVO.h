//Gemeinschaften von fahrzeug und Weg : AktivesVo ist	bstrakt class
#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<vector>
#include "SimuClient.h"
#include <map>

using namespace std;

extern double dGlobalZeit;

class AktivesVO
{
public:

	//standard constructor and destructor 
	AktivesVO();
	AktivesVO(string name);
   virtual ~AktivesVO();

	//ausgabe functions
	virtual ostream& ostreamAusgabe(ostream& ausgabe) ;
	virtual void vAusgabe();

	//eingabe functiuon
	virtual istream& istreamEingabe(istream& eingabe);

	//rein virtuall function
	virtual void vAbfertigung() = 0;

	//gemeinsam Inialisiurung von variabeln
	virtual void vInitialisierung();

	//rein virtuall function to get instanz name 
    virtual	string getName( ) ;

	//zugreif zu entscprechende zeiger 
	static AktivesVO* ptObjekt(string name);
	
protected :

	//gemeinsam variablen von fahrzeuge und Weg
	string p_sName;
	int p_iID;
	double p_dZeit;	    //lokal zeit 

	//map with key : the string , and value : pointer to AktiveVO
	static	map <string, AktivesVO*> themap;   //declared as static so we can call members without calling the class 
											   //da ptobject ist static hat sie zugriff nur zu static members 
	                                           // to not creat a map each time a fucntion is called 


private:                                      
	static int p_iMaxID;
};

// ausgabe operator overloading
ostream& operator<<(ostream& ausgabe, AktivesVO& element);

// eingabe operator overloading
istream& operator>>(istream& einagbe, AktivesVO& element);

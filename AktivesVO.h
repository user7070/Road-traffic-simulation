//Gemeinschaften von fahrzeug und Weg : AktivesVo ist	bstrakt class
#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<vector>
#include "SimuClient.h"

using namespace std;

extern double dGlobalZeit;

class AktivesVO
{
public:

	//standard constructor and destructor 
	AktivesVO();
   virtual ~AktivesVO();

	//ausgabe functions
	virtual ostream& ostreamAusgabe(ostream& ausgabe) ;
	virtual void vAusgabe();

	//rein virtuall function
	virtual void vAbfertigung() = 0;

	//gemeinsam Inialisiurung von variabeln
	virtual void vInitialisierung();

	//rein virtuall function to get instanz name 
    virtual	string getName( ) = 0;



protected :

	//gemeinsam variablen von fahrzeuge und Weg
	string p_sName;
	int p_iID;
	double p_dZeit;	    //lokal zeit 

private:
	static int p_iMaxID;
};

//operator overloading
ostream& operator<<(ostream& ausgabe, AktivesVO& element);
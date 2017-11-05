
//Circuit.h

#ifndef circuit_h
#define circuit_h

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include"fonctions.h"

class Circuit
{
	//Fonctions amies
		//Aucune
		
	public:
	//Constructeurs
	Circuit(const std::string& nom, const unsigned short int& taille, const unsigned short int& virages, const unsigned short int& climat, const unsigned short int& difficulte, const unsigned short int& denivele);

	//destructeur
	~Circuit();
	
	//Methodes statiques
	static void chargerCircuit(const unsigned short int& id, Circuit*& CircuitCourant);
	static unsigned short int listerCircuits();
	static unsigned short int construireMeteo(const unsigned short int& climat);
	static unsigned short int construireVent();
	static std::string construireClimat(const unsigned short int& climat);
	
	//Accesseurs
	std::string getNom() const;
	unsigned short int getTaille() const;
	unsigned short int getVirages() const;
	unsigned short int getMeteo() const;
	unsigned short int getVent() const;
	unsigned short int getDifficulte() const;
	unsigned short int getDenivele() const;
	
	//Mutateurs
	
	//Méthodes
		
	//Opérateurs méthodes ( =, (), [] )
	

	protected:
	//Attributs
	std::string m_nom;
	unsigned short int m_taille;
	unsigned short int m_virages;
	unsigned short int m_meteo;
	unsigned short int m_vent;
	std::string m_climat;
	unsigned short int m_difficulte;
	unsigned short int m_denivele;	
};


#endif
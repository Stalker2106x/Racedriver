
//Profil.h

#ifndef Profil_h // _h car erreur de compil sinon
#define Profil_h // idem

#include <iostream>
#include <string>
#include <cfloat>
#include <uuid/uuid.hpp>            // librairie de classe
#include <uuid/uuid_generators.hpp> // generateur d'id unique
#include <uuid/uuid_io.hpp>

#include "sha.h"
#include "fonctions.h"
#include "Voiture.h"


class Profil
{
	//Fonctions amies
		//Aucune

	public:
	//constructeurs
	Profil(const std::string& uuid, const unsigned short int& numero, const std::string& nom); //Nouveau Profil
	Profil(const std::string& uuid, const unsigned short int& numero, const std::string& nom, const unsigned int& credits, const bool& sauvegardeAuto, const unsigned short int& difficulte, const unsigned short int& nbBox, const unsigned short int& nbCourses, const unsigned short int& victoires, const unsigned short int& defaites, const unsigned short int& accidents, const unsigned short int& creditsGagnes, const unsigned short int& nbCoursesCL, const unsigned short int& victoiresCL, const unsigned short int& defaitesCL, const unsigned short int& accidentsCL, const unsigned short int& creditsGagnesCL, const unsigned short int& voituresAchetees); //Profil Chargé

	//Destructeur
	~Profil();

	//Methodes statiques
	static void listerSauvegardes();
	static unsigned short int compterSauvegardes();
	static void supprimerProfil(const unsigned short int& numeroSave);
	static bool chargerProfil(const unsigned short int& numeroSave, Profil*& ProfilCharge);
	static void creerProfil(std::string& nom, Profil*& ProfilCree);
	static bool compatible(Profil& Player, const unsigned short int& numeroBox, const char& rangNewPiece);

	//Accesseurs et Mutateurs
	std::string getUuid() const;	//profil
	unsigned short int getNumero() const;
	std::string getNom() const;
	unsigned int getCredits() const;
	unsigned short int getNbBox() const;
	Voiture* getBox(const unsigned short int& numeroBox) const;
	unsigned short int getDifficulte() const;
	std::string getDifficulteString() const;
	bool getSauvegardeAuto() const;

	unsigned short int getNbCourses() const;	//stats
	unsigned short int getVictoires() const;
	unsigned short int getDefaites() const;
	unsigned short int getAccidents() const;
	float getVDRatio() const;
	unsigned short int getCreditsGagnes() const;
	unsigned short int getVoituresAchetees() const;

	void setMoteurVoiture(const unsigned short int& numeroBox, Moteur* newMoteur, const unsigned short int& idMoteur);
	void setBox(const unsigned short int& numeroBox, const std::string& marque, const std::string& modele, const unsigned short int& idMoteur, const unsigned short int& idSpoiler, const unsigned short int& idPriseAir, const char& rang, const unsigned short int& nitroMax, const unsigned short int& aerodynamismeVoiture, const unsigned short int& idPneus, const unsigned short int& pneus, const unsigned short int& etat);
	void setBox(const unsigned short int& numeroBox, Voiture* Voiture);
	void setBox(const unsigned short int& numeroBox);
	void setDifficulte(const unsigned short int& newDifficulte);
	void setSauvegardeAuto(const bool& valeur);

	void ajouterVoitureAchetee();
	void ajouterCreditsGagnes(const int& somme);
	void ajouterCredits(const int& somme);
	void ajouterCourse();
	void ajouterVictoire();
	void ajouterDefaite();
	void ajouterAccident();

	//Méthodes
	bool boxVide(unsigned short int numeroBox);

	void changerNom(const std::string& newNom);

	void acheterBox();
	bool payer(const unsigned short int& prix);
	void sauvegarderProfil();

	//Opérateurs méthodes
		//Aucun

	protected:
	//Attributs
	std::string m_uuid; //unique identifier
	unsigned short int m_numero;
	std::string m_nom;
	int m_credits;

	unsigned short int m_difficulte;
	unsigned short int m_nbBox;  //gestion vehicules
	Voiture* m_box[5];

	//Stats
	unsigned short int m_nbCourses;
	unsigned short int m_victoires;
	unsigned short int m_defaites;
	unsigned short int m_accidents;
	unsigned short int m_creditsGagnes;
	unsigned short int m_voituresAchetees;

	//Stats course libre
	unsigned short int m_nbCoursesCL;
	unsigned short int m_victoiresCL;
	unsigned short int m_defaitesCL;
	unsigned short int m_accidentsCL;
	unsigned short int m_creditsGagnesCL;

	bool m_sauvegardeAuto;
};

bool operator!=(Profil& Player, Profil& PlayerSaved);

#endif
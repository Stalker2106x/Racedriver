//Voiture.cpp
#include "Voiture.hh"
#include "Menu.hh"

Voiture::Voiture(const std::string& marque, const std::string& modele, const int& idMoteur, const int& idSpoiler, const int& idAirIntake, const char& rang, const int& nitroMax, const int& aerodynamismeVoiture, const int& idTires, const int& etat)
 : m_moteur(Moteur::chargerMoteur(idMoteur, marque)), m_idMoteur(idMoteur), m_spoiler(Spoiler::collection[idSpoiler]), m_idSpoiler(idSpoiler),
 	 m_priseAir(AirIntake::collection[idAirIntake]), m_idAirIntake(idAirIntake), m_niveauNitro(nitroMax),
	 m_aerodynamisme((m_priseAir.getAerodynamic()/3 )+(m_spoiler.getAerodynamic()/3)+(aerodynamismeVoiture/3)+1),
	 m_vitesse(m_moteur->getVitesse()+(m_aerodynamisme/3)), m_acceleration(((m_niveauNitro+m_moteur->getAcceleration())+(m_aerodynamisme))/10),
	 m_marque(marque), m_modele(modele), m_rang(rang), m_typeCarburant(m_moteur->getTypeCarburant()), m_consommation(m_moteur->getConsommation()),
	 m_nitroMax(nitroMax), m_aerodynamismeVoiture(aerodynamismeVoiture), m_pneus(Tires::collection[idTires]), m_idTires(idTires), m_etat(etat)
{

}

Voiture::~Voiture()
{
	delete m_moteur;
}

Voiture* Voiture::chargerVoiture(const int& id, const char& rangCharge)
{
	Voiture* VoitureCharge = 0; //moteur a creer
	std::string var=""; //contient les lignes du fichier
	std::string sRang;
	sRang = rangCharge;
	std::string chemin = "Data/Voitures/"+sRang+".cdx";
	std::ifstream engine(chemin.c_str());
	std::istringstream iss;

	if(!engine)
	{
		Menu::error("Echec de lecture du fichier "+sRang+".cdx");
	}
	else
	{
		int idActuel = id + 1; //indique l'id actuellement lu dans le fichier
		while(idActuel!=id && std::getline(engine, var)) //on lit dans le fichier
		{
			//on utilise while(std::getline(flux, string) pour "Tant qu'il y a une ligne a lire"
			iss.str(var.substr(0,var.find_first_of(";"))); //on transforme le premier char en int pour etre compare
			if(iss>>idActuel)
			{
			}
			else
			{
				Menu::error("Fichier corrompu1a.");
			}
			iss.clear();
		}
		if(idActuel==id)
		{
			int curseur;
			curseur=var.find_first_of(";");
			var.erase(0,curseur+1);

			curseur=var.find_first_of(";");
			std::string marque=var.substr(0,curseur);
			var.erase(0,curseur+1);

			curseur=var.find_first_of(";");
			std::string modele=var.substr(0,curseur);
			var.erase(0,curseur+1);

			curseur=var.find_first_of(";");
			std::string sIdMoteur=var.substr(0,curseur);
			var.erase(0,curseur+1);

			curseur=var.find_first_of(";");
			std::string sIdSpoiler=var.substr(0,curseur);
			var.erase(0,curseur+1);

			curseur=var.find_first_of(";");
			std::string sIdAirIntake=var.substr(0,curseur);
			var.erase(0,curseur+1);

			curseur=var.find_first_of(";");
			std::string sNitroMax=var.substr(0,curseur);
			var.erase(0,curseur+1);

			std::string sAerodynamisme=var;

			int idMoteur;
			int idSpoiler;
			int nitroMax;
			int idAirIntake;
			int aerodynamisme;

			iss.str(sIdMoteur);
			if (iss>>idMoteur)
			{
			}
			else
			{
				Menu::error("Fichier corrompu1b.");
			}
			iss.clear();
			iss.str(sIdSpoiler);
			if (iss>>idSpoiler)
			{
			}
			else
			{
				Menu::error("Fichier corrompu2.");
			}
			iss.clear();
			iss.str(sIdAirIntake);
			if (iss>>idAirIntake)
			{
			}
			else
			{
				Menu::error("Fichier corrompu3.");
			}
			iss.clear();
			iss.str(sNitroMax);
			if (iss>>nitroMax)
			{
			}
			else
			{
				Menu::error("Fichier corrompu4.");
			}
			iss.clear();
			iss.str(sAerodynamisme);
			if (iss>>aerodynamisme)
			{
			}
			else
			{
				Menu::error("Fichier corrompu4.");
			}
			iss.clear();
			VoitureCharge = new Voiture(marque, modele, idMoteur, idSpoiler, idAirIntake, rangCharge, nitroMax, aerodynamisme, 1);
		}
		else
		{
			Menu::error("Fichier corrompu.");
		}
	}
	return VoitureCharge;
}

void Voiture::listerVoitures(const char& rang)
{
	std::string chemin ="Data/Voitures/" + std::string(&rang) + ".cdx";
	std::string var;
	int prixMoteur=0;

	std::ifstream flux(chemin.c_str());
	if(flux)
	{
		int curseur;
		Terminal::get() <<"   |Marque   |Modele     |Capacite nitro  |Aerodynamisme  |Prix  |\n\n";
		while(std::getline(flux, var))
		{
			curseur=var.find_first_of(";");
			std::string id=var.substr(0,curseur);
			var.erase(0,curseur+1);
			curseur=var.find_first_of(";");
			std::string marque=var.substr(0,curseur);
			var.erase(0,curseur+1);
			curseur=var.find_first_of(";");
			std::string modele=var.substr(0,curseur);
			var.erase(0,curseur+1);
			curseur=var.find_first_of(";");
			std::string sIdMoteur=var.substr(0,curseur);
			var.erase(0,curseur+1);
			curseur=var.find_first_of(";");
			var.erase(0,curseur+1);
			curseur=var.find_first_of(";");
			var.erase(0,curseur+1);
			curseur=var.find_first_of(";");
			std::string sNitroMax=var.substr(0,curseur);
			std::string ssNitroMax= sNitroMax + "L";
			var.erase(0,curseur+1);
			std::string sAerodynamisme=var;
			std::string ssAerodynamisme = sAerodynamisme + "%";
			std::string espace1;
			std::string espace2;
			std::string espace3;
			std::string espace4;
			std::string espace5;
			if(marque.size()<10)
			{
				for (size_t i=0; i<10-marque.size(); i++)
				{
					espace1+=" ";
				}
			}
			if(modele.size()<12)
			{
				for (size_t i=0; i<12-modele.size(); i++)
				{
					espace2+=" ";
				}
			}
			if(ssNitroMax.size()<17)
			{
				for (size_t i = 0; i<17 - ssNitroMax.size(); i++)
				{
					espace3+=" ";
				}
			}
			if(ssAerodynamisme.size()<16)
			{
				for (size_t i=0; i<16-ssAerodynamisme.size(); i++)
				{
					espace4+=" ";
				}
			}
			if(id.size()<3)
			{
				for (size_t i=0; i<3-id.size(); i++)
				{
					espace5+=" ";
				}
			}
			int nitroMax;
			int aerodynamisme;
			int idMoteur;
			std::istringstream iss(sNitroMax);
			if (iss>>nitroMax)
			{
			}
			else
			{
				Menu::error("Fichier corrompu9.");
			}
			iss.clear();
			iss.str(sAerodynamisme);
			if (iss>>aerodynamisme)
			{
			}
			else
			{
				Menu::error("Fichier corrompu10.");
			}
			iss.clear();
			iss.str(sIdMoteur);
			if (iss>>idMoteur)
			{
			}
			else
			{
				Menu::error("Fichier corrompu11.");
			}
			Moteur::infoMoteur(idMoteur, marque, prixMoteur);
			int prix = roundf( (prixMoteur + 0 + 0 + 0 )  *0.85+ (( aerodynamisme + nitroMax ) * 100)+ (( vRang(rang) - 1 ) * 20000));
			Terminal::get() << id << "." << espace5 << marque << espace1 << modele << espace2 << ssNitroMax << espace3 << ssAerodynamisme << espace4 << prix << "c\n";
		}
	}
}

int Voiture::compterVoitures(const char& rang)
{
	std::string sRang;
	sRang=rang;
	std::string chemin ="Data/Voitures/"+sRang+".cdx";
	std::ifstream engine(chemin.c_str());
	int id; //indique l'id actuellement lu dans le fichier
	int nbVoiture=0;
	std::string var;

	if(engine)
	{
		while(std::getline(engine, var))
		{
			 //on lit dans le fichier
			std::istringstream iss(var.substr(0,var.find_first_of(";"))); //on transforme le premier char en int pour etre compare
			if(iss>>id)
			{
				nbVoiture++;
			}
			else
			{
				Menu::error("Fichier corrompu6");
			}
			//on utilise while(std::getline(flux, string) pour "Tant qu'il y a une ligne a lire"
		}
	}
	else
	{
		Menu::error("Fichier corrompu7");
	}
	return nbVoiture;
}

void Voiture::infoVoiture(const int& id, const char& rang, std::string& marque, std::string& modele, int& idMoteur, int& nitroMax, int& aerodynamisme, int& prix)
{
	std::string var; //contient les lignes du fichier
	std::string sRang;
	sRang=rang;
	std::string nomMoteur;
	std::string chemin ="Data/Voitures/"+sRang+".cdx";
	std::ifstream engine(chemin.c_str());

	if(!engine)
	{
		Menu::error("Echec de lecture du fichier "+sRang+".cdx");
	}
	else
	{
		int idActuel; //indique l'id actuellement lu dans le fichier
		while(idActuel!=id && std::getline(engine, var))
		{
			std::istringstream iss(var.substr(0,var.find_first_of(";"))); //on transforme le premier char en int pour etre compare
			if(iss>>idActuel)
			{
			}
			else
			{
				Menu::error("Fichier corrompu8");
			}
		}
		if(idActuel==id)
		{
			int curseur;
			var.erase(0,var.find_first_of(";")+1);
			curseur=var.find_first_of(";");
			marque=var.substr(0,curseur);
			var.erase(0,curseur+1);
			curseur=var.find_first_of(";");
			modele=var.substr(0,curseur);
			var.erase(0,curseur+1);
			curseur=var.find_first_of(";");
			std::string sIdMoteur=var.substr(0,curseur);
			var.erase(0,curseur+1);
			curseur=var.find_first_of(";");
			std::string sIdSpoiler=var.substr(0,curseur);
			var.erase(0,curseur+1);
			curseur=var.find_first_of(";");
			std::string sIdAirIntake=var.substr(0,curseur);
			var.erase(0,curseur+1);
			curseur=var.find_first_of(";");
			std::string sNitro=var.substr(0,curseur);
			var.erase(0,curseur+1);
			std::string sAerodynamisme=var;
			std::istringstream iss(sNitro);
			if (iss>>nitroMax)
			{
			}
			else
			{
				Menu::error("Fichier corrompu9.");
			}
			iss.clear();
			iss.str(sAerodynamisme);
			if (iss>>aerodynamisme)
			{
			}
			else
			{
				Menu::error("Fichier corrompu10.");
			}
			iss.clear();
			iss.str(sIdMoteur);
			if (iss>>idMoteur)
			{
			}
			else
			{
				Menu::error("Fichier corrompu11.");
			}
			Moteur::infoMoteur(idMoteur, marque, nomMoteur);
			int prixMoteur=0;
			Moteur::infoMoteur(idMoteur, marque, prixMoteur);
			prix=roundf( (prixMoteur + 0 + 0 + 0 )  *0.85+ (( aerodynamisme + nitroMax ) * 100)+ (( vRang(rang) - 1 ) * 20000));
		}
		else
		{
			Menu::error("Fichier corrompu12.");
		}
	}
}

std::string Voiture::getMarque() const
{
	return m_marque;
}

std::string Voiture::getModele() const
{
	return m_modele;
}

std::string Voiture::getNomMoteur() const
{
	return m_moteur->getModele();
}

float Voiture::getVitesseMoteur() const
{
 	return m_moteur->getVitesse();
}

float Voiture::getAccelerationMoteur() const
{
 	return m_moteur->getAcceleration();
}

char Voiture::getRang() const
{
	return m_rang;
}

float Voiture::getVitesse() const
{
	return m_vitesse;
}

float Voiture::getAcceleration() const
{
	return m_acceleration;
}

int Voiture::getAerodynamisme() const
{
	return m_aerodynamisme;
}

int Voiture::getIdMoteur() const
{
	return m_idMoteur;
}

int Voiture::getIdSpoiler() const
{
	return m_idSpoiler;
}

int Voiture::getIdAirIntake() const
{
	return m_idAirIntake;
}

int Voiture::getNitroMax() const
{
	return m_nitroMax;
}

int Voiture::getNiveauNitro() const
{
	return m_niveauNitro;
}

int Voiture::getEtat() const
{
	return m_etat;
}

int Voiture::getAerodynamismeVoiture() const
{
	return m_aerodynamismeVoiture;
}

int Voiture::getConsommation() const
{
	return m_moteur->getConsommation();
}

float Voiture::getPrixCarburantMoteur() const
{
	return m_moteur->getPrixCarburant();
}

int Voiture::getPrix() const
{
	int prixMoteur=0;
	int prixSpoiler=0;
	int prixAirIntake=0;
	Moteur::infoMoteur(m_idMoteur, m_marque, prixMoteur);
	prixSpoiler = Spoiler::collection[m_idSpoiler].getPrice();
	prixAirIntake = AirIntake::collection[m_idAirIntake].getPrice();

	return static_cast<int>(roundf( (prixMoteur + prixSpoiler + prixAirIntake + 0 )  *0.9+ (( m_aerodynamismeVoiture + m_nitroMax ) * 100)+ (( vRang(m_rang) - 1 ) * 20000)));
}

int Voiture::getPrixMoteur() const
{
	return m_moteur->getPrix();
}

int Voiture::getIdTires() const
{
	return m_pneus.getDurability();
}

Spoiler &Voiture::getSpoiler()
{
	return m_spoiler;
}

AirIntake &Voiture::getAirIntake()
{
	return m_priseAir;
}

Tires &Voiture::getTires()
{
	return m_pneus;
}

void Voiture::setMoteur(Moteur* newMoteur, const int& idMoteur)
{
	m_moteur = newMoteur;
	m_idMoteur= idMoteur;
	updateAttributs();
}

void Voiture::setSpoiler(Spoiler newSpoiler, const int& idSpoiler)
{
	m_spoiler = newSpoiler;
	m_idSpoiler = idSpoiler;
	updateAttributs();
}

void Voiture::setAirIntake(AirIntake newAirIntake, const int& idAirIntake)
{
	m_priseAir = newAirIntake;
	m_idAirIntake = idAirIntake;
	updateAttributs();
}

void Voiture::setTires(Tires tires)
{
	m_pneus = tires;
	updateAttributs();
}

void Voiture::setNitro(const int& ajouter)
{
	m_niveauNitro+=ajouter;
	updateAttributs();
}

void Voiture::retirerEtat(const int& retirer)
{
	m_etat -=retirer;
}

void Voiture::pleinNitro()
{
	m_niveauNitro = m_nitroMax;
	updateAttributs();
}

void Voiture::pleinCarburant()
{
	m_niveauNitro = m_nitroMax;
	updateAttributs();
}

void Voiture::reparer()
{
	m_etat=100;
}

void Voiture::updateAttributs()
{
	m_aerodynamisme = static_cast<float>((m_priseAir.getAerodynamic() / 3) + (m_spoiler.getAerodynamic() / 3) + (m_aerodynamismeVoiture / 3));

	m_aerodynamisme+=1;

	m_vitesse = m_moteur->getVitesse() + ( m_aerodynamisme / 3 );
	m_niveauNitro = m_nitroMax;
	m_acceleration = static_cast<float>((( m_niveauNitro + m_moteur->getAcceleration() ) + (m_aerodynamisme))/10);
	m_typeCarburant = m_moteur->getTypeCarburant();
	m_consommation = m_moteur->getConsommation();
}

void Voiture::changerTires()
{
	m_pneus.setDurability(100);
}
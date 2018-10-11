//sousMenus.cpp
#include "sousMenus.hh"

Voiture* menuChoixVoiture(Profil& Player)
{
	std::string sMenu;
	Voiture* VoitureSelectionnee = 0;
	Voiture* VoitureListee = 0;
	int menu;
	int nbBox = Player.getNbBox();
	bool quit = false;
	while(quit != true)
	{
		//Menu Principal
		Terminal::get() << "Liste des Boxs\n";
		Terminal::get() << "===============\n";
		Terminal::get() << "Selectionnez le vehicule qui va faire la course.\n";
		Terminal::get() << "===============\n\n";
		for (size_t numeroBox = 0; numeroBox < nbBox; numeroBox++)
		{
			VoitureListee = Player.getBox(numeroBox);
			if(Player.boxVide(numeroBox))
			{
				Terminal::get() << (numeroBox + 1) << ". Box " << (numeroBox + 1) << " [VIDE]\n";
			}
			else
			{
				Terminal::get() << (numeroBox + 1) << ". Box " << (numeroBox + 1) << " [" << VoitureListee->getMarque() << " " << VoitureListee->getModele() << "]\n";
			}
		}
		for (size_t j = nbBox; j < 5; j++)
		{
			Terminal::get() << (j + 1) << ". Box " << (j + 1) << " [VEROUILLE]\n";
		}
		Terminal::get() << "\n"; //On separe le bloc
		Terminal::get() << "0. Retour\n";
		Terminal::get() << "===============\n";
		Terminal::get() << "Choix ? ";
		sMenu = getString(); // l'utilisateur confirme
		std::istringstream iss;

		iss.str(sMenu);
		iss >> menu; // on convertit la string recuperee plus haut en entier	
		if(menu == 0)
		{
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			quit = true; //INSTRUCTION DE SORTIE
		}
		else if(menu > 0 && menu <= nbBox)
		{
			if(Player.boxVide(menu - 1))
			{
				Terminal::get().clearScreen();
				error("Le box est vide.");
			}
			else
			{
				Terminal::get().clearScreen(); //On flushe l'ancien ecran
				VoitureSelectionnee = Player.getBox(menu - 1);
				quit = true; //INSTRUCTION DE SORTIE
			}
		}
		else if(menu > nbBox && menu <= 5)
		{
			Terminal::get().clearScreen();
			error("Ce box est verrouille.");
		}
		else
		{
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			saisieInvalide();
		}
	}
	return VoitureSelectionnee;
}

void menuCourseLibre(Profil& Player)
{
	std::string sMenu;
	int menu;
	Voiture* VoiturePlayer = 0;
	int nombreCircuits;
	//Menu Principal
	Terminal::get() << "Course Libre\n";
	Terminal::get() << "===============\n";
	Terminal::get() << "Selectionnez un circuit.\n";
	Terminal::get() << "===============\n\n";
	nombreCircuits = Circuit::listerCircuits();
	Terminal::get() << "0. Annuler\n";
	Terminal::get() << "===============\n";
	Terminal::get() << "Choix ? ";
	sMenu = getString(); // l'utilisateur choisit un menu
	std::istringstream iss;

	iss.str(sMenu); // On extrait la taille du circuit et on le stocke dans la variable de conversion "iss1".
	iss >> menu; // on convertit la string recuperee plus haut en entier
	//Redirection de l'utilisateur selon son choix grâce a un if + for.
	if(menu == 0)
	{
			Terminal::get().clearScreen(); //On flushe l'ancien ecran et on quitte
	}
	else if(menu > 0 && menu <= nombreCircuits)
	{
		Circuit* CircuitCourant = 0;
		Circuit::chargerCircuit(menu, CircuitCourant);
		Terminal::get().clearScreen(); //On flushe l'ancien ecran

		VoiturePlayer = menuChoixVoiture(Player);
		if(VoiturePlayer == 0)
		{
			error("Aucune voiture selectionnee.");
		}
		else
		{
			faireCourseLibre(*CircuitCourant, VoiturePlayer, Player);
		}
		delete CircuitCourant;
		CircuitCourant = 0;
	}
	else
	{
		Terminal::get().clearScreen(); //On flushe l'ancien ecran
		saisieInvalide();
	}
}

void menuCourseChampionnat(Profil& Player)
{
	std::string sMenu;
	int menu;
	Voiture* VoiturePlayer = 0;
	int nombreCircuits;
	//Menu Principal
	Terminal::get() << "Course Libre\n";
	Terminal::get() << "===============\n";
	Terminal::get() << "Selectionnez un circuit.\n";
	Terminal::get() << "===============\n\n";
	nombreCircuits = Circuit::listerCircuits();
	Terminal::get() << "0. Annuler\n";
	Terminal::get() << "===============\n";
	Terminal::get() << "Choix ? ";
	sMenu = getString();
	std::istringstream iss;

	iss.str(sMenu); // On extrait la taille du circuit et on le stocke dans la variable de conversion "iss1".
	iss >> menu; // on convertit la string recuperee plus haut en entier
	//Redirection de l'utilisateur selon son choix grâce a un if + for.
	if(menu == 0)
	{
			Terminal::get().clearScreen(); //On flushe l'ancien ecran et on quitte
	}
	else if(menu > 0 && menu <= nombreCircuits)
	{
		Circuit* CircuitCourant = 0;
		Circuit::chargerCircuit(menu, CircuitCourant);
		Terminal::get().clearScreen(); //On flushe l'ancien ecran
		VoiturePlayer = menuChoixVoiture(Player);
		if(VoiturePlayer == 0)
		{
			error("Aucune voiture selectionnee.");
		}
		else
		{
			faireCourseChampionnat(*CircuitCourant, VoiturePlayer, Player);
		}
		delete CircuitCourant;
		CircuitCourant = 0;
	}
	else
	{
		Terminal::get().clearScreen(); //On flushe l'ancien ecran
		saisieInvalide();
	}
}

int menuConsulterGarage(Profil& Player, const int& mode)
{
	std::string sMenu;
	int menu;
	int nbBox = Player.getNbBox();
	Voiture* Voiture = 0;

	//Menu Principal
	Terminal::get() << "Liste des Boxs\n";
	Terminal::get() << "===============\n";
	if(mode == 0) //On est en visualisation dans le garage
	{
		Terminal::get() << "Selectionnez un vehicule a examiner.\n";
	}
	else if(mode == 1) //On est en selection dans l'atelier
	{
		Terminal::get() << "Selectionnez un vehicule a ameliorer.\n";
	}
	else if(mode == 2) //On selectionne ou stocker une voiture en cours d'achat
	{
		Terminal::get() << "Selectionnez un emplacement pour garer le vehicule.\n";
	}
	else if(mode == 3) //On selectionne ou stocker une voiture en cours d'achat
	{
		Terminal::get() << "Selectionnez un vehicule a entretenir.\n";
	}
	else if(mode == 4) //On selectionne ou stocker une voiture en cours d'achat
	{
		Terminal::get() << "Selectionnez un vehicule a vendre.\n";
	}
	Terminal::get() << "===============\n\n";
	for (size_t numeroBox = 0; numeroBox < nbBox; numeroBox++)
	{
		Voiture = Player.getBox(numeroBox);
		if(Player.boxVide(numeroBox))
		{
			Terminal::get() << (numeroBox + 1) << ". Box " << (numeroBox + 1) << " [VIDE]\n";
		}
		else
		{
			Terminal::get() << (numeroBox + 1) << ". Box " << (numeroBox + 1) << " [" << Voiture->getMarque() << " " << Voiture->getModele() << "]\n";
		}
	}
	for (size_t numeroBoxVerouille = nbBox; numeroBoxVerouille < 5; numeroBoxVerouille++)
	{
		Terminal::get() << (numeroBoxVerouille + 1) << ". Box " << (numeroBoxVerouille + 1) << " [VEROUILLE]\n";
	}
	Terminal::get() << "\n"; //On separe le bloc
	Terminal::get() << "0. Retour\n";
	Terminal::get() << "===============\n";
	Terminal::get() << "Choix ? ";
	sMenu = getString();
	std::istringstream iss;

	iss.str(sMenu);
	iss >> menu; // on convertit la string recuperee plus haut en entier
	if(menu == 0)
	{
		Terminal::get().clearScreen(); //On flushe l'ancien ecran et quitte
	}
	else if(menu > 0 && menu <= nbBox)
	{
		if(Player.boxVide(menu - 1))
		{
			if(mode == 2)
			{
				Terminal::get().clearScreen(); //On flushe l'ancien ecran et quitte
			}
			else
			{
				Terminal::get().clearScreen();
				error("Le box est vide.");
			}
		}
		else if(mode == 0)
		{
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			menuConsulterBox(Player, menu - 1);
			Terminal::get().clearScreen();
		}
		else if(mode == 1)
		{
			Terminal::get().clearScreen();
			menuAtelier(Player, menu - 1);
		}
		else if(mode == 2)
		{
			Terminal::get().clearScreen();
			error("Le box est deja occupe.");
		}
		else if(mode == 3)
		{
			Terminal::get().clearScreen();
			menuMaintenance(Player, menu - 1);
		}
		else if(mode == 4)
		{
			Terminal::get().clearScreen();
			menuVenteVoiture(Player, menu - 1);
		}
	}
	else if(menu > nbBox && menu <= 5)
	{
		Terminal::get().clearScreen();
		error("Ce box est verrouille.");
	}
	else
	{
		Terminal::get().clearScreen(); //On flushe l'ancien ecran
		saisieInvalide();
	}
	return menu; //On renvoie l'emplacement choisi
}

void menuConsulterBox(Profil& Player, const int& numeroBox)
{
	Voiture* Voiture = Player.getBox(numeroBox);
	//Menu Principal
	Terminal::get() << "Vehicule gare dans le Box " << (numeroBox + 1) << "\n";
	Terminal::get() << "===============\n\n";
	Terminal::get() << "#Vehicule\n";
	Terminal::get() << " |Modele: " << Voiture->getModele() << "\n";
	Terminal::get() << " |Marque: " << Voiture->getMarque() << "\n";
	Terminal::get() << " |Rang: " << Voiture->getRang() << "\n";
	Terminal::get() << " |\n";
	Terminal::get() << " |Vitesse Totale: "<< Voiture->getVitesse() << " Km/h\n";
	Terminal::get() << " |Acceleration Totale: " << Voiture->getAcceleration() << " m/s²\n";
	Terminal::get() << " |Capacite Nitro: " << Voiture->getNitroMax() << " L\n";
	Terminal::get() << " |Aerodynamisme: " << Voiture->getAerodynamisme() << " %\n";
	Terminal::get() << " |Nitro Actuelle: " << Voiture->getNiveauNitro() << " L\n";
	Terminal::get() << " |Durabilite Pneus: "<< Voiture->getDurabilitePneus() << "%\n";
	Terminal::get() << " |Etat: " << Voiture->getEtat() << "%\n\n";
	Terminal::get() << "#Moteur\n";
	Terminal::get() << " |Modele: " << Voiture->getNomMoteur() << "\n";
	Terminal::get() << " |Vitesse: "<< Voiture->getVitesseMoteur() << " Km/h\n";
	Terminal::get() << " |Acceleration: " << Voiture->getAccelerationMoteur() << " m/s²\n\n";
	Terminal::get() << "#Spoiler\n";
	Terminal::get() << " |Modele: " << Voiture->getNomSpoiler() << "\n";
	Terminal::get() << " |Rang: "<<  Voiture->getRangSpoiler() << "\n";
	Terminal::get() << " |Aerodynamisme: " <<  Voiture->getAerodynamismeSpoiler() << " %\n\n";
	Terminal::get() << "#Prises d'air\n";
	Terminal::get() << " |Modele: " <<  Voiture->getNomPriseAir() << "\n";
	Terminal::get() << " |Rang: "<<  Voiture->getRangPriseAir() << "\n";
	Terminal::get() << " |Aerodynamisme: " <<  Voiture->getAerodynamismePriseAir() << " %\n\n";
	Terminal::get() << "#Pneus\n";
	Terminal::get() << " |Marque: " <<  Voiture->getMarquePneus() << "\n";
	Terminal::get() << " |Rang: "<<  Voiture->getRangPneus() << "\n\n";
	Terminal::get() << "===============\n";
	Terminal::get() << "Appuyez sur Entree pour revenir au menu precedent";
	getch();
}

void menuAtelier(Profil& Player, const int& numeroBox)
{
	Terminal::get().clearScreen();
	char menu;
	bool quit = false;
	Voiture* Voiture = Player.getBox(numeroBox);

	while(quit != true)
	{
		//Menu Principal
		Terminal::get() << "Menu Atelier\n";
		Terminal::get() << "===============\n";
		Terminal::get() << "Selectionnez une piece a modifier.\n";
		Terminal::get() << "===============\n\n";
		Terminal::get() << "Voiture actuelle: [BOX" << numeroBox + 1 << ": " << Voiture->getMarque() << " " << Voiture->getModele() << "]\n\n";
		Terminal::get() << "1. Moteur\n";
		Terminal::get() << "2. Prise d'air\n";
		Terminal::get() << "3. Spoiler\n\n";
		Terminal::get() << "0. Retour\n";
		Terminal::get() << "===============\n";
		Terminal::get() << "Choix ? ";
		menu = getch();
		//Redirection de l'utilisateur selon son choix grâce a un switch.
		switch(menu)
		{
			case '0':
				Terminal::get().clearScreen(); //On flushe l'ancien ecran
				quit = true;
				break;
			case '1':
				Terminal::get().clearScreen(); //On flushe l'ancien ecran
				menuAtelierMoteur(Player, numeroBox);
				break;
			case '2':
				Terminal::get().clearScreen(); //On flushe l'ancien ecran
				menuAtelierPriseAir(Player, numeroBox);
				break;
			case '3':
				Terminal::get().clearScreen(); //On flushe l'ancien ecran
				menuAtelierSpoiler(Player, numeroBox);
				break;
			default:
				Terminal::get().clearScreen(); //On flushe l'ancien ecran
				saisieInvalide();
				break;
		}
	}
}

void menuAtelierSpoiler(Profil& Player, const int& numeroBox)
{
	Voiture* Voiture = Player.getBox(numeroBox);
	char verif = 'x';
	int id = Voiture->getIdSpoiler();
	int idCharge = id + 1;
	std::string modeleCharge;
	int prixCharge;
	int aerodynamismeCharge;
	char rangCharge;

	Spoiler::infoSpoiler(idCharge, modeleCharge, rangCharge, aerodynamismeCharge, prixCharge);
	Terminal::get().clearScreen(); //On flushe l'ancien ecran	
	Terminal::get() << "/!\\ Attention ! /!\\\n";
	Terminal::get() << "====================\n";
	Terminal::get() << "Credits: " << Player.getCredits() << "c\n";
	Terminal::get() << "====================\n";
	Terminal::get() << "Vous allez ameliorer le spoiler de votre vehicule,\n";
	Terminal::get() << "Prix: " << prixCharge << "c\n\n";
	Terminal::get() << "#Nouveau Spoiler\n";
	Terminal::get() << " |Modele: " << modeleCharge << "\n";
	Terminal::get() << " |Rang: " << rangCharge << "\n";
	Terminal::get() << " |Aerodynamisme: " << aerodynamismeCharge << "%\n\n";
	Terminal::get() << "#Spoiler Actuel\n";
	Terminal::get() << " |Modele: " << Voiture->getNomSpoiler() << "\n";
	Terminal::get() << " |Rang: " << Voiture->getRangSpoiler() << "\n";
	Terminal::get() << " |Aerodynamisme: " << Voiture->getAerodynamismeSpoiler() << "%\n\n";
	Terminal::get() << "Souhaitez-vous vraiment continuer ? [O/n]\n";
	Terminal::get() << "====================\n";
	verif = getch();
	if(verif == 'o' || verif == 'O')
	{
		Terminal::get().clearScreen();
		if(Profil::compatible(Player, numeroBox, rangCharge) == true)
		{
			if(Player.payer(prixCharge))
			{
				Voiture->setSpoiler(Spoiler::chargerSpoiler(idCharge), id);
				msg("Spoiler amelioree avec succes !");
			}
		}
		else
		{
			error("Cette pièce n'est pas compatible avec votre vehicule");
		}
		verif = 'n'; // on quitte la verification
	}
	else if(verif == 'n' || verif == 'N')
	{
			Terminal::get().clearScreen(); // la variable de verification prend la valeur n donc on sort de la verification, mais quit vaut faux
			verif = 'n'; // on quitte la verification
	}
	else
	{
			saisieInvalide();
	}
	if(Player.getSauvegardeAuto())
	{
		Player.sauvegarderProfil();
	}
}

void menuAtelierPriseAir(Profil& Player, const int& numeroBox)
{
	Voiture* Voiture = Player.getBox(numeroBox);
	char verif = 'x';

	int id = Voiture->getIdSpoiler();

	int idCharge = id + 1;
	std::string modeleCharge;
	int prixCharge;
	int aerodynamismeCharge;
	char rangCharge;

	PriseAir::infoPriseAir(idCharge, modeleCharge, rangCharge, aerodynamismeCharge, prixCharge);
	Terminal::get().clearScreen(); //On flushe l'ancien ecran	
	Terminal::get() << "/!\\ Attention ! /!\\\n";
	Terminal::get() << "====================\n";
	Terminal::get() << "Credits: " << Player.getCredits() << "c\n";
	Terminal::get() << "====================\n";
	Terminal::get() << "Vous allez ameliorer les prises d'air de votre vehicule,\n";
	Terminal::get() << "Prix: " << prixCharge << "c\n\n";
	Terminal::get() << "#Nouveau Spoiler\n";
	Terminal::get() << " |Modele: " << modeleCharge << "\n";
	Terminal::get() << " |Rang: " << rangCharge << "\n";
	Terminal::get() << " |Aerodynamisme: " << aerodynamismeCharge << "%\n\n";
	Terminal::get() << "#Spoiler Actuel\n";
	Terminal::get() << " |Modele: " << Voiture->getNomPriseAir() << "\n";
	Terminal::get() << " |Rang: " << Voiture->getRangPriseAir() << "\n";
	Terminal::get() << " |Aerodynamisme: " << Voiture->getAerodynamismePriseAir() << "%\n\n";
	Terminal::get() << "Souhaitez-vous vraiment continuer ? [O/n]\n";
	Terminal::get() << "====================\n";
	verif = getch();
	if(verif == 'o' || verif == 'O')
	{
			Terminal::get().clearScreen();
			if(Profil::compatible(Player, numeroBox, rangCharge) == true)
			{
				if(Player.payer(prixCharge))
				{
					Voiture->setPriseAir(PriseAir::chargerPriseAir(idCharge), id);
					msg("Prise d'air amelioree avec succes !");
				}
			}
			else
			{
				error("Cette pièce n'est pas compatible avec votre vehicule");
			}
			verif = 'n'; // on quitte la verification

	}
	else if(verif == 'n' || verif == 'N')
	{
			Terminal::get().clearScreen(); // la variable de verification prend la valeur n donc on sort de la verification, mais quit vaut faux
			verif = 'n'; // on quitte la verification
	}
	else
	{
			saisieInvalide();
	}
	if(Player.getSauvegardeAuto())
	{
		Player.sauvegarderProfil();
	}
}

void menuAtelierMoteur(Profil& Player, const int& numeroBox)
{
	Terminal::get().clearScreen();

	Voiture* Voiture = Player.getBox(numeroBox);

	char verifAchat;
	std::string sMenu;
	int menu;
	int tmenu = 0;
	bool paye = false;
	bool achat = false;
	bool quit = false;
	bool e2tour = false;
	int nbMoteurs = Moteur::compterMoteurs(Voiture->getMarque());
	std::string newNomMoteur = "Aucun";
	char newRangMoteur = ' ';
	int newPrixMoteur = 0;
	int newVitesseMoteur = 0;
	int newAccelerationMoteur = 0;
	int diffVitesseMoteur = 0;
	int diffAccelerationMoteur = 0;

	while(quit != true)
	{
		verifAchat = 'x';
		//Menu Principal
		Terminal::get() << "Changer Moteur\n";
		Terminal::get() << "===============\n";
		Terminal::get() << "Entrez le numero d'un moteur une fois pour afficher ses stats.\n";
		Terminal::get() << "Entrez le a nouveau pour acheter le moteur.\n";
		Terminal::get() << "Remarque: Pour tout achat, l'ancien moteur est automatiquement vendu. (60% du prix d'origine)\n";
		Terminal::get() << "===============\n";
		Terminal::get() << "Credits: " << Player.getCredits() << "C \n";
		Terminal::get() << "===============\n\n";
		Terminal::get() << "#Stats Moteur\n";
		Terminal::get() << " |Modele: " << newNomMoteur << " (Actuel: " << Voiture->getNomMoteur() << ")\n";
		Terminal::get() << " |Vitesse: " << newVitesseMoteur << "      (Actuelle: " << Voiture->getVitesseMoteur() << " [";
		if(diffVitesseMoteur >= 0)
		{
			Terminal::get() << '+';
		}
		Terminal::get() << diffVitesseMoteur << "])\n";
		Terminal::get() << " |Acceleration: " << newAccelerationMoteur << " (Actuelle: " << Voiture->getAccelerationMoteur() << " [";
		if(diffAccelerationMoteur >= 0)
		{
			Terminal::get() << '+';
		}
		Terminal::get() << diffAccelerationMoteur << "])\n";
		Terminal::get() << " |Prix: " << newPrixMoteur << "\n\n";
		Moteur::listerMoteurs(Voiture->getMarque());
		Terminal::get() << "\n";
		Terminal::get() << "0. Retour\n";
		Terminal::get() << "===============\n";
		Terminal::get() << "Choix ? ";
		sMenu = getString(); // l'utilisateur entre le menu qu'il souhaite ouvrir
		std::istringstream iss;

		iss.str(sMenu);
		iss >> menu; // on convertit la string recuperee plus haut en entier	
		if(menu == 0)
		{
				Terminal::get().clearScreen(); //On flushe l'ancien ecran
				quit = true; //INSTRUCTION DE SORTIE
		}
		else if(menu > 0 && menu <= nbMoteurs)
		{
			Terminal::get().clearScreen();
			Moteur::infoMoteur(menu, Voiture->getMarque(), newNomMoteur, newVitesseMoteur, newAccelerationMoteur, newRangMoteur, newPrixMoteur);

			if(menu == Voiture->getIdMoteur())
			{
				Terminal::get().clearScreen();
				msg("Votre vehicule est deja equipe de cette piece. ("+newNomMoteur+")");
				newNomMoteur = "N/A";
				newVitesseMoteur = 0;
				newAccelerationMoteur = 0;
				newPrixMoteur = 0;
				newRangMoteur = ' ';
				diffVitesseMoteur = 0;
				diffAccelerationMoteur = 0;
			}
			else
			{
				if(e2tour == 0 || tmenu != menu)
				{
					diffVitesseMoteur = newVitesseMoteur - Voiture->getVitesseMoteur();
					diffAccelerationMoteur = newAccelerationMoteur - Voiture->getAccelerationMoteur();
					e2tour = 1;
					tmenu = menu;
				}
				else if(e2tour == 1 && tmenu == menu) //Si c'est la 2e pression sur le MEME menu
				{
					if(Profil::compatible(Player, numeroBox, newRangMoteur) == 1)
					{
						Terminal::get().clearScreen();
						while(verifAchat != 'n') // Boucle de confirmation
						{
							Terminal::get() << "Vous allez acheter le moteur suivant:\n\n";
							Terminal::get() << "====================\n";
							Terminal::get() << "#Moteur Selectionne\n";
							Terminal::get() << " |Modele: " << newNomMoteur << "\n";
							Terminal::get() << " |Vitesse: " << newVitesseMoteur << "  (";
							if(diffVitesseMoteur >= 0)
							{
								Terminal::get() << '+';
							}
							Terminal::get() << diffVitesseMoteur << ")\n";
							Terminal::get() << " |Acceleration: " << newAccelerationMoteur << "  (";
							if(diffAccelerationMoteur >= 0)
							{
								Terminal::get() << '+';
							}
							Terminal::get() << diffAccelerationMoteur << ")\n";
							Terminal::get() << " |Prix: " << newPrixMoteur << "c\n\n";
							Terminal::get() << "====================\n";
							Terminal::get() << "Credits: " << Player.getCredits() << "C \n";
							Terminal::get() << "====================\n\n";
							Terminal::get() << "#Moteur Actuel\n";
							Terminal::get() << " |Modele: " << Voiture->getNomMoteur() << "\n";
							Terminal::get() << " |Vitesse: "<< Voiture->getVitesseMoteur() << " Km/h\n";
							Terminal::get() << " |Acceleration: " << Voiture->getAccelerationMoteur() << " m/s²\n\n";
							Terminal::get() << "Souhaitez-vous vraiment l'acheter ? [O/n]\n";
							Terminal::get() << "====================\n";
							verifAchat = getch();
							switch(verifAchat)
							{
								case 'o':
									verifAchat = 'n'; // on quitte la verification
									achat = true;
									break;
								case 'O':
									verifAchat = 'n'; // on quitte la verification
									achat = true;
									break;
								case 'n':
									Terminal::get().clearScreen(); // la variable de verification prend la valeur n donc on sort de la verification, mais quit vaut faux
									break;
								case 'N':
									Terminal::get().clearScreen(); // la variable de verification prend la valeur n donc on sort de la verification, mais quit vaut faux
									verifAchat = 'n'; // on quitte
									break;
								default:
									Terminal::get().clearScreen();
									saisieInvalide();
									break;
							}
							if(achat == true)
							{
								Terminal::get().clearScreen();
								paye = Player.payer(newPrixMoteur);
								if(paye == true)
								{
									Player.ajouterCredits(Voiture->getPrixMoteur() * 0.6f);
									Player.setMoteurVoiture(numeroBox, Moteur::chargerMoteur(tmenu, Voiture->getMarque()), menu);
									msg("La piece a ete achetee et installee avec succes !");
								}
							}
						}
					}
					else
					{
						Terminal::get().clearScreen();
						error("La piece choisie n'est pas compatible avec votre voiture.");
					}
				}
			}
		}
		else
		{
				Terminal::get().clearScreen(); //On flushe l'ancien ecran
				saisieInvalide();
		}
	}
	if(Player.getSauvegardeAuto())
	{
		Player.sauvegarderProfil();
	}
}

void menuMaintenance(Profil& Player, const int& numeroBox)
{
	Terminal::get().clearScreen();
	char menu;
	bool quit = 0;
	char verifAchat;
	int nitroManquante;
	Voiture* Voiture = Player.getBox(numeroBox);
	int aPayer=0;
	//Menu Principal
	while(quit != 1)
	{
		Terminal::get() << "Menu Maintenance\n";
		Terminal::get() << "===============\n";
		Terminal::get() << "Selectionnez un vehicule a reparer ou entretenir.\n";
		Terminal::get() << "===============\n\n";
		Terminal::get() << "Voiture actuelle: [BOX" << numeroBox + 1 << ": " << Voiture->getMarque() << " " << Voiture->getModele() << "]\n\n";
		Terminal::get() << "1. Changer Pneus\n";
		Terminal::get() << "2. Plein Nitro\n";
		Terminal::get() << "3. Reparer\n\n";
		Terminal::get() << "0. Retour\n";
		Terminal::get() << "===============\n";
		Terminal::get() << "Choix ? ";
		menu = getch(); // l'utilisateur entre le menu qu'il souhaite ouvrir
		//Redirection de l'utilisateur selon son choix grâce a un switch.
		switch(menu)
		{
			case '0':
				Terminal::get().clearScreen(); //On flushe l'ancien ecran
				quit = 1;
				break;
			case '1':
				Terminal::get().clearScreen(); //On flushe l'ancien ecran
				Terminal::get() << "/!\\ Attention ! /!\\\n";
				Terminal::get() << "====================\n";
				Terminal::get() << "Credits: " << Player.getCredits() << "c\n";
				Terminal::get() << "====================\n";
				Terminal::get() << "Changer les pneus de ce vehicule\n";
				Terminal::get() << "vous coutera 2000c \n";
				Terminal::get() << "Etes-vous sur ? [O/n]\n";
				Terminal::get() << "====================\n";
				verifAchat = getch();
				Terminal::get().clearScreen();
				if(verifAchat == 'o' || verifAchat == 'O')
				{
					if(Player.payer(2000))
					{
						Voiture->changerPneus();
						msg("Pneus Changes avec succes !");
					}
				}
				else if(verifAchat == 'n' || verifAchat == 'n')
				{
					msg("Transaction annulee.");
				}
				break;
			case '2':
				Terminal::get().clearScreen(); //On flushe l'ancien ecran
				if(Voiture->getNitroMax() == 0)
				{
					error("Votre vehicule n'est pas equipe d'un reservoir de Nitro.");
				}
				else
				{
					nitroManquante = Voiture->getNitroMax() - Voiture->getNiveauNitro();
					Terminal::get() << "/!\\ Attention ! /!\\\n";
					Terminal::get() << "====================\n";
					Terminal::get() << "Credits: " << Player.getCredits() << "c\n";
					Terminal::get() << "====================\n";
					Terminal::get() << "Remplir la Nitro de ce vehicule (Restant: " << Voiture->getNiveauNitro() << "L/" << Voiture->getNitroMax() << "L)\n";
					Terminal::get() << "Pour remplir les " << nitroManquante << "L manquants, cela vous coutera " << nitroManquante * 100 << "c\n";
					Terminal::get() << "Etes-vous sur ? [O/n]\n";
					Terminal::get() << "====================\n";
					verifAchat = getch();
					Terminal::get().clearScreen();
					if(verifAchat == 'o' || verifAchat == 'O')
					{
						if(Player.payer(nitroManquante * 100 ))
						{
							Voiture->changerPneus();
							msg("Nitro au max !");
						}
					}
					else if(verifAchat == 'n' || verifAchat == 'n')
					{
						msg("Transaction annulee.");
					}
				}
				break;
			case '3':
				if(Voiture->getEtat()==100)
				{
					msg("Votre voiture est en parfait etat.");
				}
				else
				{
					aPayer = (Voiture->getPrix() * (100 - Voiture->getEtat())) /100 ;
					Terminal::get().clearScreen(); //On flushe l'ancien ecran
					Terminal::get() << "/!\\ Attention ! /!\\\n";
					Terminal::get() << "====================\n";
					Terminal::get() << "Credits: " << Player.getCredits() << "c\n";
					Terminal::get() << "====================\n";
					Terminal::get() << "Reparer ce vehicule\n";
					Terminal::get() << "vous coutera "<<aPayer<<"c\n";
					Terminal::get() << "Etes-vous sur ? [O/n]\n";
					Terminal::get() << "====================\n";
					verifAchat = getch();
					Terminal::get().clearScreen();
					if(verifAchat == 'o' || verifAchat == 'O')
					{
						if(Player.payer(aPayer))
						{
							Voiture->reparer();
							msg("voiture reparee avec succes !");
						}
					}
					else if(verifAchat == 'n' || verifAchat == 'n')
					{
						msg("Transaction annulee.");
					}
				}
				break;
			default:
				Terminal::get().clearScreen(); //On flushe l'ancien ecran
				saisieInvalide();
				break;
		}
	}
	if(Player.getSauvegardeAuto())
	{
		Player.sauvegarderProfil();
	}
}

void menuAcheterBox(Profil& Player)
{
	char verif = 'x';
	Terminal::get().clearScreen(); //On flushe l'ancien ecran
	Terminal::get() << "/!\\ Attention ! /!\\\n";
	Terminal::get() << "====================\n";
	Terminal::get() << "Credits: " << Player.getCredits() << "c\n";
	Terminal::get() << "====================\n";
	Terminal::get() << "Vous allez acheter un " << Player.getNbBox() + 1 << "eme Box,\n";
	Terminal::get() << "Prix: " << Player.getNbBox() * 20000 << "c\n\n";
	Terminal::get() << "Souhaitez-vous vraiment continuer ? [O/n]\n";
	Terminal::get() << "====================\n";
	verif = getch();
	switch(verif)
	{
		case 'o':
			Terminal::get().clearScreen();
			Player.acheterBox();
			verif = 'n'; // on quitte la verification
			break;
		case 'O':
			Terminal::get().clearScreen();
			Player.acheterBox();
			verif = 'n'; // on quitte la verification
			break;
		case 'n':
			Terminal::get().clearScreen(); // la variable de verification prend la valeur n donc on sort de la verification, mais quit vaut faux
			break;
		case 'N':
			Terminal::get().clearScreen(); // la variable de verification prend la valeur n donc on sort de la verification, mais quit vaut faux
			verif = 'n'; // on quitte la verification
			break;
		default:
			Terminal::get().clearScreen();
			saisieInvalide();
			break;
	}
	if(Player.getSauvegardeAuto())
	{
		Player.sauvegarderProfil();
	}
}

void menuAchatVoiture(const char& rang, Profil& Player)
{
	std::string sMenu;
	int menu;
	int tmenu = 0;
	bool quit = false;
	bool achat = false;
	bool e2tour = false;
	int numeroBox = 0;
	std::string marqueVoiture = "N/A";
	std::string modeleVoiture = "N/A";
	int nitroMaxVoiture = 0;
	int aerodynamismeVoiture = 0;
	int idMoteurVoiture =0;
	std::string nomMoteurVoiture = "N/A";
	int vitesseMoteurVoiture = 0;
	int accelerationMoteurVoiture = 0;
	int prixVoiture = 0;

	while(quit != true)
	{
		char verifAchat = 'x';
		//Menu Principal
		Terminal::get() << "Concessionnaire - [Rang " << rang << "]\n";
		Terminal::get() << "===============\n";
		Terminal::get() << "Entrez le numero d'un vehicule une fois pour le selectionner.\n";
		Terminal::get() << "Entrez le a nouveau pour acheter le vehicule.\n";
		Terminal::get() << "===============\n\n";
		Voiture::listerVoitures(rang);
		Terminal::get() << "\n"; //On separe le bloc
		Terminal::get() << "0. Retour\n";
		Terminal::get() << "===============\n";
		Terminal::get() << "Credits: " << Player.getCredits() << "c\n";
		Terminal::get() << "===============\n\n";
		Terminal::get() << "#Voiture Selectionnee\n";
		Terminal::get() << " |Marque: " << marqueVoiture << "\n";
		Terminal::get() << " |Modele: " << modeleVoiture << "\n";
		Terminal::get() << " #Moteur" << "\n";
		Terminal::get() << "  |Modele: " << nomMoteurVoiture << "\n";
		Terminal::get() << "  |Vitese: " << vitesseMoteurVoiture << "Km/h\n";
		Terminal::get() << "  |Acceleration: " << accelerationMoteurVoiture << "m/s²\n";
		Terminal::get() << " |Capa. Nitro: " << nitroMaxVoiture << "L\n";
		Terminal::get() << " |Aerodynamisme: " << aerodynamismeVoiture << "%\n";
		Terminal::get() << " |Prix: " << prixVoiture << "c\n\n";
		Terminal::get() << "===============\n";
		Terminal::get() << "Choix ? ";
		sMenu = getString(); // l'utilisateur entre le menu qu'il souhaite ouvrir
		std::istringstream iss;

		iss.str(sMenu); // On extrait la taille du circuit et on le stocke dans la variable de conversion "iss1".
		iss >> menu; // on convertit la string recuperee plus haut en entier
		if(menu == 0) //Redirection de l'utilisateur selon son choix grâce a un switch.
		{
				Terminal::get().clearScreen(); //On flushe l'ancien ecran
				quit = true; //INSTRUCTION DE SORTIE
		}
		else if(menu > 0  && menu <= Voiture::compterVoitures(rang))
		{
			if(e2tour == 0 || tmenu != menu)
			{
				Terminal::get().clearScreen(); //On flushe l'ancien ecran	
				Voiture::infoVoiture(menu, rang, marqueVoiture, modeleVoiture, idMoteurVoiture, nitroMaxVoiture, aerodynamismeVoiture, prixVoiture);
				Moteur::infoMoteur(idMoteurVoiture, marqueVoiture, nomMoteurVoiture, vitesseMoteurVoiture, accelerationMoteurVoiture);
				e2tour = 1;
				tmenu = menu;
			}
			else
			{
				while(verifAchat != 'n') // Boucle de confirmation
				{
					Terminal::get().clearScreen(); //On flushe l'ancien ecran
					Terminal::get() << "/!\\ Attention ! /!\\\n";
					Terminal::get() << "====================\n";
					Terminal::get() << "Credits: " << Player.getCredits() << "c\n";
					Terminal::get() << "====================\n";
					Terminal::get() << "Vous allez acheter le vehicule:\n";
					Terminal::get() << marqueVoiture << " " << modeleVoiture << "\n";
					Terminal::get() << "Prix: " << prixVoiture << "c\n\n";
					Terminal::get() << "Etes-vous sur ? [O/n]\n";
					Terminal::get() << "====================\n";
					verifAchat = getch();
					switch(verifAchat)
					{
						case 'o':
							Terminal::get().clearScreen();
							verifAchat = 'n'; // on quitte la verification
							achat = true;
							break;
						case 'O':
							Terminal::get().clearScreen();
							verifAchat = 'n'; // on quitte la verification
							achat = true;
							break;
						case 'n':
							Terminal::get().clearScreen(); // la variable de verification prend la valeur n donc on sort de la verification, mais quit vaut faux
							msg("Transaction annulee.");
							verifAchat = 'n'; // on quitte
							break;
						case 'N':
							Terminal::get().clearScreen(); // la variable de verification prend la valeur n donc on sort de la verification, mais quit vaut faux
							msg("Transaction annulee.");
							verifAchat = 'n'; // on quitte
							break;
						default:
							Terminal::get().clearScreen();
							saisieInvalide();
							break;
					}
					if(achat == true)
					{
						Terminal::get().clearScreen();
						numeroBox = menuConsulterGarage(Player, 2); //on demande a l'utilisateur ou stocker la voiture
						Terminal::get().clearScreen();
						if(numeroBox == 0)
						{
							msg("Transaction annulee.");
						}
						else
						{
							numeroBox -= 1;
							if(Player.payer(prixVoiture))
							{
								Player.setBox(numeroBox, Voiture::chargerVoiture(menu, rang));
								Player.ajouterVoitureAchetee();
								msg("Vehicule achete avec succes !");
							}
						}
					}
				}
			}
		}
		else
		{
				Terminal::get().clearScreen(); //On flushe l'ancien ecran
				saisieInvalide();
		}
	}
	if(Player.getSauvegardeAuto())
	{
		Player.sauvegarderProfil();
	}
}

void menuConcessionaireAchat(Profil& Player)
{
	char menu;
	//Menu Principal
	Terminal::get() << "Concessionnaire\n";
	Terminal::get() << "===============\n";
	Terminal::get() << "Selectionnez le rang du vehicule a acheter.\n";
	Terminal::get() << "===============\n\n";
	Terminal::get() << "1. Rang [D]\n";
	Terminal::get() << "2. Rang [C]\n";
	Terminal::get() << "3. Rang [B]\n";
	Terminal::get() << "4. Rang [A]\n";
	Terminal::get() << "5. Rang [S]\n\n";
	Terminal::get() << "0. Retour\n";
	Terminal::get() << "===============\n";
	Terminal::get() << "Choix ? ";
	menu = getch(); // l'utilisateur entre le menu qu'il souhaite ouvrir
	//Redirection de l'utilisateur selon son choix grâce a un switch.
	switch(menu)
	{
		case '0':
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			break;
		case '1':
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			menuAchatVoiture('D', Player);
			break;
		case '2':
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			menuAchatVoiture('C', Player);
			//menuAchatVoiture('C', Player);
			break;
		case '3':
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			menuAchatVoiture('B', Player);
			//menuAchatVoiture('B', Player);
			break;
		case '4':
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			menuAchatVoiture('A', Player);
			//menuAchatVoiture('A', Player);
			break;
		case '5':
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			menuAchatVoiture('S', Player);
			//menuAchatVoiture('S', Player);
			break;
		default:
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			saisieInvalide();
			break;
	}
}

void menuVenteVoiture(Profil& Player, const int& numeroBox)
{
	char verif;
	Voiture* Voiture = Player.getBox(numeroBox);
	Terminal::get() << Voiture->getPrix();
	int prixVente = Voiture->getPrix() * 0.70f;
	std::string sPrixVente;
	std::ostringstream oss;

	oss << prixVente;      // on insere le int dans le stream oss
	sPrixVente = oss.str(); // range le int dans la variable string

	Terminal::get().clearScreen(); //On flushe l'ancien ecran	
	Terminal::get() << "/!\\ Attention ! /!\\\n";
	Terminal::get() << "====================\n";
	Terminal::get() << "Credits: " << Player.getCredits() << "c\n";
	Terminal::get() << "====================\n\n";
	Terminal::get() << "Vous allez vendre le vehicule :" << Voiture->getMarque() << " " << Voiture->getModele() << "[Box" << numeroBox << "]\n";
	Terminal::get() << "Prix de vente : " << prixVente << "c\n\n";
	Terminal::get() << "Souhaitez-vous vraiment continuer ? [O/n]\n";
	Terminal::get() << "====================\n";
	verif = getch();
	if(verif == 'o' || verif == 'O')
	{
			Terminal::get().clearScreen();
			Player.ajouterCredits(Voiture->getPrix() * 0.5);
			Player.setBox(numeroBox);
			msg(Voiture->getModele()+" vendue avec succes pour "+sPrixVente+"c");
	}
	else if(verif == 'n' || verif == 'N')
	{
			Terminal::get().clearScreen(); // la variable de verification prend la valeur n donc on sort de la verification, mais quit vaut faux
			msg("Transaction annulee par l'utilisateur.");
			verif = 'n'; // on quitte la verification
	}
	else
	{
			Terminal::get().clearScreen();
			saisieInvalide();
	}
	if(Player.getSauvegardeAuto())
	{
		Player.sauvegarderProfil();
	}
}

void menuDifficulte(Profil& Player)
{
	std::string menu;	//un string car le le passe en iss
	char choix;
	int difficulte;
	
	Terminal::get() <<"Augmenter la difficulte augmente les gains\n";
	Terminal::get() <<"====================\n";
	Terminal::get() <<"Choisissez une difficulte\n";
	Terminal::get() <<"====================\n\n";
	Terminal::get() << "1. DEBUTANT\n";
	Terminal::get() << "2. FACILE\n";
	Terminal::get() << "3. NORMAL\n";
	Terminal::get() << "4. DIFFICILE\n";
	Terminal::get() << "5. EXPERT\n\n";
	Terminal::get() << "0. Retour\n";
	Terminal::get() << "===============\n";
	Terminal::get() << "Choix ? ";
	menu = getString(); // l'utilisateur entre le menu qu'il souhaite ouvrir
	std::istringstream iss(menu);
	iss>>difficulte;
	choix=menu[0];
	//Redirection de l'utilisateur selon son choix grâce a un switch.
	switch(choix)
	{
		case '0':
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			break;
		case '1':
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			Player.setDifficulte(difficulte);
			break;
		case '2':
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			Player.setDifficulte(difficulte);
			//menuAchatVoiture('C', Player);
			break;
		case '3':
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			Player.setDifficulte(difficulte);
			//menuAchatVoiture('B', Player);
			break;
		case '4':
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			Player.setDifficulte(difficulte);
			//menuAchatVoiture('A', Player);
			break;
		case '5':
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			Player.setDifficulte(difficulte);
			//menuAchatVoiture('S', Player);
			break;
		default:
			Terminal::get().clearScreen(); //On flushe l'ancien ecran
			saisieInvalide();
			break;
	}
	if(Player.getSauvegardeAuto())
	{
		Player.sauvegarderProfil();
	}
}

void menuChangementNomProfil(Profil& Player)
{
	std::string nom;

	//Menu Creation de profil
	Terminal::get() << "Changement de nom\n";
	Terminal::get() << "===============\n\n";
	Terminal::get() << "Saisissez le nouveau nom du Profil.\n\n";
	Terminal::get() << "0. Annuler\n";
	Terminal::get() << "===============\n";
	Terminal::get() << "Nom: ";
	nom = getString(); // l'utilisateur entre le menu qu'il souhaite ouvrir
	Terminal::get().clearScreen(); //on flushe l'ecran
	if(nom != "0")
	{
		Player.changerNom(nom);
		msg("Le nom de votre profil est maintenant : \""+nom+"\"");
	}
	if(Player.getSauvegardeAuto())
	{
		Player.sauvegarderProfil();
	}
}
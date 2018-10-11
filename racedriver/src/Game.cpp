#include <unistd.h>
#include <ctime>
#include <libcurl/include/curl.h>
#include <sstream>
#include <fstream>
#include "Game.hh"
#include "menusPrincipaux.hh"

//Singleton storage ptr
std::unique_ptr<Game> Game::instance = nullptr;

Game::Game()
{
  if (Game::instance != nullptr) throw ("Cannot reinstantiate singleton");
  Game::instance = std::unique_ptr<Game>(this);
}

int Game::main()
{
	_term.test();
	// !!!!!!!!!!!! OLD !!!!!!!!!!!!
	_term.clearScreen();
	std::srand(std::time(0)); //INITIALISATION DE L'ALEATOIRE
	update(); //on verifie et fait les mises à jour
	_term << "Chargement en Cours...\n";
	usleep(2000);
	_term.clearScreen();
	_term << "Pour jouer dans les meilleures conditions,\nbasculez en plein ecran !\n\n";
	menuRacedriver();//on lance le coeur du jeu
	return 0;
}

Terminal &Game::getTerm()
{
	return (_term);
}

void Game::printASCIILogo()
{
	_term << " ________                  ________       _____                    \n"
				<< " ___  __ \\_____ ______________  __ \\_________(_)__   ______________\n"
				<< " __  /_/ /  __ `/  ___/  _ \\_  / / /_  ___/_  /__ | / /  _ \\_  ___/\n"
				<< " _  _, _// /_/ // /__ /  __/  /_/ /_  /   _  / __ |/ //  __/  /    \n"
				<< " /_/ |_| \\__,_/ \\___/ \\___//_____/ /_/    /_/  _____/ \\___//_/     \n";
}

void Game::error(const std::string &str)
{
	msg("ERREUR: "+str);
}

void Game::msg(const std::string &str)
{
	_term << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
	      << ":: " << str << "\n"
	      << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
}

void Game::removeUpdatePackage()
{
	std::remove("Update/update.zip");
}

void Game::update()
{
	removeUpdatePackage();
	std::ifstream config("Data/config.ini");
	if(!config)
	{
		Game::instance->getTerm().clearScreen();
		error("Echec de lecture du fichier de configuration config.ini.");
		_term << ">La verification de la derniere version ne peut être effectuee.\n"
		      << ">Vous allez jouer avec une version potentiellement obsolete de Racedriver.\n"
	      	<< ">Appuyez sur [ENTREE] pour continuer.\n";
	  getch();
	}
	std::string ligneChargee;
	std::istringstream iss;	//convertion string to int
	int OS = 2; //0 = linux, 1 = windows, 2 = bug

	std::getline(config, ligneChargee);
	iss.str(ligneChargee);	//charge l'OS
	iss >> OS;

	std::string version;	//version de l'utilisateur

	std::getline(config, ligneChargee);
	version = ligneChargee;	//charge la verion de l'utilisateur

	//si le fichier config est corrompu
	if(version.size() < 3 || version.size() > 5 || (OS != 1 && OS != 0) || version.find_first_of(".") != 1)
	{
		Game::instance->getTerm().clearScreen();
		error("Fichier de configuration corompu");
		_term << ">La verification de la derniere version ne peut être effectuee.\n"
		      << ">Vous allez jouer avec une version potentiellement obsolete de Racedriver.\n"
		      << ">Appuyez sur [ENTREE] pour continuer.\n";
		getch();
		return;
	}
	CURL *curlVersion = curl_easy_init(); //On crée un flux cURL et on "instancie" le flux
	CURLcode resVersion; //CURLcode est un type enum de Curl stockant un état d'erreur.

	//création et ouverture d'un fichier en ecriture
	FILE *versionFile = fopen("Update/version.cdx", "w");

	Game::instance->getTerm() << ">Connexion au serveur distant...\n";
	//on indique l'url cible
	curl_easy_setopt(curlVersion, CURLOPT_URL, "/bin/version");

	//on indique quelle est la fonction d'ecriture du fichier. on utilise celle de la bibliothèque standard
	curl_easy_setopt(curlVersion, CURLOPT_WRITEFUNCTION, fwrite);


	//on indique le fichier de destination chez le client
	curl_easy_setopt(curlVersion, CURLOPT_WRITEDATA, versionFile);

	_term << ">Recuperation des informations de mise a jour...\n\n";
	//on lance le flux (curl version ici) ==> telechargement du fichier
	//l'état du telechargement est stocké dans un type CURLcode (ici resVersion)
	resVersion = curl_easy_perform(curlVersion);

	//on libère les ressources utilisées
	curl_easy_cleanup(curlVersion);
	fclose(versionFile); //On ferme le fichier téléchargé car on en a plus besoin

	//si le téléchargement s'est mal dérroulé
	if(CURLE_OK != resVersion)
	{
		//echec du telechargement
		error("La recuperation du fichier de mise a jour a echoue. Verifiez votre connexion.");
		_term << ">La lecture du fichier de mise a jour est impossible.\n"
		      << ">Vous jouerez avec une version potentiellement obsolete de Racedriver.\n"
		      << ">Appuyez sur [ENTREE] pour continuer.\n";
		getch();
		return;
	}
	std::ifstream latestVersion("Update/version.cdx");
	std::string stringLatestVersion;	//derniere version disponible
	std::getline(latestVersion, stringLatestVersion);

	//si la verion actuelle est differente de la version disponible, on telecharge la derniere version de racedriver
	if(version != stringLatestVersion)
	{
		char choix = 'x';
		while(choix != 'O' && choix != 'o' && choix != 'N' && choix != 'n')
		{
			msg("Votre client est obsolete, une mise a jour est disponible !");
			_term << "Souhaitez vous telecharger la derniere version de Racedriver ? [O/n]\n";
			choix = static_cast<char>(std::getchar());
		}
		if(choix == 'N' || choix == 'n')
		{
			_term << ">Vous jouerez avec une version obsolete de Racedriver.\n";
			_term << ">Appuyez sur [ENTREE] pour continuer.\n";
			getch();
			return;
		}
		FILE *updateFile = fopen("Update/update.zip", "w");
		CURL *curlUpdate;
		CURLcode resUpdate;
		std::string binURL;

		curlUpdate = curl_easy_init();

		if(OS == 0) //Si on est sur linux, on dl la version linux
		{
			binURL = "bin/linux/"+stringLatestVersion+".zip";
		}
		else if(OS == 1) //Si on est sur windows on dl la version windows
		{
			binURL = "bin/windows/"+stringLatestVersion+".zip";
		}
		_term << "\n>Connexion au serveur distant...\n";
		curl_easy_setopt(curlUpdate, CURLOPT_URL, binURL.c_str());
		curl_easy_setopt(curlUpdate, CURLOPT_WRITEFUNCTION, fwrite);
		curl_easy_setopt(curlUpdate, CURLOPT_WRITEDATA, updateFile);

		_term << ">Telechargement de Racedriver...\n\n";
		resUpdate = curl_easy_perform(curlUpdate);

		curl_easy_cleanup(curlUpdate);
		fclose(updateFile);
		//echec du dl
		if(CURLE_OK != resUpdate)
		{
			error("Le telechargement de la mise a jour a echoue.");
			_term <<">Vous jouerez avec une version obsolete de Racedriver.\n"
			      <<">Appuyez sur [ENTREE] pour continuer.\n";
			getch();
			return;
		}
		msg("Le client a ete mis a jour avec succes !");
		_term << ">Vous devez redemmarer le launcher pour appliquer les modifications.\n";
		if(OS == 0) //Si on est sur linux... car windows n'a pas install.sh
		{
			_term << ">N'oubliez pas de terminer l'installation en lançant \"install.sh\"."
			      << ">Lisez le README pour plus de precisions.\n";
		}
		_term << ">Appuyez sur [Entree] pour quitter.";
		getch();
		//décompression du .zip téléchargé
		//opérateur ternaire: si OS == 0 (linux) on appelle execl pour unpack linux, sinon on appelle execl pour unpack.exe windows
		OS == 0 ? execl("Update/unpack", "unpack", "-qq", "-o", "Update/update.zip", NULL) : execl("Update/unpack.exe", "unpack.exe", "-qq", "-o", "Update/update.zip", NULL);
		//le programme se termine ici grace à l'apel à execl()
	}
	msg("Le client est a jour !");
	_term << ">Appuyez sur [Entree] pour continuer.\n";
	getch();
}

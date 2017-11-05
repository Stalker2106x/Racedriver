
/**
===============

Ce programme est un jeu de course en console et en graphique.

Ce projet contient 16 fichiers sources et 15 fichiers d'en-tête.

Ce projet est compilé avec les options: -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wfloat-equal -Woverloaded-virtual -Winline -Os -s -O2

Les bibliothèques utilisées sont:
	-Boost-thread: pour les threads (car les threads de la bibliothèque standard ne sont pas supportés partout)
	-Boost-asio: pour le multijoueur
	-SFML: pour le graphique, le son et le temps
	-curl: pour télécharger les mises à jour depuis un FTP

Toutes les classes sont instanciées depuis des fichiers .cdx et le fichier mods.txt
Les différentes classes sont le coeur du jeu:
	-Circuit
	-Profil
	-Voiture
	-Moteur
	-PriseAir
	-Spoiler
	-Pneus

Tout ce qui n'est pas objet ne sert qu'à faire:
	-des verifications (sauvegarde...)
	-des demandes (choix des menus...)
	-des calculs (courses...)

Les conventions de ce programme sont:
	-des majuscules au début des classes et des objets (pointeurs ou non)
	-les attributs commencent par m_
	-les threads commencent par t_
	-les variables globales non statiques sont dans l'espace de nommage GLOBAL
	-pour les entités composées de plusieurs mots, la premiere lettre est en minuscule, la premiere lettres des autres mots sont en majuscules. Exemple: maVariableDecimale
	-les using namespace sont prohibés
	-ce programme se veut portable, les fonctions system() sont donc prohibées
	-un pointeur qui n'a pas ou plus de cible doit pointer sur 0, (et non NULL, qui n'est pas portable).
	-toutes les variables ne sont pas définies dès le début d'une fonction: difficile à lire et utilise des ressources parfois inutiles.

===============
*/


//main.cpp

namespace GLOBAL
{
	bool dureeNormale = true;
	bool donne100000Credits = false;
	bool toutGratuit = false;
	bool vainqueur = false;
	bool MeilleureVoiture = false;
	bool debloqueMap = false;
	bool debloqueAchievement = false;
}

#include <unistd.h>

#include "launcher.h"
#include "menusPrincipaux.h"
#include "fonctions.h"


//argc = nombre d'arguments, argv = tableau de string contenant les arguments. argv[0] est toujours le nom de l'executable
int main(/* int argc, char * argv[] */)
{
	try
	{
		clrscreen();
		std::srand(std::time(0)); //INITIALISATION DE L'ALEATOIRE
		miseAJour();//on verifie et fait les mises à jour
		std::cout << "Chargement en Cours...\n";
		sleep(2.0f);
		clrscreen();
		std::cout << "Pour jouer dans les meilleures conditions,\nbasculez en plein ecran !\n\n";
		menuRacedriver();//on lance le coeur du jeu
	}
	catch(std::bad_alloc const& erreur) //on attrape une eventuelle erreur d'allocation de memoire
	{
		error(erreur.what());
	}
	catch(std::exception const& erreur)	//on attrape une eventuelle erreur standard
	{
    	error(erreur.what());
	}
	catch(std::string erreur)
	{
		error(erreur);
	}
	catch(...) 	//on attrape une eventuelle erreur que nous ne pouvons définir
	{
		error("Le programme a rencontre un probleme non defini.");
	}

	return 0;
}
//sousMenus.h
#ifndef SOUSMENUS_HH_
#define SOUSMENUS_HH_

#include <iostream>
#include "Profile.hh"
#include "Track.hh"
#include "Race.hh"
#include"Game.hh"

void menuCourseLibre(); //Menu de Course libre (lobby sp)

int menuConsulterGarage(const int& mode = 0);
void menuAtelier(const int& numeroBox);
void menuAtelierSpoiler(const int& numeroBox);
void menuAtelierEngine(const int& numeroBox);
void menuMaintenance(const int& numeroBox);
void menuAcheterBox();

void menuBuyCar();
void menuAchatCar();
void menuConcessionaireAchat();
void menuVenteCar(const int& numeroBox);

void menuDifficulte();
void menuChangementNomProfile();

#endif /* !SOUSMENUS_HH_ */

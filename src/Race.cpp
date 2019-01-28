#include <chrono>
#include <thread>
#include <functional>
#include "Menu.hh"
#include "Race.hh"
#include "Accident.hh"

std::vector<std::string> Race::driversCollection = std::vector<std::string>();

Race::Race(std::shared_ptr<Car> pCar, Track &pTrack)
{
	_players.push_back(Concurrent(Profile::active->name, pCar));
	_track = std::make_shared<Track>(pTrack);
}

void Race::loadDrivers()
{
	DataFile file("./Data/Events/Drivers.json");

	if (!file.load())
	{
		throw (std::runtime_error("Error loading tracks"));
	}
	const json &data = file.getData();
	for (size_t i = 0; i < data["collection"].size(); i++)
	{
		driversCollection.push_back(data["collection"][i].get<std::string>());
	}
}

bool Race::preparations()
{
	int prixCourse;
	auto player = std::find_if(_players.begin(), _players.end(),
    			[=] (const Concurrent &c) { return (c.name == Profile::active->name); });

	prixCourse = 50;
	if(Profile::active->credits < prixCourse)
	{
		Menu::alert("Vous ne disposez pas d'assez de crédits pour payer les preparatifs.");
		return (false);
	}
	else if(player->car->getDurability() < 20)
	{
		Menu::alert("Votre vehicule est trop endommage pour concourir.");
		return (false);
	}
	else if(player->car->getTires()->getDurability() < 15)
	{
		Menu::alert("Vos pneus sont trop uses pour concourir.");
		return (false);
	}
	Terminal::get().clearScreen(); //On flushe l'ancien ecran
	if(player->car->getNiveauNitro().count() < 100)
	{
		Menu::msg("Attention: Votre reservoir de nitro n'est pas plein.\n");
	}
	if(player->car->getTires()->getDurability() < 55)
	{
		Menu::msg("Attention: Tires deteriores.\n");
	}
	Terminal::get() << "\nPreparatifs\n";
	Terminal::get() << "====================\n";
	Terminal::get() << "Credits: " << Profile::active->credits << "c\n";
	Terminal::get() << "====================\n";
	Terminal::get() << "Le montant total des preparatifs du circuit: " << _track->name << "\n";
	Terminal::get() << "S'elevent a " << prixCourse << "c\n\n";
	if(Menu::askConfirmation())
	{
			Terminal::get().clearScreen();
			randomizeOpponents(7);
			return (true);
	}
	Terminal::get().clearScreen();
	Menu::alert("Paiement annule par l'utilisateur");
	return (false);
}

void Race::randomizeOpponents(size_t count)
{
	std::vector<std::string> usedNames;
	std::string driver;

	for (size_t i = 0; i < count; i++)
	{
		std::shared_ptr<Car> car = std::make_shared<Car>(Car::collection[rand() % 2]);
		do
		{
			driver = driversCollection[rand() % driversCollection.size()];
		} while (std::find(usedNames.begin(), usedNames.end(), driver) != usedNames.end());
		usedNames.push_back(driver);
		_players.push_back(Concurrent(driver, car));
	}
}

bool Race::start()
{
	auto player = std::find_if(_players.begin(), _players.end(),
    			[=] (const Concurrent &c) { return (c.name == Profile::active->name); });

	Terminal::get() << "Bienvenue à tous et a toutes !\n"
									<< "Aujourd'hui va se derouler l'evenement tant attendu par tous les fans de sportives,"
									<< "tout le monde s'est reuni et l'ambiance est a son comble sur le circuit: " << _track->name << ".\n"
									<< "On m'annonce qu'il totalise " << _track->getLength() << " Km, et comprend pas moins de <JSPCB> de virages serres !\n"
									<< "<Inserer commentaire meteo>" << "\n"
									<< "D'autre part, il y a un vent de Force <ZAIREAU> dans l'enceinte du circuit.\n\n"
									<< "Sans attendre passons tout de suite a la liste des Participants:\n\n";
	//on liste les concurrents
	for (size_t i = 0; i < _players.size(); i++)
	{
		Terminal::get() << "En position " << i+1 << ", " << _players[i].name << " - " << _players[i].car->manufacturer << " " << _players[i].car->name << "\n";
	}
	Terminal::get() <<"\n\nPressez [ENTREE] pour commencer la course.\n";
	getch();

	Terminal::get().clearScreen();
	Menu::msg("Depart dans 3...");
	std::this_thread::sleep_for(std::chrono::seconds(1));
	Terminal::get().clearScreen();
	Menu::msg("Depart dans 2...");
	std::this_thread::sleep_for(std::chrono::seconds(1));
	Terminal::get().clearScreen();
	Menu::msg("Depart dans 1...");
	std::this_thread::sleep_for(std::chrono::seconds(1));
	Terminal::get().clearScreen();
	Menu::msg("GO !");
	std::this_thread::sleep_for(std::chrono::seconds(1));
	compute(); //Calculer la course
	Terminal::get() <<"\n\nPressez [ENTREE] pour voir les resultats.\n";
	getch();
	std::sort(_players.begin(), _players.end(), std::greater<Concurrent>());
	if (player - _players.begin() < 3 && !player->out) Profile::active->careerStats.victories++;//Si le joueur finit sur le podium & pas d'accident
	else Profile::active->careerStats.losses++;
	//on affiche les resultats
	for (size_t i = 0; i < _players.size(); i++)
	{
		Terminal::get() << "[" << i+1 << "e] = " << _players[i].position << "="
										<< _players[i].name << " - " << _players[i].car->manufacturer << " " << _players[i].car->name << "\n";
	}
	Terminal::get() <<"\n\n";
	Profile::active->careerStats.races++;
	Terminal::get() <<"Pressez [ENTREE] pour continuer.\n";
	getch();
	Terminal::get().clearScreen();
	Profile::active->save();
	return (true);
}

void Race::compute()
{
	auto player = std::find_if(_players.begin(), _players.end(),
    			[=] (Concurrent &c) { return (c.name == Profile::active->name); });
	std::vector<int> probaAccident = calculerProbaAccident();
	size_t rtick = 0;

	while (!player->out && player->position < _track->getLength())
	{
		for (size_t i = 0; i < _players.size(); i++)
		{
			if (_players[i].out) continue; //Skip out _players
			_players[i].car->update(omni::Second(1), omni::Meter(0));
			_players[i].position += _players[i].car->getVitesse() * omni::Second(1);
			if (_players[i].position > _track->getLength()) _players[i].out = true;
			if((rtick % 10 == 0) && std::rand() % 101 < probaAccident[i]) //each 10 ticks of 1 sec
			{
				Terminal::get() << "Tick " << rtick % 10 << ":\n";
				_players[i].out = true;
				if(i == 0) Profile::active->careerStats.accidents++;
				Terminal::get() << "Le joueur " << _players[i].name << " " << Accident::collection[rand() % Accident::collection.size()].message <<"\n";
			}
		}
			rtick++;
	}
}


std::vector<int> Race::calculerProbaAccident()
{
	std::vector<int> results;

	for (size_t i = 0; i < _players.size(); i++)
	{
		results.push_back(std::rand()%25);
	}
	return (results);
}

Concurrent::Concurrent(std::string n, std::shared_ptr<Car> c)
 : name(n), car(c), out(false), position(0)
{
}

bool operator==(const Concurrent &a, const Concurrent &b)
{
	return (a.name == b.name);
}

bool operator>(const Concurrent &a, const Concurrent &b)
{
	return (a.position > b.position);
}
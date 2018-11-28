#ifndef PROFILE_HH_ // _h car erreur de compil sinon
#define PROFILE_HH_ // idem

#include <iostream>
#include <string>
#include <cfloat>
#include "sha/sha.h"
#include "Garage.hh"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

struct Stats {
	int races;
	int victories;
	int losses;
	int accidents;
	int creditsEarned;
	int carBought;

	Stats(int r = 0, int v = 0, int l = 0, int a = 0, int cr = 0, int c = 0)
	{
		races = r;
		victories = v;
		losses = l;
		accidents = a;
		creditsEarned = cr;
		carBought = c;
	}
};

class Profile : public MenuModule
{
public:
	Profile(const std::string &name);
	Profile(const json &data);
	~Profile();

	void registerMethods();

	static void create(const std::string &name);
	static void load(const std::string &name);
	void save();

	static void listerSauvegardes();
	static int compterSauvegardes();
	static void supprimerProfile(const int& numeroSave);
	static bool compatible(Profile& Player, const int& numeroBox, const char& rangNewPiece);

	bool payer(const int& prix);

	static std::shared_ptr<Profile> active;

	std::string name;
	int difficulty;
	int credits;

	Garage garage;

	//Stats
	Stats careerStats;
};

bool operator!=(Profile& Player, Profile& PlayerSaved);

void to_json(json& j, const Profile& garage);

#endif /* !PROFILE_HH_ */

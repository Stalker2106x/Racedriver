
//Engine.h

#ifndef ENGINE_HH_
#define ENGINE_HH_

#include <string>
#include <fstream>
#include <sstream>

#include "algos.hh"
#include "Game.hh"
#include "Part.hpp"
#include "Collection.hpp"

enum Energy {
	Diesel,
	Gasoline
};

class Engine : public Part
{
public:
	Engine(const json &data);
	~Engine();

  virtual std::string info();

  static const std::string getPath() { return ("Engines"); };

	static float returnPrixCarburant(const std::string& carburant);

	float getVitesse() const;
	float getAcceleration() const;
	Energy getTypeCarburant() const;
	float getConsommation() const;
	int getPrix() const;
	float getPrixCarburant() const;

	static Collection<Engine> collection;

protected:
	int _price;
	float _speed;
	float _acceleration;
	Energy _energy;
	float _consommation;
};


#endif /* !ENGINE_HH_ */

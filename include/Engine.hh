#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "Part.hpp"
#include "Collection.hpp"

enum Energy {
	Diesel,
	Gasoline,
	Electric
};

[[maybe_unused]]static const char* EnergyNames[] = { "Diesel", "Gasoline", "Electric" };

class Engine : public Part
{
public:
  Engine(const json &data);

  virtual std::string info();
	void update(omni::KilometerPerHour speed, omni::Inch diameter);

  static const std::string getPath() { return ("Engines"); };
	static Collection<Engine> collection;

	//Manufacturer
	omni::Horsepower mPower;
	omni::revolutionPerMinute<int> mRevolutions;
	Energy energy;
	int price;

	//Instance
	omni::Horsepower power;
	omni::revolutionPerMinute<int> revolutions;
	omni::NewtonMeter torque;
};

#endif /* !ENGINE_HPP_ */
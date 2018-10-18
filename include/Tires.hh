//Tires.h

#ifndef TIRES_HH_
#define TIRES_HH_

#include <string>
#include <sstream>
#include "DataFile.hh"

#include"algos.hh"
#include"Game.hh"

class Tires
{
public:
	Tires(const std::string& marque, const char& rang, const int& usure);
	Tires(const json &data);
	~Tires();

	static bool loadCollection();
	static Tires* chargerTires(const int& id, const int& usure = 100);
	static void listerTires();

	std::string getMarque() const;
	int getDurabilite() const;
	int getPrix() const;
	char getRang() const;

	void setDurabilite(int value);

protected:

	std::string _brand;
	char _rank; //definit la voiture qui peut les porter
	int _durability; //definit la vitesse d'usure des pneus
	int _price;
};

#endif /* !TIRES_HH_ */

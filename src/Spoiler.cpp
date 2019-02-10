//Spoiler.cpp
#include "Spoiler.hh"
#include "Menu.hh"

Collection<Spoiler> Spoiler::collection = Collection<Spoiler>();

Spoiler::Spoiler(const json &data)
 : Part(data), aerodynamic(data["aerodynamic"].get<int>())
{
}

Spoiler::~Spoiler()
{

}

void Spoiler::expose(sol::state &lua)
{
    lua.new_usertype<Spoiler>("Spoiler",
      // constructor
      sol::constructors<Spoiler(const json &data)>(),

      "getId", &Spoiler::getId
    );
}
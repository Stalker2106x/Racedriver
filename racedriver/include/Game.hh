#ifndef GAME_HH_
#define GAME_HH_

#include <memory>
#include "Terminal.hh"

#define GAME_VERSION  "Alpha 2.0.0"
#define SERVER_PATH "http://racedriver.url.ph/"
#define PWD_SALT	"RaceDriver"

class Game
{
public:
  Game();
  int main();
  Terminal &getTerm();
  void printASCIILogo();
  void removeUpdatePackage();
  void update();

  static std::unique_ptr<Game> instance; //Singleton handle
private:
  Terminal _term;
};

#endif /* !GAME_HH_ */
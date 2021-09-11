#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include<string>
using namespace std;

class GamePlay
{
private:

public:
  GamePlay();
  ~GamePlay();
  // a function to convert user's B2 to 1,1 (array indexes/coordinates)
  string fireAt(); // user chooses coordinates to shoot at
  bool isSunk(); // did opponents ship sink
  bool quitGame(); // end game command
};

#endif

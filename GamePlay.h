#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <iostream>
#include "Ship.h"
/* include user interaction and board */
using namespace std;

class GamePlay
{
    public:
        GamePlay::~GamePlay();

        void fireAt(char x, int b);

        bool isHit();

        bool isMissed();

        void hits();

        int getHits();



};

#endif
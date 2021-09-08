#ifndef USERINTERACTION_H
#define USERINTERACTION_H
#include "Ship.h"
#include "ViewBoard.h"
#include <iostream>

using namespace std;

class UserInteraction
{
    public:
        UserInteraction::~UserInteraction();

        UserInteraction(int numShips, string pName);

        string getPname();

        Ships setShip();

        void exit();

    private:

        int numShips;

        string name;

        ViewBoard viewMyboard;
        
        ViewBoard viewOpponentboard;



};

#endif
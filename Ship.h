#ifndef SHIP_H
#define SHIP_H
#include <iostream>
/* include other neccesary files */
using namespace std;

class Ships
{
    public:
        
        Ships::~Ships();

        void setSize(int length);

        int getSize();

        bool horizontal();
        //may not need both of these
        bool vertical();

        void setShip(char a, int x);

        char getLetter();

        int getNumber();

};
#endif

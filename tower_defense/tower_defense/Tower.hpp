#ifndef TOWER HPP
#define TOWER HPP

#include <iostream>

class Tower{
	int x;
	int y;
	int rad;
	int dmg;

public:
	Tower(int x,int y,int rad,int dmg);
	int getX()const;
	int getY()const;
	int getR()const;
	int getDmg()const;
};

#endif
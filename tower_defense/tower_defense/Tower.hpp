#ifndef TOWER_HPP
#define TOWER_HPP

#include <iostream>

class Tower{
	int x;
	int y;
	double rad;
	double dmg;

public:
	Tower(int x,int y,double rad,double dmg);
	int getX()const;
	int getY()const;
	double getR()const;
	double getDmg()const;
	void print();
};

#endif
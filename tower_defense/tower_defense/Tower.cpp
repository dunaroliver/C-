#include "Tower.hpp"

Tower::Tower(int x, int y, int rad, int dmg) :x(x), y(y), rad(rad), dmg(dmg){

}

int Tower::getX()const{
	return x;
}

int Tower::getY()const{
	return y;
}

int Tower::getR()const{
	return rad;
}

int Tower::getDmg()const{
	return dmg;
}



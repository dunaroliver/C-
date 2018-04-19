#include "Tower.hpp"

Tower::Tower(int x, int y, double rad, double dmg) :x(x), y(y), rad(rad), dmg(dmg){

}

int Tower::getX()const{
	return x;
}

int Tower::getY()const{
	return y;
}

double Tower::getR()const{
	return rad;
}

double Tower::getDmg()const{
	return dmg;
}

void Tower::print(){
	std::cout << "x: " << x << ",y: " << y << ",r: " << rad << ", damage: " << dmg;
}



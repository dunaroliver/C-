#include "Soldier.hpp"

Soldier::Soldier(int y, int startRound, int speed, int hp) :y(y), startRound(startRound), speed(speed), hp(hp){

}

int Soldier::getY()const{
	return y;
}

int Soldier::getStartRound()const{
	return startRound;
}

int Soldier::getSpeed()const{
	return speed;
}

int Soldier::getHp()const{
	return hp;
}

int Soldier::getX()const{
	return x;
}

bool Soldier::setX(){
	x -= speed;
	if (x < 0)return false;
	return true;
}
bool Soldier::setHp(int dmg){
	hp -= dmg;
	if (hp < 0) return false;
	return true;
}
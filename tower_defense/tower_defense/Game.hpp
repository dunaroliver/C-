#ifndef JATEK HPP
#define JATEK HPP

#include "Soldier.hpp"
#include "Tower.hpp"
#include <list>

class Game{
	int x;
	int y;
	int round;
	int number_of_towers;
	int number_of_soldiers;
	std::list <Soldier> soldiers;
	std::list <Tower> towers;

public:
	Game(int x,int y);
	~Game();
	bool addTower(Tower t);
	bool addSoldier(Soldier *s);
	int getRound()const;
	bool nextRound();
	bool removeSoldier(Soldier s);
	int getX()const;
	int getY()const;
};

#endif
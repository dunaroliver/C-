#include "Game.hpp"

Game::Game(int x, int y):x(x),y(y){
	round=0;
	number_of_towers=0;
	number_of_soldiers=0;
}

Game::~Game(){
	delete(soldiers);
	delete(towers);
}

bool Game::addTower(Tower t){
	towers.insert(t);
}
bool addSoldier(Soldier *s);
int getRound()const;
bool nextRound();
bool removeSoldier(Soldier *s);
int getX()const;
int getY()const;
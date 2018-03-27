#ifndef SOLDIER HPP
#define SOLDIER HPP

class Soldier{
	int y;
	int x;
	int startRound;
	int speed;
	int hp;

public:
	Soldier(int y,int startRound,int speed,int hp);
	int getY()const;
	int getStartRound()const;
	int getSpeed()const;
	int getHp()const;
	int getX()const;
	bool setX();
	bool setHp(int dmg);

};

#endif
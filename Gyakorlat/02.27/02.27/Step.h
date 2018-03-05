#ifndef TESTER HPP /*header guard*/
#define TESTER HPP

#include <iostream>

class Step{
	int dx;
	int dy;

public:
	Step(int x, int y);
	int getX() const;
	int getY() const;
};


#endif
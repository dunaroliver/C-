#ifndef TESTER HPP /*header guard*/
#define TESTER HPP

#include <iostream>
class Jatek{
	int tabla[10][10];
	bool xkov;
	int lastx[2];
	int lasty[2];


public:
	Jatek();
	void print() const;
	void getMove(int x, int y);
	bool isValidMove(int x, int y) const;
	bool isGameOver() const;
	bool isXkov() const;
	void setXkov();
	bool isFinished() const;
}; /*kell a ;*/
#endif
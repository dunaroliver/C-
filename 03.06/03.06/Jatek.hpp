#ifndef TESTER HPP /*header guard*/
#define TESTER HPP

#include <iostream>
#include <iomanip>
class Jatek{
	int **tabla;
	bool xkov;
	int lastx[2];
	int lasty[2];
	int size;


public:
	Jatek();
	Jatek(int size);
	~Jatek();
	void print() const;
	void fancyPrint() const;
	void getMove(int x, int y);
	bool isValidMove(int x, int y) const;
	bool isGameOver() const;
	bool isXkov() const;
	void setXkov();
	bool isFinished() const;
	void resize();
}; /*kell a ;*/
#endif
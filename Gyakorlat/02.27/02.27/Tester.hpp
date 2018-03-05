#ifndef TESTER HPP /*header guard*/
#define TESTER HPP

#include <iostream>
#define INITIAL_DEFAULTMAXD 1
struct Step{
	int dx;
	int dy;
	struct Step *next;
};

class Tester{
	const int maxd;
	const int width;
	const int height;
	int x;
	int y;
	struct Step *steps;
	bool isCorrectNextStep(int dx, int dy) const;
	int** matrix;

	public:
		struct Step* Tester::getLastStep() const;
		static int defaultmaxd;
		Tester(int width, int height,int maxd=defaultmaxd);
		~Tester(); /*destruktor*/
		void print() const;
		bool isFinished() const;
		bool move(int dx, int dy);
		void static setDefaultMaxdD(int newmaxd);
		int **getMatrix();

}; /*kell a ;*/
#endif
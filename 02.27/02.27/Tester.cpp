#include "Tester.hpp"
int Tester::defaultmaxd =INITIAL_DEFAULTMAXD;
void static setDefaultMaxdD(int newmaxd){
	if (newmaxd >= 1) Tester::defaultmaxd = newmaxd;
}

Tester::Tester(int width, int height,int maxd):width(width),height(height),maxd(maxd),steps(NULL){
	/*this->width = width;
	this->height = height; ha const akkor nem jó mert error lesz*/
	x = y = 0;
	steps = new struct Step;
	steps->dx = 0;
	steps->dy = 0;
	steps->next = NULL;
	matrix =(int**) new int[width];
	for (int i = 0; i<width; i++){
		matrix[i] = (int*)new int[height];
	}
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			matrix[i][j] = 0;
		}
	}
}

Tester::~Tester(){
	struct Step* tmp = steps;
	struct Step* tmpnext;
	do{
		tmpnext = tmp->next;
		delete tmp;
		tmp = tmpnext;
	} while (tmp != NULL);

	for (int i = 0; i < width; i++){
		delete [] matrix[i];
	}
	delete [] matrix;
}
void Tester::print() const{
	int xossz, yossz;
	xossz = 0;
	yossz = 0;
	std::cout << "x: " << x << ", y: " << y<<"\n";
	/*struct Step *tmp = steps;
	while (tmp != NULL){
		std::cout << "\tdx: " << tmp->dx << ",dy: " << tmp->dy << "\n";
		tmp = tmp->next;
	} ¡¡¡¡¡az ugyan az a for ciklusba¡¡¡¡ */

	for (struct Step *tmp = steps; tmp != NULL; tmp = tmp->next){
		xossz += tmp->dx;
		yossz += tmp->dy;
		std::cout << "\tdx: " << tmp->dx << ",dy: " << tmp->dy << "\n";
	}
	matrix[xossz][yossz] = 1;
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}


bool Tester::isFinished() const{
	return x == (width - 1) && y == (height - 1);
}

bool Tester::isGameOver() const{
	if (isFinished()) return false;
	for (int dx = getLastStep()->dx - defaultmaxd; dx <= getLastStep()->dx + defaultmaxd; dx++){
		for (int dy = getLastStep()->dy - defaultmaxd; dy <= getLastStep()->dy + defaultmaxd; dy++){
			if (isCorrectNextStep(dx, dy)) return false;
		}
	}
		return true;
}

bool Tester::isCorrectNextStep(int dx, int dy) const{
	int newx = x + dx;
	int newy = y + dy;
	if (newx < 0 || newx >= width || newy < 0 || newy >= height) return false;
	struct Step* last = Tester::getLastStep();
	return !(dx<last->dx - maxd || dx>last->dx + maxd || dy<last->dy - maxd || dy>last->dy + maxd);
}

struct Step* Tester::getLastStep() const{
	struct Step *tmp = steps;
	while (tmp->next != NULL) tmp = tmp->next;
	return tmp;
}


bool Tester::move(int dx, int dy){
	int newx = x + dx;
	int newy = y + dy;
	if (!isCorrectNextStep(dx,dy)) return false;
	else{
		x = newx;
		y = newy;
		struct Step * newstep = new struct Step;
		newstep->dx = dx;
		newstep->dy = dy;
		newstep->next = NULL;
		struct Step* last=Tester::getLastStep();
		last->next = newstep;		
		return true;
	}
}
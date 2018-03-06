#include "Jatek.hpp"
int main(){
	int x, y;
	Jatek jatek(10);
	while (!jatek.isGameOver() && !jatek.isFinished()){
		jatek.fancyPrint();
		if (jatek.isXkov()) std::cout << "X kovetkezik: ";
		else std::cout << "Y kovetkezik: ";
		std::cin >> x;
		std::cin >> y;
		jatek.getMove(x, y);
	}
	if (!jatek.isGameOver()) jatek.fancyPrint();
}
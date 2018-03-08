#include "Jatek.hpp"
int main(){
	int x, y;
	bool ok = false;
	Jatek jatek(10);
	jatek.fancyPrint();
	while (!jatek.isGameOver() && !ok){
		if (jatek.isXkov()) std::cout << "\nX kovetkezik: \n";
		jatek.aiMove();
		jatek.fancyPrint();
		if (jatek.isFinished()){
			ok = true;
			std::cout << "\nX nyert!!!\n";
		}
		else{
			std::cout << "\nO kovetkezik: ";
			std::cin >> x;
			std::cin >> y;
			jatek.getMove(x, y);
			jatek.fancyPrint();
			if (jatek.isFinished()){
				ok = true;
				std::cout << "\nO nyert!!!\n";
			}
		}
	}
}
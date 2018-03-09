#include "Jatek.hpp"

void menu();
int tablameret();
bool PvAi(int size);
bool PvP(int size);

int main(){
	menu();
	return 0;
}

void menu(){
	system("chcp 1250");
	system("cls");
	int x=0, y;
	bool ok = false;
	bool good = false;
	int size;
	clock_t wait;
	clock_t wait2;


	do{
		std::cout << "5 in a row játék.\n\nVálasszon játékmódot!\nPvP: 1\nPvAI: 2\nExit: 3\n";
		std::cin >> x;
		if (std::cin.fail()){
			std::cout << "Csak 1 és 3 közötti szám elfogadott.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else{
			if (x != 2 && x != 1 && x!=3){
				std::cout << "Csak 1-es és 2-es szám elfogadott.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (x == 1){
				size = tablameret();
				if (!PvP(size)) ok = true;
			}
			else if(x==2){
				size = tablameret();
				if (!PvAi(size)) ok = true;
			}
			else ok = true;
		}
	} while (!ok);
	if (ok) ok = false;
}

int tablameret(){
	int x=0;
	bool ok = false;
	std::cout << "Adja meg a tábla kívánt kezdeti méretét.(8-10)\nA pálya késõbb dinamikusan nõni fog.\n";
	do{
		
		if (!(std::cin >> x)){
			std::cout << "Csak egész szám elfogadott.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else{
			if (x<8 || x>10){
				std::cout << "Csak 8 és 10 közötti kezdõérték adható meg.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else{
				return x;
				ok = true;
			}
		}
	} while (!ok);
}

bool PvAi(int size){
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	bool ok = false;
	bool good = false;
	int x;
	int y;
	Jatek jatek(size);
	clock_t wait;
	clock_t wait2;

	jatek.fancyPrint();
	while (!jatek.isGameOver() && !ok){
		if (jatek.isXkov()) std::cout << "\nX következik: \n";
		/*wait = clock();
		wait2 = clock();
		while (wait2 != wait + 1000){
			wait2 = clock();
		}*/
		jatek.aiMove();
		system("cls");
		jatek.fancyPrint();
		if (jatek.isFinished()){
			ok = true;
			std::cout << "\nX nyert!!!\n";
		}
		else{
			do{
				std::cout << "\nO következik: ";
				std::cin >> x;
				if (std::cin.good()){
					std::cin >> y;
					if (std::cin.good()){
						if (jatek.getMove(x, y)){
							system("cls");
							jatek.fancyPrint();
							if (jatek.isFinished()){
								ok = true;
								std::cout << "\nO nyert!!!\n";
							}
							good = true;
						}
					}
					else{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "Csak egész szaám adható meg.\n";
					}
				}
				else{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Csak egész szám adható meg.\n";
				}
			} while (!good);
			if (good) good = false;
		}
	}
	std::cout << "\nSzeretne újat játszani?\nIgen: 1\nNem: 2\n";
	std::cin >> x;
	system("cls");
	if (std::cin.good()){
		if (x == 1) return true;
		else return false;
	}
	else return false;
}

bool PvP(int size){
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	bool good = false;
	int x;
	int y;
	Jatek jatek(size);
	
	jatek.fancyPrint();
	while (!jatek.isGameOver() && !jatek.isFinished()){
		do{
			if (jatek.isXkov()) std::cout << "\nX következik: \n";
			else std::cout << "\nO következik: \n";
			std::cin >> x;
			if (std::cin.good()){
				std::cin >> y;
				if (std::cin.good()){
					if (jatek.getMove(x, y)){
						system("cls");
						jatek.fancyPrint();
						good = true;
					}
				}
				else{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Csak egész szaám adható meg.\n";
				}
			}
			else{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Csak egész szám adható meg.\n";
			}
		} while (!good);
		if (good) good = false;
	}
	if (jatek.isFinished()){
		if (!jatek.isXkov()) std::cout << "\nX nyert!\n";
		else std::cout << "\nO nyert!\n";
	}
	std::cout << "\nSzeretne újat játszani?\nIgen: 1\nNem: 2\n";
	std::cin >> x;
	system("cls");
	if (std::cin.good()){
		if (x == 1) return true;
		else return false;
	}
	else return false;
}


#include "Jatek.hpp"

Jatek::Jatek(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			tabla[i][j] = 0;
		}
	}
	xkov = true;
	lastx[0] = -1;
	lastx[1] = -1;
	lasty[0] = -1;
	lasty[1] = -1;

}

void Jatek::print() const{
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			std::cout << tabla[i][j]<<" ";
		}
		std::cout << "\n";
	}
}

void Jatek::getMove(int x, int y){
	if (isValidMove(x, y)){
		if (isXkov()){
			tabla[x][y] = 1;
			lastx[0] = x;
			lastx[1] = y;
		}
		else{
			tabla[x][y] = 2;
			lasty[0] = x;
			lasty[1] = y;
		}
		setXkov();
	}
	else std::cout << "Hibás lépés.\n";
}

bool Jatek::isValidMove(int x, int y) const{
	if (x < 0 || x>9 || y < 0 || y>9) return false;
	else if (tabla[x][y]) return false;
	else return true;
}

bool Jatek::isGameOver() const {
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (tabla[i][j]==0) return false;
		}
	}
	return true;
}

bool Jatek::isXkov() const{
	return xkov;
}

void Jatek::setXkov(){
	if (isXkov()) xkov = false;
	else xkov = true;
}

bool Jatek::isFinished() const{
	int tmpx=-1;
	int tmpy=-1;
	int szam;
	int db = 0;
	if (isXkov() && (lasty[0]!=-1)){
		tmpx = lasty[0];
		tmpy = lasty[1];
		szam = 2;
	}
	else if (lastx[0]!=-1){
		tmpx = lastx[0];
		tmpy = lastx[1];
		szam = 1;
	}

	if (tmpx != -1){
		/*függõleges*/
		db = 0;
		for (int i = 0; i < 9; i++){
			if (tabla[i][tmpy] == szam) db++;
			else if (db != 5){
				db = 0;
			}
		}
		if (db == 5){
			printf("%c nyert.\n", szam == 2 ? 'Y' : 'X');
			return true;
		}

		/*vízszintes*/
		db = 0;
		for (int i = 0; i < 9; i++){
			if (tabla[tmpx][i] == szam) db++;
			else if (db != 5){
				db = 0;
			}
		}
		if (db == 5){
			printf("%c nyert.\n", szam == 2 ? 'Y' : 'X');
			return true;
		}


		/*fõátló*/
		db = 0;
		int i = tmpx;
		int j = tmpy;
		while (tabla[i-1][j-1] == szam){
			i--;
			j--;
		}
		while (db < 5 && i < 9 && j < 9){
			if (tabla[i][j] == szam){
				db++;
			}
			else if (db != 5){
				db = 0;
			}
			i++;
			j++;
		}
		if (db == 5){
			printf("%c nyert.\n", szam == 2 ? 'Y' : 'X');
			return true;
		}


		/*mellékátló*/
		db = 0;
		i = tmpx;
		j = tmpy;
		while (tabla[i - 1][j + 1] == szam){
			i--;
			j++;
		}
		while (db < 5 && i < 9 && j>0){
			if (tabla[i][j] == szam){
				db++;
			}
			else if (db != 5){
				db = 0;
			}
			i++;
			j--;
		}
		if (db == 5){
			printf("%c nyert.\n", szam == 2 ? 'Y' : 'X');
			return true;
		}
	}
	return false;
}


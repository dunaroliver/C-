#include <iostream>
#include "Tester.hpp" /* nem <> !!!*/
using namespace std;
/*using std::cout; egyenként is lehet*/

int main(){
	//cout << "Hello world!\n"; /*std:: ha nincs using*/
	Tester izebize(10,5,2);
	//Tester izebize("palya.txt");

	int dx, dy;
	while (!izebize.isFinished()){
		do{
			izebize.print();
			cout << "Lepes pls: ";
			cin >> dx;
			cin >> dy;
		} while (izebize.move(dx, dy));
	}
	return 0;
}

/*hf: dx dy lecserélése getx gety ra esetleg, mátrixxal kiíratni, struct helyett osztály*/

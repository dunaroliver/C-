#include <iostream>
#include "Tester.hpp" /* nem <> !!!*/
using namespace std;
/*using std::cout; egyenk�nt is lehet*/

int main(){
	//cout << "Hello world!\n"; /*std:: ha nincs using*/
	Tester izebize(10,5,2);
	//Tester izebize("palya.txt");

	int dx, dy;
	while (!izebize.isFinished()&&!izebize.isGameOver()){
		do{
			izebize.print();
			cout << "Lepes pls: ";
			cin >> dx;
			cin >> dy;
		} while (!izebize.move(dx, dy));
	}
	if (izebize.isFinished()) cout << "Yepeeeeee\n";
	else if (izebize.isGameOver()) cout << "Next time.\n";
	else cout << "Megmerted csin�lni?!\n";
	return 0;
}

/*hf: dx dy lecser�l�se getx gety ra esetleg, m�trixxal ki�ratni, struct helyett oszt�ly*/

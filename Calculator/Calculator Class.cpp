#include <iostream>
#include "Calculator.h"
using namespace std;

int main() {
	Calculator first;
	Calculator second;

	cout << "First pairs of value" << endl;
	first.setNumb(5.0, 7.2);
	first.displayResult();

	cout << endl; // for the sake of visibility

	cout << "Second pairs of value" << endl;
	second.setNumb(3.2, 4.0);
	second.displayResult();


	system("pause");
	return 0;
}
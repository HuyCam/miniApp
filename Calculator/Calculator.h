#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <cmath>
using namespace std;

class Calculator
{
public:
	Calculator();
	~Calculator();
private:
	double numb1_;
	double numb2_;
public:
	double add();
	double subtract();
	double multiply();
	double divide();
	double exponent();
	void setNumb(double numb1, double numb2);
	void displayResult();
};
#endif

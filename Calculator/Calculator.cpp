#include "Calculator.h"
#include <iostream>
using namespace std;


Calculator::Calculator()
{
	numb1_ = 0.0;
	numb2_ = 0.0;
}

Calculator::~Calculator()
{
}


double Calculator::add()
{
	
	return numb1_ + numb2_;
}


double Calculator::subtract()
{
	return numb1_ - numb2_;
}


double Calculator::multiply()
{
	return numb1_ * numb2_;
}


double Calculator::divide()
{
	if (numb2_ == 0) {
		cout << "Error, dividend is 0" << endl;
	}
	return numb1_ / numb2_ ;
}


double Calculator::exponent()
{
	return pow(numb1_,numb2_);
}


void Calculator::setNumb(double numb1, double numb2)
{
	numb1_ = numb1;
	numb2_ = numb2;
}


void Calculator::displayResult()
{
	cout << "Addition: " << add() << endl;
	cout << "Subtraction: " << subtract() << endl;
	cout << "Multiplication: " << multiply() << endl;
	cout << "Division: " << divide() << endl;
	cout << "Exponents: " << exponent() << endl;
}

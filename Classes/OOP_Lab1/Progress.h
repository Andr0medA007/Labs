#pragma once
#include <iostream>
using namespace std;

class Progression {
private:
	double first;
	double second;
	double pow(double x, double y) {
		cout << "ֲûחמג לועמהא pow("<< x<< ","<< y<<")\n";
		double result = 1;
		for (int i = 1; i <= y; i++) {
			result *= x;
		}
		return result;
	}
public:
	Progression(double, double);
	double element(int);
	void setFirst(double);
	void setSecond(double);
};
#pragma once
#include <string>
using namespace std;

class Pay_Money {
private:
	string name;
	double salary;
	int bonus;
public:
	Pay_Money();
	Pay_Money(string, double, int);
	Pay_Money(const Pay_Money&);
	~Pay_Money();
	string getName();
	void setName(string);
	double getSalary();
	void setSalary(double);
	int getBonus();
	void setBonus(int);
	void print();
};

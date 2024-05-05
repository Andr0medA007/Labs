#include <iostream>
#include <string>
#include "money.h"
using namespace std;

Pay_Money::Pay_Money() {
	name = "";
	salary = 0;
	bonus = 0;
	cout << "\n Конструктор по умолчанию для объекта: " << this << endl;
}
Pay_Money::Pay_Money(string name = "", double salary = 0, int bonus = 0) {
	this->name = name;
	this->salary = salary;
	this->bonus = bonus;
	cout << "\n Конструктор с параметрами: " << this << endl;
}
Pay_Money::Pay_Money(const Pay_Money&pay) {
	this->name = pay.name;
	this->salary = pay.salary;
	this->bonus = pay.bonus;
	cout << "\n Конструктор копирования: " << this << endl;
}
Pay_Money::~Pay_Money() {
	cout << "\n Деконструктор для объекта: " << this << endl;
}	
string Pay_Money::getName() { return this->name; }
void Pay_Money::setName(string name) { this->name = name; }
double Pay_Money::getSalary() { return this->salary; };
void Pay_Money::setSalary(double salary) { this->salary = salary; };
int Pay_Money::getBonus() { return this->bonus; };
void Pay_Money::setBonus(int bonus) { this->bonus = bonus; };
void Pay_Money::print() {
	cout << "\n ФИО: " << this->name << "\n Оклад: " << this->salary << "\n Премия: " << this->bonus <<"%"<<endl;
}



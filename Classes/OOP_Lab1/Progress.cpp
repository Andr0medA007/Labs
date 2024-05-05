#pragma once
#include "Progress.h"

Progression::Progression(double first = 1, double second = 1) {
	cout << "Вызов констуктора класса Progression("<< first<< ","<< second<< ")\n";
	this->first = first;
	this->second = second;
}

double Progression::element(int k) {
	cout << "Вызов метода element("<< k<< ")\n";
	return first * pow(second, k);
}

void Progression::setFirst(double a0) {
	cout << "private Поле first(r) = "<< a0<< "\n";
	this->first = a0;
}

void Progression::setSecond(double r) {
	cout << "private Поле second(r) = "<< r<< "\n";
	this->second = r;
}
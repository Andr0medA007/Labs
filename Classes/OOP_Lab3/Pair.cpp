#pragma once
#include "Pair.h"
#include <iostream>
using namespace std;

//перегрузка операции присваивания
Pair::Pair() {
	first = 0;
	second = 0;
}
Pair::Pair(int f = 0,double s = 0) {
	this->first = f;
	this->second = s; 
}
Pair::Pair(const Pair& p) {
	this->first = p.first;
	this->second = p.second;
}
Pair::~Pair() {
}
int Pair::getFirst() { return this->first; }
void Pair::SetFirst(int x) { this->first = x; }
double Pair::getSecond() { return this->second; }
void Pair::SetSecond(double y) { this->second = y; }
void Pair::print() {
	cout << this->first << " : " << this->second << endl;
}
Pair::Pair() {
	first = 0;
	second = 0;
}
Pair::Pair(int f = 0, double s = 0) {
	this->first = f;
	this->second = s;
}
Pair::Pair(const Pair& p) {
	this->first = p.first;
	this->second = p.second;
}
Pair::~Pair() {
}
int Pair::getFirst() { return this->first; }
void Pair::SetFirst(int x) { this->first = x; }
double Pair::getSecond() { return this->second; }
void Pair::SetSecond(double y) { this->second = y; }
void Pair::print() {
	cout << this->first << " : " << this->second << endl;
}

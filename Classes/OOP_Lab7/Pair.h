#pragma once
#include <iostream>
using namespace std;

class Pair {
private:
	int first;
	double second;
public:
	void SetFirst(int x);
	void SetSecond(double y);
	int getFirst();
	double getSecond();
	void print();
	Pair() {}
	Pair(int f, double s) {
		SetFirst(f);
		SetSecond(s);
	}
	Pair(const Pair& p) {
		this->first = p.first;
		this->second = p.second;
	}
	~Pair() {}
	//перегруженные операции 
	Pair operator+(const int& x) const {
		return Pair(this->first + x, this->second);
	}
	Pair operator+(const double& y) const {
		return Pair(this->first, this->second + y);
	}
	Pair operator-(const Pair& p) const {
		return Pair(this->first - p.first, this->second - p.second);
	}
	friend Pair operator+(const int& x, const Pair& p) {
		return p + x;
	}
	Pair& operator*=(Pair& pair) 
	{
		first *= pair.first;
		second *= pair.second;
		return *this;
	}
	friend Pair operator+(const double& y, const Pair& p) {
		return p + y;
	}
	friend ostream& operator<<(ostream& str, Pair& p) {
		str << p.first << " : " << p.second << endl;
		return str;
	}
	friend istream& operator>>(istream& stream, Pair& p) {
		cout << "Первое число: " << endl;
		stream >> p.first;
		cout << "Второе число: " << endl;
		stream >> p.second;
		return stream;
	}
};


int Pair::getFirst() { return this->first; }
void Pair::SetFirst(int x) { this->first = x; }
double Pair::getSecond() { return this->second; }
void Pair::SetSecond(double y) { this->second = y; }
void Pair::print() {
	cout << this->first << " : " << this->second << endl;
}

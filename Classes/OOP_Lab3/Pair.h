#pragma once
#include <iostream> 
using namespace std;

class Pair
{
private:
	int first;
	double second;
public:
	Pair();
	Pair(int f, double s);
	Pair(const Pair& p);
	~Pair();
	void SetFirst(int x);
	void SetSecond(double y);
	int getFirst();
	double getSecond();
	void print();

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
	friend Pair operator+(const double& y, const Pair& p) {
		return p + y;
	}
	friend ostream& operator<<(ostream& str, const Pair& p) {
		str <<" "<< p.first << " : " << p.second << endl;
		return str;
	}
};


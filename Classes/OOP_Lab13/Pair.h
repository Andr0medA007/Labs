#pragma once
#include <iostream>
using namespace std;

class Pair {
private:
	int first;
	double second;
public:
	Pair() { first = 0; second = 0; };
	Pair(int x, double y) {
		setFirst(x);
		setSecond(y);
	}
	Pair(const Pair& p){
		this->first = p.first;
		this->second = p.second;
	}
	~Pair() {};
	void Print(const Pair&p) { cout << this->first << " : " << this->second << endl; };
	Pair operator+(Pair& p) {
		first = first + p.first;
		second = second + p.second;
		return *this;
	}
	Pair operator-(Pair& p) {
		first = first - p.first;
		second = second - p.second;
		return *this;
	}
	void setFirst(const int& x) { this->first = x; };
	void setSecond(const double& y) { this->second = y; }
	int getFirst() { return this->first; };
	double getSecond() { return this->second; };
	void operator=(const Pair& p) {
		first = p.first;
		second = p.second;
	}
	bool operator>(const Pair& p) {
		if (first > p.first && second > p.second) {
			return 1;
		}
		else {
			return 0;
		}
	}
	bool operator<(const Pair& p) {
		if (first < p.first && second < p.second) {
			return 1;
		}
		else {
			return 0;
		}
	}
	friend ostream& operator<<(ostream& stream, Pair& p) {
		stream << p.first << " : " << p.second << endl;
		return stream;
	}
	friend istream& operator>>(istream& stream, Pair& p) {
		cout << "Первое число: "; stream >> p.first;
		cout << "Второе число: "; stream >> p.second;
		return stream;
	}
};
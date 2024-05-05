#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class Pair {
private:
	int first;
	double second;
public:
	Pair() { first = 0; second = 0; };
	Pair(int first, int second) {
		setfirst(first);
		setsecond(second);
	}
	void setfirst(int first) { first = first; }
	void setsecond(int second) { second = second; }
	int getfirst() const { return first;  }
	int getsecond() const { return second; }
	Pair& operator -= (Pair& p) {
		first -= p.first;
		second -= p.second;
		return *this;
	}
	Pair& operator += (double num) {
		int var = num;
		if (num - var == 0) {
			first += num;
		}
		else {
			second += num;
		}
		return *this;
	}
	bool operator >=(Pair& p) {
		return first + second >= p.first + p.second;
	}
	friend istream& operator>>(istream& stream, Pair& p) {
		cout << "Первое число: "; stream >> p.first;
		cout << "Второе число: "; stream >> p.second;

		return stream;
	}
	friend ostream& operator<<(ostream& stream, Pair& p) {
		stream << p.first << ":" << p.second;
		return stream;
	}
	friend fstream& operator<<(fstream& stream, Pair& p) {
		stream << p.first << "\n" << p.second << "\n";
		return stream;
	}
	friend fstream& operator>>(fstream& stream, Pair& p) {
		stream >> p.first;
		stream >> p.second;
		return stream;
	}
};
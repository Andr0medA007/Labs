#include <iostream>
#include <list>
#include <queue>
#include <functional>
#include <algorithm>
#include <random>
#include "Pair.h"

using namespace std;

ostream& operator<<(ostream& stream, list<Pair>& l);
void random(Pair& p);

int main() {
	system("chcp 1251 > Null");
	srand(time(0));
	int n;
	do {
		cout << "������� ������ ������: " << endl;
		cin >> n;
	} while (n < 1);

	Pair sum;
	list<Pair> list_1(n);
	generate(list_1.begin(), list_1.end(), []() {Pair p; random(p); return p; });
	cout << "��������������� ������: " << endl << list_1 << endl;
	for_each(list_1.begin(), list_1.end(), [&sum](Pair& p) {sum = sum + p; });
	sum.setFirst(sum.getFirst() / list_1.size());
	sum.setSecond(sum.getSecond() * 10000 / list_1.size() * 0.0001);
	cout << "������� ��������������: " << sum << endl;

	list_1.push_back(sum);
	cout << "���� ������: " << endl << list_1 << endl;

	Pair p_one, p_two;

	cout << "������� ��� ���� �����, �� ��������� ������� ����� ������� ��� ����: " << endl;
	cout << "������ ����: " << endl;
	cin >> p_one;
	cout << "������ ����: " << endl;
	cin >> p_two;

	if (p_one > p_two) {
		swap(p_one, p_two);
	}

	list<Pair>::iterator s = remove_if(list_1.begin(), list_1.end(), [p_one, p_two](Pair& p) {return p > p_one && p < p_two; });
	list_1.erase(s, list_1.end());

	cout << endl << "����� �������� ���������: " << endl << list_1 << endl;

	pair<list<Pair>::iterator, list<Pair>::iterator> stl_pair = minmax_element(list_1.begin(), list_1.end());
	cout << "����������� �������: " << *stl_pair.second << endl;
	cout << "������������ �������: " << *stl_pair.first << endl;

	Pair sum_pair(stl_pair.first->getFirst() + stl_pair.second->getFirst(), stl_pair.first->getSecond() + stl_pair.second->getSecond());
	cout << "����� ��������� � ��������: " << sum_pair << endl;
	for_each(list_1.begin(), list_1.end(), [&sum_pair](Pair& p) {p = p + sum_pair; });
	cout << "����� ���������� ����� ������������� � ������������ �������� � ������ ����: " << endl;
	cout << list_1 << endl;

	cout << "������� ������ ����� ��� ������:" << endl;
	int f;
	cin >> f;
	auto i = find_if(list_1.begin(), list_1.end(), [&f](Pair& p) {return f == p.getFirst(); });
	if (i != end(list_1)) {
		cout << "������� ������" << *i << endl;
	}
	else {
		cout << "������� �� ������" << endl;
	}
	return 0;
}

ostream& operator<<(ostream& stream, list<Pair>& l) {
	for_each(l.begin(), l.end(), [](Pair& p) {cout << p << endl; });
	return stream;
}
void random(Pair& p) {
	int x = rand() % 1000;
	double y = (rand() % 10000) * 0.01;
	p = Pair(x, y);
}


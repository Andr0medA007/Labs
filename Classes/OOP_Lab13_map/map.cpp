#include <iostream>
#include <functional>
#include <algorithm>
#include "Pair.h"
#include <map>
using namespace std;

void random(Pair& p) {
	int x = rand() % 1000;
	double y = (rand() % 10000) * 0.01;
	p = Pair(x, y);
};
void fill_map(map <Pair, Pair>& my_map, int m_size) {
	Pair p1{ 0,0 }, p2{ 0,0 };
	for (int i = 0; i < m_size; i++) {
		random(p1);
		random(p2);
		my_map[p1] = p2;
	}
}
ostream& operator<<(ostream& stream, pair<Pair, Pair> p) {
	stream << "���� - " << p.first << "\n �������� - " << p.second << endl;
	return stream;
}
ostream& operator<<(ostream& stream, map<Pair, Pair>& my_map) {
	map<Pair, Pair>::const_iterator It = my_map.begin();
	while (It != my_map.end()) {
		cout << *It++;
	}
	return stream;
}
bool is_in_range(Pair& key, Pair& min, Pair& max) {
	return key > min && key < max;
}
void del_range(map<Pair, Pair>& my_map, Pair& range_1, Pair& range_2) {
	auto it = my_map.begin();
	Pair p;
	while (it != my_map.end()) {
		p = it->first;
		if (!is_in_range(p, range_1, range_2)) {
			++it;
		}
		else {
			it = my_map.erase(it);
		}
	}
}
Pair min_pair(map<Pair, Pair>& my_map) {
	auto it = my_map.begin();
	Pair p;
	p = it->first;
	return p;
}
Pair max_pair(map<Pair, Pair>& my_map) {
	auto it = my_map.begin();
	Pair p;
	while (it != my_map.end()) {
		p = it->first;
		++it;
	}
	return p;
}
void sum(map<Pair, Pair>& my_map, Pair& key, Pair& val) {
	for (const auto& pair : my_map) {
		Pair tmp = pair.first;
		key = key + tmp;
		tmp = pair.second;
		val = val + tmp;
	}
}
map<Pair, Pair> add(map<Pair, Pair>& my_map, Pair& key, Pair& val) {
	map<Pair, Pair> p;
	for (const auto& pair : my_map) {
		Pair p1 = pair.first;
		Pair p2 = pair.second;
		p[p1 + key] = (p2 + val);
	}
	return p;
}
bool find(map<Pair, Pair>& my_map, Pair& key, Pair& val) {
	auto it = my_map.find(key);
	if (it != my_map.end()) {
		val = Pair(it->second);
		return 1;
	}
	else {
		return 0;
	}
}


int main() {
	system("chcp 1251");
	int n;
	do {
		cout << "������� ������ �������: " << endl;
		cin >> n;
	} while (n < 1);

	Pair sum1(0, 0), sum2(0, 0), sum_key(0, 0), sum_value(0, 0);

	map<Pair, Pair> m;
	fill_map(m, n);

	cout << "������������ �������: " << m << endl;

	sum(m, sum1, sum2);
	sum1 / m.size();
	sum2 / m.size();
	cout << "������� �������������� ������: " << sum1 << endl;
	cout << "������� �������������� ��������: " << sum2 << endl;
	
	m[sum1] = sum2;
	cout << "����� ���������� �������� ����������������: " << m << endl;

	Pair one_elem, two_elem;

	cout << "������� ��� ���� ������ ��� ��������: " << endl;
	cout << "������ ����: " << endl;
	cin >> one_elem;
	cout << "������ ����: " << endl;
	cin >> two_elem;
	
	if (one_elem > two_elem) {
		swap(one_elem, two_elem);
	}

	del_range(m, one_elem, two_elem);
	cout << "����� �������� ���������: " << m << endl;

	Pair max_elem = max_pair(m);
	Pair min_elem = min_pair(m);

	find(m, min_elem, sum1);
	find(m, max_elem, sum2);

	cout << "����������� ������� �� �����: " << min_elem << endl;
	cout << "����: " << min_elem << " ��������: " << sum1 << endl;
	cout << "������������ ������� �� �����: " << max_elem << endl;
	cout << "����: " << max_elem << " ��������: " << sum2 << endl;

	sum_key = min_elem + max_elem;
	sum_value = sum1 + sum2;
	cout << "����� ������������� � ������������ ���������: " << endl;
	cout << "����: " << sum_key << " ��������: " << sum_value << endl;

	m = add(m, sum_key, sum_value);
	cout << "����� ����������: " << endl;
	cout << m << endl;

	cout << "������� �������� ��� ������: " << endl;
	cin >> one_elem;

	if (find(m, one_elem, two_elem) == 1) {
		cout << "���� ������)" << endl;
		cout << "���� - " << one_elem << " ��������: " << two_elem << endl;
	}
	else {
		cout << "������� �� ������(" << endl;
	}
	return 0;
}
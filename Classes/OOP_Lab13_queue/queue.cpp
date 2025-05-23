#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <random>
#include "Pair.h"

using namespace std;

void random(Pair& p) {
	int x = rand() % 1000;
	double y = (rand() % 10000) * 0.01;
	p = Pair(x, y);
}

class greater_than_Pair {
public:
	bool operator()(Pair& p1, Pair& p2) {
		return p1 < p2;
	}
};
void generate_queue(priority_queue<Pair, vector<Pair>, greater_than_Pair>& my_queue, int q_size);
ostream& operator<<(ostream& stream, priority_queue < Pair, vector<Pair>, greater_than_Pair> my_queue);
Pair all_sum(priority_queue<Pair, vector<Pair>, greater_than_Pair> my_q);
void remove_from(priority_queue<Pair, vector<Pair>, greater_than_Pair>& my_q, Pair& range_1, Pair& range_2);
Pair max_pair(priority_queue<Pair, vector<Pair>, greater_than_Pair>my_q);
Pair min_pair(priority_queue<Pair, vector<Pair>, greater_than_Pair>my_q);
priority_queue<Pair, vector<Pair>, greater_than_Pair> add(priority_queue<Pair, vector<Pair>, greater_than_Pair>& my_q, Pair& p);
bool find(priority_queue<Pair, vector<Pair>, greater_than_Pair>my_q, int& x, Pair& p);

int main() {
	system("chcp 1251");
	srand(time(0));

	int n;
	do {
		cout << "������� ����� �������: " << endl;
		cin >> n;
	} while (n < 1);

	priority_queue<Pair, vector<Pair>, greater_than_Pair> first_queue;
	generate_queue(first_queue, n);
	cout << first_queue;
	Pair sum = all_sum(first_queue);
	sum.setFirst(sum.getFirst() / first_queue.size());
	sum.setSecond(sum.getSecond() *1000 / first_queue.size()*0.001);
	cout << "������� ��������������" << endl;

	first_queue.push(sum);
	cout << "����� ���������� ����. �������. : " << endl << first_queue << endl;
	Pair p_one, p_two;
	cout << "������� ���� ��� ��������� ��������: " << endl;
	cout << "������ ����: " << endl;
	cin >> p_one;
	cout << "������ ����: " << endl;
	cin >> p_two;

	if (p_one > p_two) {
		swap(p_one, p_two);
	}
	
	remove_from(first_queue, p_one, p_two);
	cout <<"����� ��������: \n"<< first_queue << endl;

	Pair max_p = max_pair(first_queue);
	Pair min_p = min_pair(first_queue);
	cout << "������������ ����: " << max_p << endl;
	cout << "����������� ����: " << min_p << endl;
	
	sum = max_p + min_p;
	cout << "����� ������������� � ������������: " << sum << endl;
	first_queue = add(first_queue, sum);
	cout << "����� ����������: \n" << first_queue;
	cout << "������� ���� ��� ������: " << endl;
	int p;
	cin >> p;
	if (find(first_queue, p, sum)) {
		cout << "������� ������ " <<sum<< endl;
	}
	else {
		cout << "������� �� ������" << endl;
	}
	return 0;
}

void generate_queue(priority_queue<Pair, vector<Pair>, greater_than_Pair>& my_queue, int q_size) {
	Pair q_w_e(0, 0);
	for (int i = 0; i < q_size; i++) {
		random(q_w_e);
		my_queue.push(q_w_e);
	}
}
ostream& operator<<(ostream& stream, priority_queue < Pair, vector<Pair>, greater_than_Pair> my_queue) {
	while (!my_queue.empty()) {
		Pair user = my_queue.top();
		cout << user << endl;
		my_queue.pop();
	}
	return stream;
}
Pair all_sum(priority_queue<Pair, vector<Pair>, greater_than_Pair> my_q) {
	Pair p(0, 0);
	while (!my_q.empty()) {
		Pair upp = my_q.top();
		p = p + upp;
		my_q.pop();
	}
	return p;
}
void remove_from(priority_queue<Pair, vector<Pair>, greater_than_Pair>& my_q, Pair& range_1, Pair& range_2) {
	priority_queue<Pair, vector<Pair>, greater_than_Pair> queue_1;
	while (!my_q.empty()) {
		Pair upp = my_q.top();
		if (!(upp > range_1 && upp < range_2)) {
			queue_1.push(upp);
		}
		my_q.pop();

	}
	my_q = queue_1;
}
Pair max_pair(priority_queue<Pair, vector<Pair>, greater_than_Pair>my_q) {
	Pair max_p = my_q.top();
	return max_p;
}
Pair min_pair(priority_queue<Pair, vector<Pair>, greater_than_Pair>my_q) {
	Pair min_p;
	while (!my_q.empty()) {
		min_p = my_q.top();
		my_q.pop();
	}
	return min_p;
}
priority_queue<Pair, vector<Pair>, greater_than_Pair> add(priority_queue<Pair, vector<Pair>, greater_than_Pair>& my_q, Pair& p) {
	priority_queue<Pair, vector<Pair>, greater_than_Pair> queue_1;
	Pair upp = my_q.top();
	while (!my_q.empty()) {
		upp = my_q.top();
		queue_1.push(upp + p);
		my_q.pop();
	}
	return queue_1;
}
bool find(priority_queue<Pair, vector<Pair>, greater_than_Pair>my_q, int& x, Pair& p) {
	bool f = 0;
	while (!my_q.empty()) {
		p = my_q.top();
		if (x == p.getFirst()) {
			f = 1;
		}
		my_q.pop();
	}
	return f;
}

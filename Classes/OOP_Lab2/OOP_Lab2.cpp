#include <iostream>
#include <string>
#include "money.h"
using namespace std;

Pay_Money make_pay();

int main() {
	system("chcp 1251");
	system("cls");
	Pay_Money p1;
	p1.print();
	Pay_Money p2("������� ������ ���������", 1000000, 645);
	p2.print();
	Pay_Money p3;
	p3.setName("���� ������ ������");
	p3.setSalary(345000);
	p3.setBonus(300);
	cout << "���: " << p3.getName() <<endl<< " �����: " << p3.getSalary() <<endl<< " ������: " << p3.getBonus() <<"%"<< endl;
	Pay_Money p4 = make_pay();
	p4.print();
}

Pay_Money make_pay() {
	string name;
	double salary;
	int bonus;
	cout << "������� ���: " << endl;
	getline(cin, name);
	cout << "������� �����: " << endl;
	cin >> salary;
	cout << "������� ������: " << endl;
	cin >> bonus;
	Pay_Money work(name, salary, bonus);
	return work;
}
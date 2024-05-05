#include <iostream>
#include <fstream>
#include "Pair.h"
#include "Pair.cpp"
using namespace std;

int main() {
	system("chcp 1251");
	int len = 0;
	do {
		cout << "������� �����: " << endl;
		cin >> len;
	} while (len <= 0);
	WriteFile(len);
	bool stop = 0;
	while (!stop) {
		cout << "\n";
		printf("1 - ����������� ����\n2 - ������� ��� ������ ������ ��������� �����\n3 - ��������� �� ���� ����� �����\n4 - �������� k ���\n5 - ������� ����\n6 - �����");

		int ch = 0;
		cin >> ch;
		Pair pair;
		switch (ch)
		{
		case 1:
			do {
				cout << "������� ���������� ���������: " << endl;
				cin >> len;
			} while (len <= 0);
			WriteFile(len);
			break;
		case 2:
			cout << "������� ���� ��� ���������: " << endl;
			cin >> pair;
			RemoveLess(pair);
			break;
		case 3:
			cout << "������� �����: " << endl;
			double n;
			cin >> n;
			Add(n);
			break;
		case 4:
			cout << "������� ������� � ���������� ���:" << endl;
			int pos;
			int k;
			cin >> pos >> k;
			AddPairs(pos, k);
			break;
		case 5:
			PrintFile();
			break;
		case 6:
			stop = 1;
			break;
		default:
			cout << "���������� �������� :(" << endl;
			break;
		}
	}
}
#include <iostream>
#include <fstream>
#include "Pair.h"
#include "Pair.cpp"
using namespace std;

int main() {
	system("chcp 1251");
	int len = 0;
	do {
		cout << "Введите длину: " << endl;
		cin >> len;
	} while (len <= 0);
	WriteFile(len);
	bool stop = 0;
	while (!stop) {
		cout << "\n";
		printf("1 - пересоздать файл\n2 - удалить все записи меньше заданного числа\n3 - прибавить ко всем парам число\n4 - Добавить k пар\n5 - Вывести файл\n6 - выход");

		int ch = 0;
		cin >> ch;
		Pair pair;
		switch (ch)
		{
		case 1:
			do {
				cout << "Введите количество элементво: " << endl;
				cin >> len;
			} while (len <= 0);
			WriteFile(len);
			break;
		case 2:
			cout << "Введите пару для сравнения: " << endl;
			cin >> pair;
			RemoveLess(pair);
			break;
		case 3:
			cout << "Введите число: " << endl;
			double n;
			cin >> n;
			Add(n);
			break;
		case 4:
			cout << "Введите позицию и количество пар:" << endl;
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
			cout << "Непонятная операция :(" << endl;
			break;
		}
	}
}
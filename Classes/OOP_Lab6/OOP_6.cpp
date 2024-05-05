#include <iostream>
#include "List.h"
using namespace std;

int main() {
	system("chcp 1251");
	system("cls");
	srand(time(0));
	List list1(10, 0);
	cout << list1 << endl;
	for (int i = 0; i < list1(); i++) {
		list1[i] = rand() % 50 - 25;
	}
	cout << list1 << endl;
	cout << *(list1.first()) << " " << *(list1.last()) << endl;

	List list2(list1);
	cout << list2 << endl;
	list2.push_back(100);
	list2.pop_front();
	cout << list2 << endl;

	for (Iterator iter = list1.first(); iter != list1.last() + 1; iter++) {
		cout << *iter << " ";
	}
	return 0;
}

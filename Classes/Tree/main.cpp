#include <iostream>
#include "tree.h"
using namespace std;


int main() {
	system("chcp 1251");
	int k;
	
	Tree<double>* CurTree = new Tree<double>(0);
	cout << "¬ведите количество значений бинарного дерева: " << endl;
	cin >> k;
	CurTree = CurTree->balanced(k);

	CurTree->print_vertical();
}
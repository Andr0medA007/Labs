#include <iostream>
#include "tree.h"
using namespace std;


int main() {
	Tree<int>* root1 = new Tree<int>(1);
	root1->insert_left(2);
	root1->insert_right(3);
	root1->get_left()->insert_left(4);
	root1->get_left()->insert_right(5);

	root1->PrintTreeVertical(3);
	root1->reverse_way(root1); cout << endl;
}
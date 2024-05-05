#include <iostream>
#include "Progress.h"
using namespace std;

int main()
{
	system("chcp 1251");
	Progression progress(5, 4);
	progress.setFirst(3);
	progress.setSecond(2);
	cout <<"результат выполнения: " << progress.element(3) << endl;
	return 0;
}	
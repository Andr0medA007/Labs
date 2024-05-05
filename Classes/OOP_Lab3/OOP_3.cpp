#include <iostream>
#include "Pair.h"
using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");
    Pair a(3, 8);
    Pair b(2, 4);
    cout <<"a: "<< a <<"b: " << b;
    cout <<"Разность двух чисел"<< a - b << endl;
    cout <<"Сложение с целочисленной константой "<<"9: "<< a + 9 << endl;
    cout << "Сложение с вещественной константой "<<"5.5: "<<a + 5.5 << endl;
    return 0;
}

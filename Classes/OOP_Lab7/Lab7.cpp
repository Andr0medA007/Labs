#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");
    
   
    List<int> IntList;
    cout << "Введите список целых чисел: " << endl;
    cin >> IntList;
    cout << "Список целых чисел: " << endl;
    cout << IntList << endl;
    cout << "Введите список дробных чисел: " << endl;
    List<double> DoubleList;
    cin >> DoubleList;
    cout << "Список дробных чисел: " << endl;
    cout << DoubleList << endl;


    List<Pair> pairList;
    cin >> pairList;
    cout << "Список пар чисел: " << endl;
    cout << pairList<< endl;

    IntList *= IntList;
    cout << IntList << endl;
    
    
    return 0;
}


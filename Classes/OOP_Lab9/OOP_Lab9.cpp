#include <iostream>
#include "Error.h"
#include "List.h"
using namespace std;


int main()
{
    system("chcp 1251");
    try { // Недопустимый размер списка
        List list(-1);
    }
    catch (Error& e) {
        e.what();
    }
    cout << endl;

    try { // Недопустимое обращение по индексу
        List list(10, 2);
        cout << list[11] << endl;
    }
    catch (Error& e) {
        e.what();
    }
    cout << endl;

}

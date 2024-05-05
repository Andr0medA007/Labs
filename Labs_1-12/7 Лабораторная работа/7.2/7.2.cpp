#include <iostream>
using namespace std;

template <typename Type>
Type func1(Type a, Type b) {
    return abs(a-b);
}

template <typename Type>
Type belong(Type x1, Type y1, Type x2, Type y2, Type x3, Type y3, Type xm, Type ym) {
    int a = (x1 - xm) * (y2 - y1) - (x2 - x1) * (y1 - ym);
    int b = (x2 - xm) * (y3 - y2) - (x3 - x2) * (y2 - ym);
    int c = (x3 - xm) * (y1 - y3) - (x1 - x3) * (y3 - ym);
    if ((a > 0 && b > 0 && c > 0) or (a < 0 && b < 0 && c < 0) or (a == 0 or b == 0 or c == 0)) {
        cout << "Принадлежит" << endl;
    }
    else {
        cout << "Не принадлежит" << endl;
    }
    return 0;
}
int i = 0;

bool cringe(int k,int x[], int y[], int n,...)
{//n - размерность массива, массивы x и y хранят координаты вершин многоугольника, dotx, doty - координаты точки
    bool b = false;
    int* f = &k+1;
    int* j = &k + 2;
    for (int i = 0; i < n - 1; i++)                 //луч направляем вдоль оси х
        if (*f < x[i] && *j<y[i] && *j>y[i + 1] || *f<x[i] && *j>y[i] && *j < y[i + 1]) b = !b;//если пересечет многоуолник нечетное число раз - тру
    if (*f < x[i] && *j<y[0] && *j>y[n - 1] || *f<x[i] && *j>y[0] && *j < y[n - 1]) b = !b;//пересечение с последним ребром
    if (b == 0) {
        cout << "Лежит вне" << endl;
    }
    else {
        cout << "Лежит внутри" << endl;
    }
    return b;
};

    

int main()
{
    setlocale(LC_ALL, "Ru");
    double a = 6.5, b = 10.2;
    cout << "Длина стороны: "<<func1(a, b) << endl;
    int x1 = 1, y1 = 1, x2 = 1, y2 = 5, x3 =5, y3 =5, x4 = 5, y4 = 1, xm = 2, ym = 2;
    belong(x1, y1, x2, y2, x3, y3, xm, ym);
    int x[4] = { 1,1,5,5 };
    int y[4] = { 1,5,5,1 };

    cringe(2, x, y, 4, 2, 2);// лежит вне 
}   

#include <iostream>
using namespace std;

static int Hanoisk(int n, int start, int tmp, int final) {
    if (n > 0) {
        Hanoisk(n - 1, start, tmp, final);
        cout << start << " =>" << tmp << endl;
        Hanoisk(n - 1, tmp, final,start);
    }
    return 0;
}


int main()
{
    setlocale(LC_ALL, "Ru");
    int n;
    cout << "Введите количество колец на башне: " << endl;
    cin >> n;
    Hanoisk(n, 1, 2, 3);
    return 0;
}

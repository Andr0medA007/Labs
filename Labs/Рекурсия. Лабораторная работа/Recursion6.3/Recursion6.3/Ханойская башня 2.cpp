#include <iostream>
using namespace std;

static int Hanoisk(int n, int start, int tmp, int final) {
    if (n == 1) {
        printf("Перенести диск номер 1 cо столбика %d на %d столбик\n", start, tmp);
    }
    else{
        Hanoisk(n - 1, start, tmp, final);
        printf("Перенести диск номер %d cо столбика %d на %d столбик\n", n, start, tmp);
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

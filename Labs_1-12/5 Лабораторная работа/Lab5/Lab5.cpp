#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");
	const int n = 5;
	int r = 0;
	int i = 0;
	srand(time(0));
	int a[100] = { 0 };
	int a1[n][n] = { 0 };
	//Генерация изначального массива//
	cout << "Изначальная матрица" << endl;
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 10 + 50;
		cout << a[i] << " ";
	}
	cout << endl;
	//Заполнение массива единицами//
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			a1[i][j] = 1;
		}
	}
	//Добавление в матрицу последнего числа//

	for (int i = 0; i < n; i++) {
		while (r < a[i] - (n - 1) ){
			r++;
		}
		a1[(n - 1)][i] = r;
		r = 0;
	}
	cout << endl;
	cout << "Финальная матрица" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a1[i][j] << " ";
		}
		cout << endl;
	}



}
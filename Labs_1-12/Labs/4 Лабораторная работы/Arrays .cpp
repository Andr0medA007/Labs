#include <iostream>
#include <stdlib.h>
using namespace std;

// Функция сортировки
static int Sort(int* a, int n) { 
	for (int i = n - 1; i > 0; i--) {
		for (int j = n - 1; j >= (n - i); j--) {
			if (a[j] > a[j - 1]) {
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
	}
	return 0;
}
//Функция создания кольца из массива, т.е. перестановка элементов
static int ring(int* a, int n, int k, int r) {
	for (int i = 0; i < k / 2; i++) {
		r = a[i];
		a[i] = a[k - i - 1];
		a[k - i - 1] = r;
	}
	for (int i = 0; i < (n - k) / 2; i++) {
		r = a[i + k];
		a[i + k] = a[n - i - 1];
		a[n - i - 1] = r;
	}
	return 0;
}
//Функция вывода массива
static int print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
int main() {
	setlocale(LC_ALL, "Ru");
	int n, r = 0, k;
	int a[100] = { 0 };
	cout << "Введите длину массива: " << endl;
	cin >> n;
	cout << "С какого элемента вывести массив ? " << endl;
	cin >> k;
	cout << "Изначальный массив" << endl;
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 101 - 50;
		cout << a[i] << " ";
	}
	ring(a, n, k, r);
	cout << endl;
	cout << "Кольцевой массив" << endl;
	print(a, n);
	cout << "Отсортированный массив" << endl;
	Sort(a, n);
	print(a, n);
	int i = 0;
	//Удаление нечётных чисел
	for (int i = 0; i < n - 1; i++) {
		if (abs(a[i]) % 2 == 1) {
			for (int j = i; j < n - 1; j++) {
				a[j] = a[j + 1];
				i--;
			}
			n--;
		}
	}
	cout << "Удалённые нечётные числа" << endl;
	print(a, n);
	ring(a, n, k, r);
	cout << "Массив, начиная с k-го элемента" << endl;
	print(a, n);
		return 0;
}

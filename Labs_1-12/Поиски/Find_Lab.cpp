#include <iostream>
#include <vector>
#include <string>
#include "Line_Search.h"
#include "Bin_Search.h"
#include "Substring_Search.h"
#include "Interpol_Search.h"
#include "KMP.h"
using namespace std;

static int n;
int n1;
const int MAXN = 25;
const int MAXM = 25;
wstring text1;
wstring pattern;
int	shift[MAXM];
int m;
template<typename T> T init_vector(vector<T>& vect);
template<typename T> T print_vector(vector<T>& vect);
void print_str(string text);
void prepare_shift();
int boyer_moore();

int main()
{	
	system("chcp 1251");
	system("cls");
	int k;
	printf("1: Поиск Линейный \n2: Бинарный поиск \n3: Интерполяционный поиск \n4 : Прямой Поиск подстроки в строке \n");
	printf("5 : Поиск Бойера-Мура\n6 : Поиск Кнута-Морриса-Пратта\n");
	cin >> k;
	switch (k) {
	case 1: {
		printf("Введите длину строки: \n");
		cin >> n;
		vector <char> vect(n);
		init_vector(vect);
		print_vector(vect);
		printf("Введите символ для поиска: \n");
		char r;
		cin >> r;
		cout << Line_Search(vect, r, n) << endl;
		break;
	}
	case 2: {
		printf("Введите длину строки: \n");
		cin >> n;
		vector <int> vect_int(n);
		init_vector(vect_int);
		printf("Введите символ для поиска: \n");
		int h;
		cin >> h;
		int res = Bin_Search(vect_int, h, n);
		if (res == -1) {
			printf("Элемент не найден\n");
		}
		else {
			printf("Элемент найден");
		}
		break;
	}
	case 3: {
		printf("Введите длину строки: \n");
		cin >> n;
		vector <int> vect_int(n);
		init_vector(vect_int);
		printf("Введите символ для поиска: \n");
		int h;
		cin >> h;
		int res = Interpol_Search(vect_int, h, n);
		if (res == -1) {
			printf("Элемент не найден\n");
		}
		else {
			printf("Элемент найден");
		}
		break;
	}
	case 4: {
		string text;
		getline(cin, text);
		cout << "Строка: " << endl;
		getline(cin, text);
		string substring;
		cout << "Подстрока: " << endl;
		getline(cin, substring);
		int res = Substring_Search(text, substring);
		if (res == -1) {
			printf("Элемент не найден\n");
		}
		else {
			printf("Номер первого элемента найденной строки: %d\n", res + 1);
		}
		break;
	}
	case 5: {
		cout << "Строка: " << endl;
		wcin >> text1;
		cout << "Подстрока: " << endl;
		wcin >> pattern;
		n1 = text1.length();
		m = pattern.length();
		prepare_shift();
		int res = boyer_moore();
		if (res == -1) {
			printf("Элемент не найден\n");
		}
		else {
			printf("Номер первого элемента найденной строки: %d\n", res + 1);
		}
		break;
	}
	case 6: {
		string text;
		getline(cin, text);
		cout << "Строка: " << endl;
		getline(cin, text);
		string substring;
		cout << "Подстрока: " << endl;
		getline(cin, substring);
		int res = SearchStrKMP(text, substring);
		cout << res;
		break;
	}
	}
	return 0;
}


template<typename T> T init_vector(vector<T>& vect){
	printf("Введите знаки для создания строки: \n");
	for (int i = 0; i < n; i++) {
		T r;
		cin >> r;
		vect[i] = r;
	}
	return 0;
}
template<typename T> T print_vector(vector<T>& vect) {
	for (int i = 0; i < n; i++) {
		cout << vect[i] << " ";
	}
	cout << endl;
	return 0;
}
void print_str(string text) {
	for (int i = 0; i < text.length(); i++) {
		cout << text[i];
	}
	cout << endl;
}

void prepare_shift() {
	for (int i = 0; i < MAXM; i++) {
		shift[i] = m;
	}
	for (int i = 0; i < m; i++) {
		shift[pattern[i]] = m - i - 1;
	}
}
int boyer_moore() {
	int i = 0;
	while (i <= n1 - m) {
		int j = m - 1;
		while (j >= 0 && text1[i + j] == pattern[j]) {
			j--;
		}
		if (j == -1) {
			return i;
		}
		i += shift[text1[i + j]];
	}
	return -1;
}

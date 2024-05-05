#include <iostream>
#include <fstream>
#include "Pair.h"
using namespace std;
static void WriteFile(int len) {
	fstream File("File.txt", ios::out | ios::trunc);
	if (!File) {
		cout << "Не получилось открыть файл :(" << endl;
		return;
	}
	for (int i = 0; i < len; i++) {
		Pair pair;
		cin >> pair;
		File << pair << "\n";
	}
	File.close();
}
static void PrintFile() {
	fstream File("File.txt", ios::in);

	if (!File) {
		cout << "Не удалось открыть файл :(" << "\n";
		return;
	}
	Pair pair;
	while (File >> pair) {
		cout << pair << "\n";
	}
}
static void Add(double n) {
	fstream File("File.txt", ios::in);
	if (!File) {
		cout << "Не удалось открыть файл :(" << "\n";
		return;
	}
	fstream tmp("tmp.txt", ios::out | ios::trunc);
	Pair buf;
	while (File >> buf) {
		buf += n;
		tmp << buf << endl;
	}
	File.close();
	tmp.close();
	remove("File.txt");
	rename("tmp.txt", "File.txt");
}
static void AddPairs(int pos, int n) {
	if (pos <= 0 || n <= 0) {
		cout << "Числа должны быть больше 1" << endl;
		return;
	}
	fstream File("File.txt", ios::in);
	if (!File) {
		cout << "Не удалось открыть файл :(" << "\n";
		return;
	}
	fstream tmp("tmp.txt", ios::out | ios::trunc);
	Pair buf;
	int cnt = 0;
	while (File >> buf) {
		cnt++;
		tmp << buf << endl;
		if (cnt == pos) {
			for (int i = 0; i < n; i++) {
				Pair new_pair;
				cin >> new_pair;
				tmp << new_pair << endl;
			}
		}
	}
	if (cnt < pos) {
		cout << "Слишком большая позиция" << endl;
	}
	File.close();
	tmp.close();
	remove("File.txt");
	rename("tmp.txt", "File.txt");
}
static void RemoveLess(Pair&p) {
	fstream File("File.txt", ios::in);
	if (!File) {
		cout << "Не удалось открыть файл :(" << "\n";
		return;
	}
	fstream tmp("tmp.txt", ios::out | ios::trunc);
	Pair buf;
	while (File >> buf){
		if (buf >= p) {
			tmp << buf << endl;
		}
	}
	File.close();
	tmp.close();
	remove("File.txt");
	rename("tmp.txt", "File.txt");
}
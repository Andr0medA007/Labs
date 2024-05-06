#pragma once
#include <string>
using namespace std;

int Substring_Search(string text, string substring) {
	int n = text.length();
	int m = substring.length();

	for (int i = 0; i <= n - m; i++) {
		bool f = 1;
		int j = 0;
		while (j < m && f) {
			f = (text[i + j] == substring[j]);
			j++;
		}
		if (f) {
			return i;
		}
	}
	return -1;
}
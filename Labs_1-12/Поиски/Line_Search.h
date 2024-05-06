#pragma once
#include <vector>
using namespace std;

int Line_Search(vector<char>& vect, char key,int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (vect[i] == key) {
			cnt++;
		}
	}
	return cnt;
}
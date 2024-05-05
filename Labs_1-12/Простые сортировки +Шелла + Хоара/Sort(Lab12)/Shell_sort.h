#pragma once
#include <vector>
using namespace std;

void Shell_sort(vector<int>& vect) {
	int end = vect.size();
	int step = end / 2;
	for (int step = end / 2; step > 0; step /= 2) {
		for (int i = step; i < end; i++) {
			for (int j = i - step; j >= 0 && vect[j]> vect[j + step]; j -= step) {
				int tmp = vect[j];
				vect[j] = vect[j + step];
				vect[j + step] = tmp;
			}
		}
	}
}
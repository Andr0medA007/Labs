#pragma once
#include <vector>
#include "QuickSort9.h"
using namespace std;

void Bucket_sort(vector<int>& vect) {
	int n = 25;
	if (vect.size() < 2) {
		return;
	}

	int mx = vect[0];
	int mn = vect[0];
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i] > mx) {
			mx = vect[i];
		}
		else if (vect[i] < mn) {
			mn = vect[i];
		}
	}

	int bucketsLenght = 5;
	vector<int>* buckets = new vector<int>[bucketsLenght] {};

	for (int i = 0; i < vect.size(); i++) {
		buckets[vect[i] / 10 - mn / 10].push_back(vect[i]);
	}

	for (int i = 0; i < bucketsLenght; i++) {
		QuickSort(buckets[i]);
	}

	int index = 0;
	for (int i = 0; i < bucketsLenght; i++) {
		for (int j = 0; j < buckets[i].size(); j++) {
			vect[index++] = buckets[i][j];
		}
	}

	delete[] buckets;
}
#pragma once
#include <vector>
using namespace std;

int Bin_Search(vector<int>& vect, int key, int n) {
	int leftIndex = 0;
	int rightIndex = n - 1;
	while (leftIndex <= rightIndex) {
		int mid = (leftIndex + rightIndex) / 2;
		if (vect[mid] == key) {
			return mid;
		}
		else {
			if (vect[mid] < key) {
				leftIndex = mid + 1;
			}
			else {
				rightIndex = mid - 1;
			}
		}
	}
	return -1;
}
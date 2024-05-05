#pragma once
#include <vector>
using namespace std;
void QuickSort(vector<int>& vect, int beginIndex, int pivotIndex) {
    if (beginIndex < pivotIndex) {
        int currentIndex = beginIndex;
        for (int i = currentIndex; i < pivotIndex; i++) {
            if (vect[i] < vect[pivotIndex]) {
                int tmp = vect[i];
                vect[i] = vect[currentIndex];
                vect[currentIndex] = tmp;
                currentIndex++;
            }
        }
        int tmp = vect[currentIndex];
        vect[currentIndex] = vect[pivotIndex];
        vect[pivotIndex] = tmp;
        QuickSort(vect, beginIndex, currentIndex - 1);
        QuickSort(vect, currentIndex + 1, pivotIndex);
    }
}
void QuickSort(vector<int>& vect) {
    if (vect.size() > 1) {
        QuickSort(vect, 0, vect.size() - 1);
    }
}
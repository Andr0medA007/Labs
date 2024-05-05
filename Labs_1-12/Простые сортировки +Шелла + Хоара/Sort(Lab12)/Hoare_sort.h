#pragma once
#include <vector>
using namespace std;
void Hoare_Sort(vector<int>& vect,int beginIndex, int endIndex){
    int i, j, pivot, tmp;
    i = beginIndex;
    j = endIndex;
    pivot = vect[(beginIndex + endIndex) / 2];
    do {
        while ((vect[i] < pivot) && (i < endIndex)) i++;
        while ((pivot<vect[j]) && (j > beginIndex)) j--;
        if (i <= j) {
            tmp = vect[i];
            vect[i] = vect[j];
            vect[j] = tmp;
            i++;
            j--;
        }

    } while (i <= j);
    if (beginIndex < j) Hoare_Sort(vect, beginIndex, j);
    if (i < endIndex) Hoare_Sort(vect, i, endIndex);
}
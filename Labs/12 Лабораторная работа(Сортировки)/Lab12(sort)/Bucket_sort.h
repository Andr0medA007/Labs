#pragma once
#include "Quick_Sort.h"

void Block_sort(int* arr, int n) {
	int max_value = arr[0];
	int min_value = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
		}
		if (arr[i] < min_value) {
			min_value = arr[i];
		}
	}
	int bucket_cnt = ((max_value-min_value)/n)+1;
	int** arr_buckets = new int* [bucket_cnt];
	for (int i = 0; i < bucket_cnt; i++) {
		arr_buckets[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		int bucket_index = ((arr[i] - min_value) / bucket_cnt);
		arr_buckets[bucket_index][i] = arr[i];
	}

	for (int i = 0; i < bucket_cnt; i++) {
		Quick_Sort(arr_buckets[i], 0,bucket_cnt);
	}
	int index = 0;
	for (int i = 0; i < bucket_cnt; i++) {
		for (int j = 0; j < n; j++) {
			if (arr_buckets[i][j] != 0) {
				arr[index++] = arr_buckets[i][j];
			}
		}
	}


}
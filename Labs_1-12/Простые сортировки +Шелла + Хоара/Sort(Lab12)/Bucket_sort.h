
#include "Quick_Sort.h"

void Block_sort(int* arr, int n) {
	float max_value = arr[0];
	float min_value = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
		}
		if (arr[i] < min_value) {
			min_value = arr[i];
		}
	}
	int bckt_count = max_value / 10 - min_value / 10 + 1;
	int** buckets = new int*[25];
	
	for (int i = 0; i < bckt_count; i++) {
		buckets[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		int bucket_index = (int)((arr[i] - min_value) / bckt_count);
		buckets[bucket_index][i] = arr[i];
	}
	for (int i = 0; i < bckt_count; i++) {
		for(int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (buckets[i][j] > buckets[i][k]) {
					int tmp = buckets[i][j];
					buckets[i][j] = buckets[i][k];
					buckets[i][k] = tmp;
				}
			}
		}
	}
	int index = 0;
	for (int i = 0; i < bckt_count; i++) {
		for (int j = 0; j < n; j++) {
			if (buckets[i][j] != 0) {
				arr[index++] = buckets[i][j];
			}
		}
	}
}
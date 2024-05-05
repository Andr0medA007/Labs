#pragma once

void count_sort(int* arr, int min, int max) {
	int i = min, j = 0;
	int len = 25;
	int* arr_cnt = new int[len];
	for (i; i <= max; i++) {
		arr_cnt[i] = 0;
	}
	for (i = 0; i < len; i++) {
		arr_cnt[arr[i]]++;
	}
    for (i = min; i <= max; i++) {

        while (arr_cnt[i] > 0) {

            arr[j++] = i;


            arr_cnt[i]--;
        }
    }
}
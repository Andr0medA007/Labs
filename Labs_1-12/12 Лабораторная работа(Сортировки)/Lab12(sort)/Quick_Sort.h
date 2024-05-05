#pragma once

void Quick_Sort(int* arr, int i_begin, int i_end) {
	if (i_begin < i_end) {
		int left = i_begin;
		int right = i_end;
		int middle = arr[(i_begin + i_end) / 2];
		do {
			while (arr[left] < middle) {
				left++;
			}
			while (arr[right] > middle) {
				right--;
			}
			if (left <= right) {
				int tmp = arr[left];
				arr[left] = arr[right];
				arr[right] = tmp;
				left++;
				right--;
			}
		} while (left < right);
		Quick_Sort(arr, i_begin, right);
		Quick_Sort(arr, left, i_end);
	}
}
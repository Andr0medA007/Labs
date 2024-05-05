#pragma once

void Merge(int arr[], int i_start, int i_end) {
    int i = i_start;
    int mid = i_start + (i_end - i_start) / 2;
    int j = mid + 1;
    int k = 0;
    int* arr1 = new int[i_end - i_start + 1];
    while (i <= mid && j <= i_end) {
        if (arr[i] < arr[j]) {
            arr1[k++] = arr[i++];
        }
        else {
            arr1[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        arr1[k++] = arr[i++];
    }
    while (j <= i_end) {
        arr1[k++] = arr[j++];
    }
    for (int i = i_start; i <= i_end; i++) {
        arr[i] = arr1[i - i_start];
    }
}
void Merge_sort(int* arr, int left, int right) {
    int tmp = 0;
    if (left < right) {
        int mid_i = (left + right) / 2;
        if (right - left == 1) {
            if (arr[left] > arr[right]) {
                tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
            }
        }
        if (right - left > 1) {

            Merge_sort(arr, left, mid_i);
            Merge_sort(arr, mid_i + 1, right);
            Merge(arr, left, right);
        }
    }
}
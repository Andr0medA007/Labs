#include <iostream>
#include "Merge_sort.h"
#include "Quick_Sort.h"
#include "count_sort.h"
#include "Bucket_sort.h"
using namespace std;

const int n=25;
const int l = 10;

void print(int* arr);
void init_arr(int* arr);
void init_arr_cnt(int* arr);

int main()
{
    system("chcp 1251");
    system("cls");
    srand(time(0));
    int* arr = new int[n];
    init_arr(arr);
    printf("Новый массив\n");
    print(arr);
    Merge_sort(arr,0,n-1);
    printf("Отсортированный массив(Метод слияния): \n");
    print(arr);
    printf("Новый массив\n");
    init_arr(arr);
    print(arr);
    Quick_Sort(arr, 0, n - 1);
    printf("Отсортированный массив(Быстрая сортировка): \n");
    print(arr);
    printf("Новый массив\n");
    init_arr_cnt(arr);
    print(arr);
    printf("Отсортированный массив(Сортировка пересчётом): \n");
    count_sort(arr,0,10);
    print(arr);
    printf("Новый массив\n");
    init_arr(arr);
    print(arr);
    Block_sort(arr, n);
    print(arr);


}

void init_arr(int* arr) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 - 50;
    }
}
void init_arr_cnt(int* arr) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 9+1;
    }
}
void print(int* arr) {
    cout << arr[0];
    for (int i = 1; i < n; i++) {
        cout << " " << arr[i];
    }
    cout << "\n";
}
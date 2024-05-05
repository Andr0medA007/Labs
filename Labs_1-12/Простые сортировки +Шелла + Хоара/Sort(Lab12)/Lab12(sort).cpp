#include <iostream>
#include <vector>
#include <chrono>
#include "Merge_sort.h"
#include "Quick_Sort.h"
#include "count_sort.h"
#include "Bucket_sort.h"
#include "Bucket_sort2.h"
#include "Shell_sort.h"
#include "Hoare_sort.h"

using namespace std;

const int n=25;

void print(int* arr);
void init_arr(int* arr);
void init_arr_cnt(int* arr);
void init_vector(vector<int>& vect);
void print_vector(vector<int>& vect);
void hends_arr_init(int* arr);

int main()
{
    system("chcp 1251");
    system("cls");
    srand(time(0));
    int* arr = new int[n];
    vector <int> vect(25);
    int k = 0;
    printf("Какую сортировку использовать: \n 1: Слиянием\n 2: Быстрая сортировка \n");
    printf(" 3: Сортировка пересчётом \n 4: Сортировка блоками \n 5: Сортировка Шелла \n 6: Сортировка Хоара \n");
    cin >> k;
    switch (k) {
    case 1: {
        auto start_time_recursive = chrono::steady_clock::now();
        init_arr(arr);
        printf("Новый массив\n");
        print(arr);
        Merge_sort(arr, 0, n - 1);
        printf("Отсортированный массив(Метод слияния): \n");
        print(arr);
        auto end_time_recursive = chrono::steady_clock::now();
        auto diff1 = end_time_recursive - start_time_recursive;
        cout << "Функция выполнена за " << chrono::duration <double, milli>(diff1).count() << " ms" << endl << endl;
        break; }
    case 2: {
        auto start_time_recursive = chrono::steady_clock::now();
        printf("Новый массив\n");
        init_arr(arr);
        print(arr);
        Quick_Sort(arr, 0, n - 1);
        printf("Отсортированный массив(Быстрая сортировка): \n");
        print(arr);
        auto end_time_recursive = chrono::steady_clock::now();
        auto diff1 = end_time_recursive - start_time_recursive;
        cout << "Функция выполнена за " << chrono::duration <double, milli>(diff1).count() << " ms" << endl << endl;
        break; }
    case 3: {
        auto start_time_recursive = chrono::steady_clock::now();
        printf("Новый массив\n");
        init_arr_cnt(arr);
        print(arr);
        printf("Отсортированный массив(Сортировка пересчётом): \n");
        count_sort(arr, 0, 10);
        print(arr);
        auto end_time_recursive = chrono::steady_clock::now();
        auto diff1 = end_time_recursive - start_time_recursive;
        cout << "Функция выполнена за " << chrono::duration <double, milli>(diff1).count() << " ms" << endl << endl;
        break;
    }
    case 4: {
        auto start_time_recursive = chrono::steady_clock::now();
        printf("Новый массив\n");
        init_vector(vect);
        print_vector(vect);
        printf("Отсортированный массив(Сортировка блоками): \n");
        Bucket_sort(vect);
        print_vector(vect);
        auto end_time_recursive = chrono::steady_clock::now();
        auto diff1 = end_time_recursive - start_time_recursive;
        cout << "Функция выполнена за " << chrono::duration <double, milli>(diff1).count() << " ms" << endl << endl;
        break;
    }
    case 5:{
        auto start_time_recursive = chrono::steady_clock::now();
        printf("Новый массив\n");
        init_vector(vect);
        print_vector(vect);
        printf("Отсортированный массив(Сортировка Шелла): \n");
        Shell_sort(vect);
        print_vector(vect);
        auto end_time_recursive = chrono::steady_clock::now();
        auto diff1 = end_time_recursive - start_time_recursive;
        cout << "Функция выполнена за " << chrono::duration <double, milli>(diff1).count() << " ms" << endl << endl;
        break;
    }
    case 6: {
        auto start_time_recursive = chrono::steady_clock::now();
        printf("Новый массив\n");
        init_vector(vect);
        print_vector(vect);
        printf("Отсортированный массив(Сортировка Хоара): \n");
        Hoare_Sort(vect, 0, n - 1);
        print_vector(vect);
        auto end_time_recursive = chrono::steady_clock::now();
        auto diff1 = end_time_recursive - start_time_recursive;
        cout << "Функция выполнена за " << chrono::duration <double, milli>(diff1).count() << " ms" << endl << endl;
        break;
    }
    }
}

/*
4
98
67
32
14
69
43
78
91
62
58
22
50
71
18
33
61
99
57
48
22
79
83
12
6
9
*/


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
void hends_arr_init(int* arr) {
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        arr[i] = t;
    }
}
void init_vector(vector<int>& vect) {
    for (int i = 0; i < n; i++)
        vect[i] = rand() % 50;
}
void print_vector(vector<int>& vect) {
    for (int i = 0; i < 25; i++) {
        cout << vect[i] << " ";
    }
    cout << endl;
}
void print(int* arr) {
    cout << arr[0];
    for (int i = 1; i < n; i++) {
        cout << " " << arr[i];
    }
    cout << "\n";
}
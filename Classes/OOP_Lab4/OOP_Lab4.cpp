#include <iostream>
#include "Person.h"
using namespace std;

template <class T>
int CounterAgeGreater(T* persons, int count, int age) {
    int cnt = 0;
    for (int i = 0; i < count; i++) {
        if ((persons + i)->getAge() > age) {
            cnt++;
        }
    }
    return cnt;
};

Person* persons;
Student* students;
int age;

int main()
{
    system("chcp 1251");
    system("cls");
    int N;
    int k;
    printf("Выберите пользователей для сравнения: \n1- Обычный человек\n2- Студент\n");
    cin >> k;
    switch (k) {
    case 1: {
        cout << "Введите кол-во простых людей: " << endl;
        cin >> N;
        persons = new Person[N];

        for (int i = 0; i < N; i++) {
            cin >> persons[i];
        }
        cout << "Введите возраст: " << endl;
        cin >> age;
        cout << "Людей старше чем введёный возраст: " << CounterAgeGreater(persons, N, age) << endl;
        delete[] persons;
        }
    case 2: {
        cout << "Введите кол-во студентов: " << endl;
        cin >> N;
        students = new Student[N];

        for (int i = 0; i < N; i++) {
            cin >> students[i];
        }
        cout << "Введите возраст: " << endl;
        cin >> age;
        cout << "Студентов старше чем введёный возраст: " << CounterAgeGreater(students, N, age) << endl;
        delete[] students;
    }
    }
    

    
}

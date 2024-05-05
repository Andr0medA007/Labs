#pragma once
#include <iostream>
#include <string>
#include "Object.h"
#include "Event.h"

using namespace std;

class Print : public Object {
protected:
	string author;
	string name;
public:
	Print() {};
	Print(string author, string name) {
		set_name(name);
		set_author(author);
	}
	virtual ~Print() {};
	string get_author() { return author; };
	string get_name() override { return name; };
	void set_author(string author) { author = author; };
	void set_name(string name) { name = name; };
	void show(bool no_pages = 0) override {
		if (no_pages) {
			cout << get_name();
			return;
		}
		cout << "Название: " << name << ", Автор: " << author;
	}
	void input() override {
		cout << "Введите название: " << endl;
		getline(cin, name);
		cout << "Введите автора: " << endl;
		getline(cin, author);
	}
	Print& operator =(Print& pr) {
		name = pr.name;
		author = pr.author;
		return *this;
	}
};
class Magazine : public Print {
private:
	int page_cnt = 0;
public:
	Magazine() :Print() {}
	Magazine(string name, string author, int pages) : Print(name, author) {
		set_pages(pages);
	}
	virtual ~Magazine(){}
	void set_pages(int pages) { page_cnt = pages; }
	int get_pages() { return page_cnt; }
	void show(bool no_pages = 0) {
		Print::show(no_pages);
		if (!no_pages) {
			cout << ", количество страниц: " << page_cnt << endl;
		}
	}
	void input() override {
		Print::input();
		cout << "Введите количество страниц: " << endl;
		cin >> page_cnt;
	}
	Magazine& operator =(Magazine& an_mag) {
		Print::operator=(an_mag);
		page_cnt = an_mag.page_cnt;
		return *this;
	}
};
class Vector {
protected:
	Object** elements;
	int lenght;
	int cur_lenght;
public:
	Vector() { elements = 0; cur_lenght = 0; lenght = 0; }
	Vector(int loc_lenght) {
		elements = new Object * [loc_lenght];
		lenght = loc_lenght;
		cur_lenght = 0;
	}
	virtual  ~Vector() {
		if (elements == 0) return;
		for (int i = 0; i < cur_lenght; i++) {
			delete elements[i];
		}
		delete[] elements;
		lenght = 0;
		cur_lenght = 0;
	}
	void New_create(int loc_lenght){
		if (elements != 0) {
			for (int i = 0; i < cur_lenght; i++) {
				delete elements[i];
			}
			delete[] elements;
		}
		lenght = loc_lenght;
		elements = new Object * [loc_lenght];
		cur_lenght = 0;
	}
	bool Try_to_add(Object* element) {
		if (cur_lenght >= lenght) {
			cout << "Ваша группа переполнена :(" << endl;
			return false;
		}

		elements[cur_lenght] = element;
		cur_lenght++;
		return true;
	}
	bool Try_to_remove(string name) {
		if (cur_lenght == 0) {
			cout << "Список пуст(" << endl;
			return false;
		}
		bool flag = 0;

		for (int i = 0; i < cur_lenght && flag; i++) {
			flag = elements[i]->get_name() == name;
			if (flag) {
				Object* tmp = elements[i];
				for (int j = i; j < cur_lenght - 1; j++) {
					elements[j] = elements[j + 1];
				delete tmp;

				cur_lenght--;
				}
			}
		}
		if (!flag) {
			cout << "Элемент не найден(" << endl;
		}
		return flag;
	}
	void print(bool no_pages) {
		if (cur_lenght == 0) {
			cout << "Нет данных для вывода" << endl;
			return;
		}
		elements[0]->show(no_pages);

		for (int i = 1; i < cur_lenght; i++) {
			cout << endl;
			elements[i]->show(no_pages);
		}
	}
};
class Dialog : public Vector {
protected: 
	bool is_over = 1;
public:
	Dialog() { is_over = 0; }
	~Dialog() {};

	void Execute() {
		printf("c - создать новую группу\na - добавить новый элемент\nd - удалить элемент\np - вывести группу\npn - Вывести только авторов\nq - выход ");
		
		Event Event;

		while (!is_over) {
			get_event(Event);
			handle_event(Event);
		}
	}
	void get_event(Event& Event) {
		char command;
		cout << "Ввод команды: " << endl;
		cin >> command;

		Event.What = info;
		switch (command) {
		case 'c':
			Event.Command = Create;
			break;
		case 'a':
			Event.Command = Add;
			break;
		case 'd':
			Event.Command = Del;
			break;
		case 'p':
			Event.Command = commandPrint;
			break;
		case 'pn':
			Event.Command = Print_without_pages;
			break;
		case 'q':
			Event.Command = quit;
			break;
		default:
			Event.Command = Nothing;
		}
	}
	void handle_event(Event& Event) {
		if (Event.What = Nothing) {
			cout << "Invalid Command" << endl;
			return;
		}
		string Name;
		switch (Event.Command) {
		case Create:
			int size;

			do {
				cout << "Введите размер группы: " << endl;
				cin >> size;
			} while (size <= 0);
			New_create(size);
			break;
		case Add:
			if (elements == 0) {
				cout << "Группа не создана, для начала создайте её" << endl;
				break;
			}
			int num;
			do {
				printf("Какой объект добавить: 1 - журнал, 2 - книга\n");
				cin >> num;
			} while (num != 1 && num != 2);
			cin.ignore();

			if (num == 1) {
				Print* print = new Print;
				print->input();

				Try_to_add(print);
			}
			else {
				Magazine* magazine = new Magazine;
				magazine->input();

				Try_to_add(magazine);
			}
			break;
		case Del:
			if (elements == 0) {
				cout << "Группа не создана, для начала создайте её" << endl;
				break;
			}
			cin.ignore();

			cout << "Введите имя для удаления" << endl;
			getline(cin, Name);
			Try_to_remove(Name);
			break;
		case commandPrint:
			print(0);
			cout << endl;
			break;
		case Print_without_pages:
			print(1);
			cout << endl;
			break;
		case quit:
			is_over = 1;
			break;
		default:
			break;
		}
		Event.What = Nothing;
	}
};
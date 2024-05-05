#pragma once
#include "Pair.h"
using namespace std;

template <class T>
struct Node {
	Node<T>* next_node = nullptr;
	Node<T>* prev_node = nullptr;
	T data;
};

template <class T>
class List {
private:
	int size;
	Node<T>* head;
	Node<T>* tail;
public:
	List() { head = nullptr, tail = nullptr, size = 0; };
	~List() {
		del();
	};
	template <class T>
	void push_back(T data) {
		Node<T>* new_node = new Node<T>;
		new_node->data = data;
		new_node->next_node = nullptr;
		if (this->head == nullptr) {
			this->head = new_node;
			this->tail = new_node;
		}
		else {
			tail->next_node = new_node;
			new_node->prev_node = tail;
			tail = new_node;
		}
		this->size++;
	}
	template <class T>
	void push_front(T data) {
		Node<T>* new_node = new Node<T>;
		new_node->data = data;
		if (this->head == nullptr) {
			this->head = new_node;
			this->tail = new_node;
			this->size++;
		}
		else {
			head->prev_node = new_node;
			new_node->next_node = head;
			head = new_node;
			this->size++;
		}
	}
	template <typename T>
	T pop_back() {
		int tmp;
		if (this->tail != nullptr) {
			Node<T>* current_node = this->tail;
			tail = current_node->prev_node;
			tmp = current_node->data;
			tail->next_node = nullptr;
			this->size--;
		}
		return tmp;
	}
	template <typename T>
	T pop_front() {
		int tmp;
		if (this->head != nullptr) {
			Node<T>* current_node = this->head;
			head = current_node->next_node;
			tmp = current_node->data;
			head->prev_node = nullptr;
			this->size--;
		}
		return tmp;
	}
	template <typename T>
	bool is_empty() const {
		return this->size == 0;
	}
	template <typename T>
	void operator() () {
		return this->size;
	}

	List& operator =(List& list) {
		cout << "Оператор присваивания" << endl;
		if (this != &list)
		{
			~List();
			Node<T>* current = list.head;
			while (current != nullptr)
			{
				push_back(current->data);
				current = current->next_node;
			}
		}

		return *this;
	}
	
	T& operator[](int index)
	{
		if (index >= size || index < 0)
		{
			cout << "Index out of range" << endl;
			del();
			exit(0);
		}

		Node<T>* current = head;

		for (int i = 0; i < index; i++)
			current = current->next_node;

		return current->data;
	}
	
	List& operator*=(List& morelist) {
		int tmp_size;
		if (morelist.size > size) tmp_size = size;
		else tmp_size = morelist.size;

		for (int i = 0; i < tmp_size; i++) {
			(*this)[i] *= morelist[i];
		}
		
		return *this;
	}
	template <class T>
	friend ostream& operator <<(ostream& stream, List<T>& list);
	template <class T>
	friend istream& operator >>(istream& stream, List<T>& list);
	void del() {
		while (head != nullptr) {
			Node<T>* tmp = head;
			head = head->next_node;
			delete tmp;
		}
		tail = nullptr;
		size = 0;
	}
};

template <class T>
ostream& operator <<(ostream& stream, List<T>& list) {
	stream << endl << "Вывод элементов списка..." << endl;
	if (list.size == 0) {
		stream << "Нулевая длина(" << endl;
	}
	else {
		Node<T>* current = list.head;
		stream << current->data;
		current = current->next_node;
		while (current != nullptr)
		{
			stream << " " << current->data;
			current = current->next_node;
		}
	}
	return stream;
}

template <class T>
istream& operator >>(istream& stream, List<T>& list) {
	cout << endl << "Ввод элементов списка..." << endl;
	int size;
	cout << "Введите размер: " << endl;
	stream >> size;
	for (int i = 0; i < size; i++) {
		T data;
		stream >> data;
		list.push_back(data);
	}
	return stream;
}










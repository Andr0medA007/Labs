#pragma once
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next_node;
	Node* prev_node;
};
class Iterator {
private:
	friend class List;
	Node* elem;
public:
	Iterator() {
		this->elem = nullptr;
	}
	Iterator(const Iterator& iter) {
		this->elem = iter.elem;
	}
	Iterator& operator =(const Iterator& iter) {
		this->elem = iter.elem;
		return *this;
	}
	bool operator ==(const Iterator& iter) {
		return this->elem == iter.elem;
	}
	bool operator !=(const Iterator& iter) {
		return this->elem != iter.elem;
	}
	Iterator& operator ++ (int) {
		this->elem = this->elem->next_node;
		return*this;
	}
	Iterator& operator -- () {
		this->elem = this->elem->prev_node;
		return*this;
	}
	Iterator& operator + (const int number) const {
		Iterator tmp(*this);
		for (int i = 0; i < number; i++) {
			tmp.elem = tmp.elem->next_node;
		}
		return tmp;
	}
	Iterator& operator - (const int number) const {
		Iterator tmp(*this);
		for (int i = 0; i < number; i++) {
			tmp.elem = tmp.elem->prev_node;
		}
		return tmp;
	}
	int& operator*() {
		return this->elem->data;
	}
};

class List {
private:
	int size;
	Node* head;
	Node* tail;
	Iterator begin;
	Iterator end;
public:
	List(int size, int data);
	List(const List& list);
	List(int size);
	~List();
	Iterator first();
	Iterator last();
	int front();
	int back();
	void push_back(int data);
	void push_front(int data);
	int pop_back();
	int pop_front();
	bool is_empty() const;
	int operator () ();
	List& operator= (const List& list);
	int& operator [] (int index);
	List operator* (List& list);
	friend ostream& operator << (ostream& out, const List& list);
	friend istream& operator >> (istream& in, const List& list);
};

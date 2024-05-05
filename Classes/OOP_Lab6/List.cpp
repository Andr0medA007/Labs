#pragma once
#include <iostream>
#include "List.h"
using namespace std;

List::List(int size, int data) {
	this->size = size;
	if (size > 0) {
		Node* node = new Node;
		node->data = data;
		this->head = node;
		this->tail = node;
		for (int i = 1; i < size; i++) {
			Node* newNode = new Node;
			newNode->data = data;
			tail->next_node = newNode;
			newNode->prev_node = tail;
			tail = newNode;
		}
		tail->next_node = nullptr;
	}
	else {
		this->head = nullptr;
		this->tail = nullptr;
	}
	this->begin.elem = this->head;
	this->end.elem = this->tail;
}
List::List(int size) {
	this->size = size;
	if (size > 0) {
		Node* node = new Node;
		this->head = node;
		this->tail = node;
		for (int i = 1; i < size; i++) {
			Node* newNode = new Node;
			tail->next_node = newNode;
			newNode->prev_node = tail;
			tail = newNode;
		}
		tail->next_node = nullptr;
	}
	else {
		this->head = nullptr;
		this->tail = nullptr;
	}
	this->begin.elem = this->head;
	this->end.elem = this->tail;
}
List::List(const List& list) {
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;

	Node* current_node = list.head;
	while (current_node != nullptr) {
		push_back(current_node->data);
		current_node = current_node->next_node;
	}
	this->begin.elem = this->head;
	this->end.elem = this->tail;
}
List::~List() {
	Node* current_node = head;
	while (current_node != nullptr) {
		Node* next_node = current_node->next_node;
		delete current_node;
		current_node = next_node;
	}
	head = nullptr;

}
void List::push_back(int data) {
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next_node = nullptr;
	if (this->head == nullptr) {
		this->head = new_node;
		this->tail = new_node;
		this->begin.elem = this->head;
		this->end.elem = this->tail;
	}
	else {
		tail->next_node = new_node;
		new_node->prev_node = tail;
		tail = new_node;
	}
	this->size++;
}
void List::push_front(int data) {
	Node* new_node = new Node;
	new_node->data = data;
	if (this->head == nullptr) {
		this->head = new_node;
		this->tail = new_node;
		this->size++;
		this->begin.elem = this->head;
		this->end.elem = this->tail;
	}
	else {
		head->prev_node = new_node;
		new_node->next_node = head;
		head = new_node;
		this->size++;
		this->begin.elem = this->head;
	}
}
Iterator List::first(){
	return this->begin;
}
Iterator List::last() {
	return this->end;
}
int List::front() {
	return this->head->data;
}
int List::back() {
	return this->tail->data;
}
int List::pop_back() {
	int tmp;
	if (this->tail != nullptr) {
		Node* current_node = this->tail;
		tail = current_node->prev_node;
		tmp = current_node->data;
		tail->next_node = nullptr;
		this->size--;
		this->end.elem = tail;
	}
	return tmp;
}
int List::pop_front() {
	int tmp;
	if (this->head != nullptr) {
		Node* current_node = this->head;
		head = current_node->next_node;
		tmp = current_node->data;
		head->prev_node = nullptr;
		this->size--;
		this->begin.elem = head;
	}
	return tmp;
}
bool List::is_empty() const {
	return this->size == 0;
}
List& List::operator =(const List& list) {
	cout << "Оператор присваивания" << endl;
	if (this == &list) {
		return *this;
	}
	while (head != nullptr) {
		Node* tmp = head;
		head = head->next_node;
		delete tmp;
	}
	size = 0;
	Node* current_node = list.head;
	while (current_node != nullptr) {
		push_back(current_node->data);
		current_node = current_node->next_node;
	}
	this->begin = list.begin;
	this->end = list.end;
	return *this;
}
int& List::operator[] (int index) {
	if (index < this->size && index >= 0) {
		Node* current_node = this->head;
		for (int i = 0; i != index; i++) {
			current_node = current_node->next_node;
		}
		return current_node->data;
	}
	else {
		cerr << "Индекс выходить за границы" << endl;
		exit(0);
	}
}
int List::operator() () {
	return this->size;
}
List List::operator*(List& list) {
	int tmp_size;
	if (this->size > list.size) tmp_size = list.size;
	else tmp_size = this->size;
	List tmp(tmp_size, 0);
	for (int i = 0; i < tmp_size; i++) {
		tmp[i] = (*this)[i] * list[i];
	}
	return tmp;
}
ostream& operator << (ostream& ostream, const List& list) {
	ostream << endl << "Вывод элементов списка..." << endl;
	Node* current_node = list.head;
	while (current_node != nullptr) {
		ostream << current_node->data << " ";
		current_node = current_node->next_node;
	}
	ostream << endl << "Завершение вывода элементов..." << endl;
	return ostream;
}
istream& operator >> (istream& in, const List& list) {
	cout <<endl<<  "Ввод элементов списка..." << endl;
	Node* current_node = list.head;
	while (current_node != nullptr) {
		in >> current_node->data;
		current_node = current_node->next_node;
	}
	cout<< endl << "Завершение ввода элементов..." << endl;
	return in;
}
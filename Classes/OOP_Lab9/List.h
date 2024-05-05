#pragma once
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next_node;
	Node* prev_node;
};

class List {
private:
	int size;
	Node* head;
	Node* tail;
public:
	List(int size, int data);
	List(const List& list);
	List(int size);
	~List();
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
	List operator +(List& list);
	friend ostream& operator << (ostream& out, const List& list);
	friend istream& operator >> (istream& in, const List& list);
};


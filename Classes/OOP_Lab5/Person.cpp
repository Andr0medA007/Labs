#pragma once
#include "Person.h"
using namespace std;

Person::Person() {
	name = "";
	age = 0;
}
Person::Person(const string& name, const int& age) {
	this->name = name;
	this->age = age;
}
Person::Person(const int& age, const string& name) {
	this->name = name;
	this->age = age;
}
Person::Person(const Person& p) {
	this->name = p.name;
	this->age = p.age;
}
Person::~Person() {}

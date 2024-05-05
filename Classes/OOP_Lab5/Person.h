#pragma once
#include <string>
#include <iostream>
#include "Object.h"
using namespace std;
class Person : public Object{
protected:
	string name;
	int age;
public:
	Person();
	Person(const string& name, const int& age);
	Person(const int& age, const string& name);
	Person(const Person& p);
	~Person();

	void setName(const string& name) { this->name = name; };
	void setAge(const int& age) {
		if (age < 0) {
			cout << "�������� �������" << endl;
		}
		this->age = age;
	}
	string getName() const { return this->name; };
	int getAge() const { return this->age; };
	Person& operator=(const Person& p) {
		this->name = p.name;
		this->age = p.age;
		return *this;
	}
	friend ostream& operator<<(ostream& out,const Person& p) {
		cout << "���: " << p.name;
		cout << "\n �������: " << p.age;
		cout << endl << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Person& p) {
		cout << "������� ���: " << endl;
		getline(in, p.name);
		cout << "\n������� �������: ";
		(in >> p.age).ignore();
		cout << endl << endl;
		return in;
	}
};
class Student : public Person
{
protected:
	int mark;
	string subject;
public:
	Student() {
		this->mark = 0;
		this->subject = "";
	}
	Student(const string& name, const int& age, const string& sub, const int& mark) : Person(age, name) {
		this->setMark(mark);
		this->setSubject(sub);
	}
	Student(const int& age, const string& name, const string& sub, const int& mark) : Student(name, age, sub, mark) {};
	void setMark(const int& mark) {
		if (mark <= 0 || mark >= 6) {
			cout << "�������� ������" << endl;
		}
	}
	void setSubject(const string& sub) { this->subject = sub; };
	int getMark() const { return this->mark; };
	string getSubject() const { return this->subject; };
	friend ostream& operator<<(ostream& stream, const Student& s) {
		const Person* ps = &s;
		stream << *ps << endl;
		stream << "�������: " << s.subject << endl;
		if (s.mark <= 5 || s.mark >= 2) {
			stream << "������: " << s.mark << endl;
			if (s.mark > 5 || s.mark < 2) {
				stream << "������������ ������" << endl;
			}
			if (s.mark == 5) {
				stream << "�������� ������" << endl;
			}
			if (s.mark == 4) {
				stream << "������� ������" << endl;
			}
			if (s.mark < 4) {
				stream << "�����" << endl;
			}
		}
		return stream;
	}
	friend istream& operator>>(istream& stream, Student& s) {
		string tmp;
		int m;
		Person* const ps = &s;
		stream >> *ps;
		cout << "�������: ";
		stream >> tmp;
		s.setSubject(tmp);
		cout << "������: ";
		stream >> m;
		s.setMark(m);
		cout << endl;
		return stream;
	}
};
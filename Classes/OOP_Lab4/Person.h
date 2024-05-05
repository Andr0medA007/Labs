#pragma once
#include <string>
#include <iostream>
using namespace std;
class Person {
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
			cout << "Неверный возраст" << endl;
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
	friend ostream& operator<<(ostream& stream, const Person& p) {
		stream << "Имя: " << p.name << endl;
		stream << "Возраст: " << p.age << endl;
		return stream;
	}
	friend istream& operator>>(istream& stream, Person& p) {
		string tmp;
		int a;
		cout << "Имя: ";
		stream >> tmp;
		p.setName(tmp);
		cout << "Возраст: ";
		stream >> a;
		p.setAge(a);
		cout << endl;
		return stream;
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
			cout << "Неверная оценка" << endl;
		}
	}
	void setSubject(const string& sub) { this->subject = sub; };
	int getMark() const { return this->mark; };
	string getSubject() const { return this->subject; };
	friend ostream& operator<<(ostream& stream, const Student& s) {
		const Person* ps = &s;
		stream << *ps << endl;
		stream << "Предмет: " << s.subject << endl;
		stream << "Оценка: " << s.mark << endl;
		return stream;
	}
	friend istream& operator>>(istream& stream, Student& s) {
		string tmp;
		int m;
		Person* const ps = &s;
		stream >> *ps;
		cout << "Предмет: ";
		stream >> tmp;
		s.setSubject(tmp);
		cout << "Оценка: ";
		stream >> m;
		s.setMark(m);
		cout << endl;
		return stream;
	}
};
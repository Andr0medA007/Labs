#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Object {
public:
	Object() {};
	virtual ~Object() {};
	virtual void show(bool no_pages) = 0;
	virtual void input() = 0;
	virtual string get_name() = 0;
};
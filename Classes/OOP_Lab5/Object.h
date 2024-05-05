#pragma once
class Object {
public:
	Object() {};
	virtual ~Object() {};
	virtual void output() = 0;
};
#pragma once

const int Nothing = 0;
const int info = 10;
const int Create = 1; //c
const int Add = 2; // a
const int Del = 3; // d
const int commandPrint = 4; // p
const int Print_without_pages = 5; // pn
const int quit = 6; // q

class Event {
public:
	int What;
	int Command;
};
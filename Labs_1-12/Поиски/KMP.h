#pragma once
#include <string>

using namespace std;

void prefix_func(string substr, int* table) {
	table[0] = 0;
	int l_index = 0;
	int r_index = 1;

	while (r_index < substr.size()) {
		if (substr[r_index] == substr[l_index]) {
			table[r_index] = l_index + 1;
			l_index++;
			r_index++;
		}
		else if (l_index == 0) {
			table[r_index] = 0;
			r_index++;
		}
		else {
			l_index = table[l_index - 1];
		}
	}
}

int SearchStrKMPD(string text, string substr) {
	int subSize = substr.size();
	int* table = new int[subSize] {};

	prefix_func(substr, table);

	bool isFind = false;
	int index = 0;
	int sub_index;

	while (index < text.size() - subSize + 1 && !isFind) {
		sub_index = 0;

		for (; sub_index < subSize &&
			text[index + sub_index] == substr[sub_index]; sub_index++);

		if (sub_index == subSize) {
			isFind = true;
		}
		else if (sub_index == 0) {
			index++;
		}
		else {
			if (table[sub_index - 1] != 0) {
				index += table[sub_index - 1];
			}
			else {
				index += sub_index;
			}
		}
	}

	if (isFind) {
		return index;
	}
	else {
		return -1;
	}

}
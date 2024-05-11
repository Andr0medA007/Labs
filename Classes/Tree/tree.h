#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


template <class T>
class Tree {
public:
	struct pos {
		int col; // x
		int str; // y
	};
	Tree(T value, Tree<T>*&parent){
		this->right = nullptr;
		this->left = nullptr;
		this->parent = parent;
		this->data = value;
	}
	Tree(T data) {
		this->data = data;
		left = right = parent = nullptr;
	}
	Tree() {
		left = right = parent = nullptr;
	}
	~Tree() {
		delete_left();
		delete_right();
	}
	void delete_left() {
		if (left != nullptr) {
			left->delete_left();
			left->delete_right();
			delete left;
		}
	}
	void delete_right() {
		if (right != nullptr) {
			right->delete_left();
			right->delete_right();
		}
	}
	T get_data(){
		return data;
	}
	Tree<T>* get_left() {
		return left;
	}
	Tree<T>* get_right() {
		return right;
	}
	Tree<T>* get_parent() {
		return parent;
	}
	Tree<T>* next() {
		Tree<T>* current = this;
		if (current->right != nullptr) {
			return current->right.find_min();
		}
		Tree<T>* tmp = current->parent;
		while (tmp != nullptr && current == tmp->right) {
			current = tmp;
			tmp = tmp->parent;
		}
		return tmp;
	}
	Tree<T>* prev() {
		if (left != nullptr) {
			Tree<T>* tmp = left;
			while (tmp->right != nullptr) {
				tmp = tmp->right;
			}
			return tmp;
		}
		else {
			Tree<T>* tmp = this;
			while (tmp->parent != nullptr && tmp->parent->left == tmp) {
				tmp = tmp->parent;
			}
			return tmp->parent;
		}
	}
	Tree<T>* find_min() {
		Tree<T>* min_node = this;
		while (min_node->left != nullptr) {
			min_node = min_node->left;
		}
		return min_node;
	}
	void insert_right(T data) {
		Tree<T>* new_node = new Tree(data);
		if (this->right != nullptr) {
			this->right->parent = new_node;
			new_node->right = this->right;
		}
		this->right = new_node;
		new_node->parent = this;
	}
	void insert_left(T data) {
		left = new Tree<T>(data);
		left->parent = this;
	}
	void insert(T data) {
		Tree<T>* current = this;
		while (current != nullptr) {
			if (data > current->data) {
				if (current->right != nullptr) {
					current = current->right;
				}
				else {
					current->insert_right(data);
					return;
				}
			}
			else if (data < current->data) {
				if (current->left != nullptr) {
					current = current->left;
				}
				else {
					current->insert_left(data);
					return;
				}
			}
			else {
				return;
			}
		}
	}
	void add_left(Tree<T>* tmp) { left = tmp; }; //установка левой ветви
	void add_right(Tree<T>* tmp) { right = tmp; }; //установка правой ветви
	void direct_way(Tree<T>* current_tree) {
		if (current_tree == nullptr) {
			return;
		}
		else {
			cout << current_tree->get_data() << " ";
			direct_way(current_tree->get_left());
			direct_way(current_tree->get_right());
		}
	}
	void symmetric_way(Tree<T>* current_tree) {
		if (current_tree != nullptr) {
			symmetric_way(current_tree->left);
			cout << current_tree->data << " ";
			symmetric_way(current_tree->right);
		}
	}
	void reverse_way(Tree<T>* current_tree) {
		if (current_tree != nullptr) {
			reverse_way(current_tree->left);
			reverse_way(current_tree->right);
			cout << current_tree->data << " ";
		}
	}
	void print_horizontal(int depth = 0, char br = ' ') {
		if (right != nullptr) {
			right->print_horizontal(depth + 1, '/');
		}
		for (int i = 0; i < depth; ++i) {
			cout << "   ";
		}
		cout << br << "--" << data << endl;
		if (left != nullptr) {
			left->print_horizontal(depth + 1, '\\');
		}
	}
	int get_height() {
		int h1 = 0, h2 = 0, hadd = 0;
		if (this == NULL) return 0;
		if (this->left != NULL) h1 = this->left->get_height();
		if (this->right != NULL) h2 = this->right->get_height();
		if (h1 >= h2) return h1 + 1;
		else return h2 + 1;
	}
	int get_level(Tree<T>*node) {
		vector<Tree<T>*> vec;
		Tree<T>* p = this;
		vec.push_back(p);
		for (int i = 0; i < this->get_nodes_cnt(); i++) {
			if (vec.at(i)->left != NULL) {
				vec.push_back(vec.at(i)->left);
			}
			if (vec.at(i)->right != NULL) {
				vec.push_back(vec.at(i)->right);
			}
		}
		for (int i = 0; i < vec.size(); i++) {
			cout << vec.at(i)->get_data() << " ";
		}
		cout << endl;

	}
	int get_nodes_cnt() {
		if (this == NULL) return 0;
		if ((this->left == NULL) && (this->right == NULL)) return 1;
		int l = 0;
		int r = 0;
		if (this->left != NULL) l = this->left->get_nodes_cnt();
		if (this->right != NULL) r = this->right->get_nodes_cnt();
		return (l + r + 1);
	}
	Tree<T>* copy() {
		Tree<T>* new_tree = new Tree<T>(data);
		if (left != nullptr) {
			new_tree->left = left->copy();
			new_tree->left->parent = new_tree;
		}
		if (right != nullptr) {
			new_tree->right = right->copy();
			new_tree->right->parent = new_tree;
		}
		return new_tree;
	}
	Tree<T>* replaceNullToFull() {
		Tree<T>* node = this->copy();
		int h = node->get_height();
		node = more_replace(node, h);
		return node;
	}
	Tree<T>* more_replace(Tree<T>* node, int h) {
		int curLvl = get_level(node);
		if ((node->get_left() == NULL) && (curLvl != h - 1)) {
			node->insert_left(NULL);
		}
		if ((node->get_right() == NULL) && (curLvl != h - 1)) {
			node->insert_right(NULL);
		}
		if (node->get_left() != NULL) node.add_left(more_replace(node->get_left(), h));
		if (node->get_right() != NULL) node.add_right(more_replace(node->get_right(), h));
		return node;
	}
	void road(Tree<T>* node) {
		ofstream f("File.txt");
		int cnt = node->get_nodes_cnt();
		queue<Tree<T>*> q;
		q.push(node);
		
		while (!q.empty()) {
			Tree<T>* tmp = q.front();
			q.pop;
			f << tmp->data << endl;
			if (tmp.left) {
				q.push(tmp->left);
			}
			if (tmp.right) {
				q.push(tmp->right);
			}
		}
		f.close();
	}
	int get_pos(int index, int width, int CurLvl, int MaxLvl) {
		int x1 = 0;
		int x2 = pow(2, CurLvl) - 1;
		int y1 = width / pow(2, CurLvl + 1);
		int y2 = width - pow(2, MaxLvl - CurLvl);
		if (x1 == x2) return y1;

		double k = (y2 - y1) / (x2 - x1);
		double m = -x1 * k + y1;
		int y = (int)(k * index + m);
		return y;
	}
	void PrintTreeVertical(int k) {
		int height = this->get_height();

		int maxLeafs = pow(2, height - 1);

		int width = 2 * maxLeafs - 1;
		int CurLvl = 0;
		int index = 0;

		int spaces = get_pos(index, width, CurLvl, height - 1);
		pos node;
		vector<Tree<T>*> vec;
		vector<pos> VecI;
		Tree<T>* t = this->copy();
		t = t->replaceNullToFull();
		Tree<T>* p = t;
		vec.push_back(p);
		node.col = spaces;
		node.str = CurLvl;
		VecI.push_back(node);

		for (int i = 0; i < t->get_nodes_cnt(); i++) {
			if (pow(2, CurLvl) <= index + 1) {
				index = 0;
				CurLvl++;
			}
			if (vec.at(i)->left != NULL) {
				vec.push_back(vec.at(i)->left);
				spaces = get_pos(index, width, CurLvl, height - 1);
				node.col = spaces;
				node.str = CurLvl;
				VecI.push_back(node);
				index++;
			}
			if (vec.at(i)->right != NULL) {
				vec.push_back(vec.at(i)->right);
				spaces = get_pos(index, width, CurLvl, height - 1);
				node.col = spaces;
				node.str = CurLvl;
				VecI.push_back(node);
				index++;
			}
		}
		for (int i = vec.size() - 1; i >= 0; i--) {
			if (i != 0) {
				if (VecI.at(i - 1).str == VecI.at(i).str) VecI.at(i).col = VecI.at(i).col - VecI.at(i-1).col-1;
			}
		}
		int flag = 0;
		for (int i = 0; i < vec.size(); i++) {
			node = VecI.at(i);
			CurLvl = node.str;

			if (flag < CurLvl) {
				flag = CurLvl;
				cout << endl;
			}
			spaces = node.col;
			int Cur_Spaces = k * spaces;
			for (int j = 0; j < Cur_Spaces; j++) cout << " ";
			cout << vec.at(i)->get_data();
			for (int j = 0; j < k; j++) cout << " ";
		}
		cout << endl;
	}
	void print_vertical(int depth = 0) {
		if (right != nullptr) {
			right.print_vertical(depth + 1);
		}
		for (int i = 0; i < depth; ++i) {
			cout << "   ";
		}
		cout << data << endl;
		if (left != nullptr) {
			left.print_vertical(depth + 1);
		}
	}
	Tree<T>* balanced(int cnt) {
		if (cnt <= 0) {
			return nullptr;
		}
		T data;
		cout << "Введите данные для balanced дерева: " << endl;
		cin >> data;
		Tree<T>* tmp = new Tree<T>(data);
		tmp->add_left(balanced(cnt / 2));
		tmp->add_right(balanced(cnt-cnt / 2-1));
		return tmp;
	}



private:
	Tree<T>* left;
	Tree<T>* right;
	Tree<T>* parent;
	T data;
};
#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


template <class T>
class Tree {
private:
	Tree<T>* left;
	Tree<T>* right;
	Tree<T>* parent;
	T data;

public:
	struct pos {
		int col; // x
		int str; // y
	};
	Tree(T value, Tree<T>*& parent) {
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
			delete right;
		}
	}
	T get_data() {
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
	int obh(Tree<T>* node) {
		ofstream f("File.txt");
		int cnt_of_nodes = node->get_nodes_cnt();
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
		return cnt_of_nodes;
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
	
	Tree<T>* balanced(int cnt) {
		if (cnt <= 0) {
			return nullptr;
		}
		T data;
		cout << "Введите данные для balanced дерева: " << endl;
		cin >> data;
		Tree<T>* tmp = new Tree<T>(data);
		tmp->add_left(balanced(cnt / 2));
		tmp->add_right(balanced(cnt - cnt / 2 - 1));
		return tmp;
	}
	void Fill_empty(int i) {
		if (i == 1) {
			return;
		}
		if (!this->right) {
			this->insert_right(-1);
		}
		if (!this->left) {
			this->insert_left(-1);
		}
		this->right->Fill_empty(i - 1);
		this->left->Fill_empty(i - 1);
	}
	void print_vertical() {
		Tree<T>* tree1 = this->copy();
		int height = tree1->get_height();
		tree1->Fill_empty(height);
		int node_cnt = obh(tree1);
		vector<T*> mas = vector(node_cnt);
		int cnt = 0;
		vector<int*>spaces = new vector(height);
		spaces[0] = 0;
		for (int i = 1; i < height; i++) {
			spaces[i] = spaces[i - 1] * 2 + 1;
		}
		if (height == 1) {
			cout << mas[0] << endl;
		}
		else {
			for (int i = 0, l = height - 1; i < height - 1; i++, l--) {
				for (int j = 0, k = 0; j < pow(2, i); j++, k++) {
					if (k == 0) {
						for (int m = 0; m < spaces[l]; m++) {
							cout << ' ';
						}
					}
					else {
						for (int m = 0; m < spaces[l + 1]; m++) {
							cout << ' ';
						}
					}
					if (mas[count] != -1)
						cout  << mas[count++];
					else
						cout  << ' ';
				}
				cout << endl;
			}

			vector<T*> last_str = new vector<T>(pow(2, height - 1));
			for (int i = 0; i < pow(2, height - 1); i++) {
				last_str[i] = 9999999129;
			}

			int sch1 = 0;
			int sch2 = spaces[height - 2] + 1;

			for (int i = count; i < node_cnt; i += 2) {
				if (i <= node_cnt - 1) {
					last_str[sch1] = mas[i];
					sch1 += 2;
				}
				if (i + 1 <= node_cnt - 1) {
					last_str[sch2] = mas[i + 1];
					sch2 += 2;
				}
				if (sch1 >= pow(2, height - 1) || sch2 >= pow(2, height - 1)) {
					sch1 = 1;
					sch2 = spaces[height - 2] + 2;
				}
			}

			for (int i = 0; i < pow(2, height - 1); i++)
				if (last_str[i] != 9999999129) last_str[i] = mas[count++];

			for (int i = 0; i < pow(2, height - 1); i++)
				if (last_str[i] != 9999999129 && last_str[i] != -1) cout << last_str[i] << ' ';
				else cout << ' ' << ' ';

			cout << endl;
		}
	}
	
};
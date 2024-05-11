#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Graph {
private:
	vector<T> List_of_Vertex;
	vector<vector<T>> Adjacency_Matrix;
	int size_of_Matrix;
public:	
	Graph(const int& size) {
		this->size_of_Matrix = size;
		this->Adjacency_Matrix = vector<vector<T>>(size, vector<T>(size));
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				this->Adjacency_Matrix[i][j] = 0;
			}
		}
	}
	bool is_full() {
		return this->List_of_Vertex.size() == this->size_of_Matrix;
	}
	bool is_empty() {
		return this->List_of_Vertex.size() == 0;
	}
	void insert_vertex(const T& vertex) {
		if (this->is_full) {
			cout << "Граф заполнен, нельзя добавить новую вершину" << endl;
			return;
		}
		else {
			this->List_of_Vertex.push_back(vertex);
		}
	}
	int get_position(const T& vertex) {
		for (int i = 0; i < List_of_Vertex.size(), i++) {
			if (this->List_of_Vertex[i] == vertex) {
				return i;
			}
		}
		return -1;
	}
	int get_count_of_vertex() {
		return this->List_of_Vertex.size();
}
	int get_vertex_weight(const T& vertex1, const T& vertex2) {
		if (this->is_empty()) {
			return 0;
		}
		int position_vertex1 = this->get_position(v1);
		int position_vertex2 = this->get_position(v2);

		if (position_vertex1 == -1 || position_vertex2 == -1) {
			cout << "Нет связи между вершинами" << endl;
			return 0;
		}
		return this->Adjacency_Matrix[vertex1][vertex2];
	}
	vector<T> get_neighbours(const T& vertex) {
		vector<T> List_of_Neighbours;
		int pos = this->get_position(vertex);
		if (pos != -1) {
			for (int i = 0; i < this->List_of_Vertex.size(); i++) {
				if (this->Adjacency_Matrix[pos][i] != 0) {
					List_of_Neighbours.push_back(this->List_of_Vertex[i]);
				}
			}
		}
		return List_of_Neighbours;
	}

};

#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

template <class T>
class Graph {
private:
	vector<T> List_of_Vertex;
	vector<vector<T>> Adjacency_Matrix;
	queue<T> queue_of_vertex;
	int size_of_Matrix;
public:	
	Graph() {
		this->size_of_Matrix = 0;

	}
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
		if (this->is_full()) {
			cout << "Граф заполнен, нельзя добавить новую вершину" << endl;
			return;
		}
		else {
			this->List_of_Vertex.push_back(vertex);
		}
	}
	int get_position(const T& vertex) {
		for (int i = 0; i < List_of_Vertex.size(); i++) {
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
		int position_vertex1 = this->get_position(vertex1);
		int position_vertex2 = this->get_position(vertex2);

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
	void insert_forward_edge(const T& vertex1, const T& vertex2, int weight = 1) {
		if (get_position(vertex1) != (-1) && this->get_position(vertex2) != (-1)) {
			int vertexPosition1 = get_position(vertex1);
			int vertexPosition2 = get_position(vertex2);

			if (this->Adjacency_Matrix[vertexPosition1][vertexPosition2] != 0 && this->Adjacency_Matrix[vertexPosition2][vertexPosition1] != 0) {
				cout << "Ребро уже существует" << endl;
				return;
			}
			else {
				this->Adjacency_Matrix[vertexPosition1][vertexPosition2] = weight;
			}
		}
		else {
			cout << "Невозможно создать ребро" << endl;
			return;
		}
	}
	void insert_unforward_edge(const T& vertex1, const T& vertex2, int weight = 1) {
		if (get_position(vertex1) != (-1) && this->get_position(vertex2) != (-1)) {
			int vertexPosition1 = get_position(vertex1);
			int vertexPosition2 = get_position(vertex2);

			if (this->Adjacency_Matrix[vertexPosition1][vertexPosition2] != 0 && this->Adjacency_Matrix[vertexPosition2][vertexPosition1] != 0) {
				cout << "Ребро уже существует" << endl;
				return;
			}
			else {
				this->Adjacency_Matrix[vertexPosition1][vertexPosition2] = weight;
				this->Adjacency_Matrix[vertexPosition2][vertexPosition1] = weight;
			}
		}
		else {
			cout << "Невозможно создать ребро" << endl;
			return;
		}
	}
	void print_matrix() {
		if (!this->is_empty()) {
			cout << "Матрица смежности графа: " << endl;
			cout << "  ";
			for (int i = 0; i < List_of_Vertex.size(); i++) {
				cout<< " "<< List_of_Vertex[i] << " ";
			}
			cout << endl;

			for (int i = 0; i < this->List_of_Vertex.size(); i++) {
				cout << this->List_of_Vertex[i] << " ";
				for (int j = 0; j < List_of_Vertex.size(); j++) {
					cout << " " << this->Adjacency_Matrix[i][j] << " ";
				}
				cout << endl;
			}
		}
		else {
			cout << " Граф пуст" << endl;
		}
	}
	int get_forward_edges_cnt() {
		int cnt = 0;
		if (!this->is_empty()) {
			for (int i = 0; i < this->List_of_Vertex.size(); i++) {
				for (int j = 0; j < this->List_of_Vertex.size(); i++) {
					if (this->Adjacency_Matrix[i][j] != 0) {
						cnt++;
					}
				}
			}
		}
		return cnt;
	}
	int get_unforward_edges_cnt() {
		int cnt = 0;
		if (!this->is_empty()) {
			for (int i = 0; i < this->List_of_Vertex.size(); i++) {
				for (int j = 0; j < this->List_of_Vertex.size(); i++) {
					if (this->Adjacency_Matrix[i][j] != 0) {
						cnt++;
					}
				}
			}
		}
		return cnt/2;
	}
	void dfs(T& start_vertex, bool* visited_Vertexes) {
		cout << "Вершина " << start_vertex << " доступна для прохождения" << endl;
		visited_Vertexes[this->get_position(start_vertex)] = 1;
		vector<T> neighbors = this->get_neighbours(start_vertex);
		for (int i = 0; i < neighbors.size(); i++) {
			if (!visited_Vertexes[this->get_position(neighbors[i])]) {
				this->dfs(neighbors[i], visited_Vertexes);
			}
		}
	}
	void bfs(T& start_vertex, bool* visited_vertexes) {
		if (visited_vertexes[this->get_position(start_vertex)] == 0) {
			this->queue_of_vertex.push(start_vertex);
			cout << "Вершина " <<start_vertex<< " доступна для прохождения" << endl;
			visited_vertexes[this->get_position(start_vertex)] = 1;
		}
		vector<T> neighbors = this->get_neighbours(start_vertex);
		this->queue_of_vertex.pop();
		for (int i = 0; i < neighbors.size(); i++) {
			if (!visited_vertexes[this->get_position(neighbors[i])]) {
				this->queue_of_vertex.push(neighbors[i]);

				visited_vertexes[this->get_position(neighbors[i])] = 1;
				cout << "Вершина " << neighbors[i] << " доступна для прохождения" << endl;
			}
		}
		if (this->queue_of_vertex.empty()) {
			return;
		}
		bfs(queue_of_vertex.front(), visited_vertexes);
	}
	void Pink_Floyd() {
		int Vertex_cnt, Edge_cnt;
		cout << "Количество вершин: " << endl;
		cin >> Vertex_cnt;
		cout << "Количество граней: " << endl;
		cin>> Edge_cnt;
		vector<vector<int>> dist(Vertex_cnt, vector<int>(Vertex_cnt, INF));
		for (int v = 0; v < Vertex_cnt; v++) {
			dist[v][v] = 0;
		}
		for (int i = 0; i < Edge_cnt; i++) {
			int a, b, weight;
			cout << "Введите начальную точку: " << endl;
			cin >> a;
			cout << "Введите вторую вершину: " << endl;
			cin >> b;
			cout << "Введите вес грани: " << endl;
			cin >> weight;
			a--;
			b--;

			dist[a][b] = min(dist[a][b], weight);
		}
		for (int v = 0; v < Vertex_cnt; v++) {
			for (int a = 0; a < Vertex_cnt; a++) {
				for (int b = 0; b < Vertex_cnt; b++) {
					if (dist[a][v] != INF && dist[v][b] != INF && dist[a][b] > dist[a][v] + dist[v][b]) {
						dist[a][b] = dist[a][v] + dist[v][b];
					}
				}
			}
		}
		for (int a = 0; a < Vertex_cnt; a++) {
			for (int b = 0; b < Vertex_cnt; b++) {
				cout << dist[a][b] << " ";
			}
			cout << "\n";
		}
	}
};

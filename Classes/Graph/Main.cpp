#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "Graph.h"
using namespace std;


int main()
{
    system("chcp 1251");
    bool* visitedVertexes = new bool[20];
    fill(visitedVertexes, visitedVertexes + 20, 0);

    int k = 0;
    cout << "Количество вершин графа: " << endl; cin >> k;
    Graph<int> graph(k);
    int Edges_cnt, vertex, sourceVertex, targetVertex;
    cout << "Количество рёбер графа: " << endl; cin >> Edges_cnt;
    for (int i = 0; i < k; i++) {
        cout << "Вершина: " << endl;
        cin >> vertex;
        graph.insert_vertex(vertex);
    }
    for (int i = 0; i < Edges_cnt; i++) {
        cout << "Исходная вершина: " << endl; 
        cin >> sourceVertex;
        cout << "Конечная вершина: " << endl;
        cin >> targetVertex;

        int* targetVertexPointer = &targetVertex;
        graph.insert_forward_edge(sourceVertex, targetVertex);
    }
    graph.print_matrix();
    cout << "С какой вершины начинать обход: " << endl;
    cin >> vertex;
    graph.bfs(vertex, visitedVertexes);

    graph.Pink_Floyd();


    return 0;
}
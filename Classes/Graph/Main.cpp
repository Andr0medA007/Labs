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
    cout << "���������� ������ �����: " << endl; cin >> k;
    Graph<int> graph(k);
    int Edges_cnt, vertex, sourceVertex, targetVertex;
    cout << "���������� ���� �����: " << endl; cin >> Edges_cnt;
    for (int i = 0; i < k; i++) {
        cout << "�������: " << endl;
        cin >> vertex;
        graph.insert_vertex(vertex);
    }
    for (int i = 0; i < Edges_cnt; i++) {
        cout << "�������� �������: " << endl; 
        cin >> sourceVertex;
        cout << "�������� �������: " << endl;
        cin >> targetVertex;

        int* targetVertexPointer = &targetVertex;
        graph.insert_forward_edge(sourceVertex, targetVertex);
    }
    graph.print_matrix();
    cout << "� ����� ������� �������� �����: " << endl;
    cin >> vertex;
    graph.bfs(vertex, visitedVertexes);

    graph.Pink_Floyd();


    return 0;
}
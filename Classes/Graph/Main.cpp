#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "Graph.h"
using namespace std;

int main()
{
    Graph<int> g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.print();

    return 0;
}
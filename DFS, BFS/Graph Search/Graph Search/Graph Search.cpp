#include <iostream>
#include "Graph.h"

int main()
{
    Graph* graph = new Graph();

    graph->AddEdge(0, 1);
    graph->AddEdge(1, 2);
    graph->AddEdge(1, 3);
    graph->AddEdge(2, 3);
    graph->AddEdge(2, 4);
    graph->AddEdge(3, 4);
    graph->AddEdge(3, 5);
    graph->AddEdge(5, 7);
    graph->AddEdge(5, 6);
    graph->AddEdge(6, 8);

    std::cout << "----------Start DFS----------" << std::endl;

    graph->DFS();
    graph->Init();
    std::cout << "----------Start BFS----------" << std::endl;

    graph->BFS();

    delete graph;

    return 0;
}
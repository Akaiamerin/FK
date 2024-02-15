#include <iostream>
#include "adjacency_list.h"
#include "critical_path.h"

int main() {
    AdjacencyList graph = {};
    CrtDirectedWeightedGraph(graph);
    CriticalPath(graph);
    return 0;
}
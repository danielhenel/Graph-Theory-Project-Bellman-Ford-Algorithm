#include <iostream>
#include "graph.h"
#include "bellman_ford.h"
using namespace std;



int main(){
    Graph * graph = loadGraph();
    graph->printEdges();
    Paths zero(graph, 0);
    zero.printPathToNodeWithGivenIndex(5);
    return 0;
}

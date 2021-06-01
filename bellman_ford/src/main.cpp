#include <iostream>
#include "graph.h"
#include "bellman_ford.h"
using namespace std;



int main(){
    Graph * graph = loadGraph();
    userInterface(graph);
    return 0;
}

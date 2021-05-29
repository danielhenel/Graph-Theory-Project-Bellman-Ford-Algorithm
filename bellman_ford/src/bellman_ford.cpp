#include "graph.h"
#include "bellman_ford.h"

Paths::Paths(Graph * g, int index){
    graph = g;
    startNodeIndex = index;
    N = graph->getNodesCounter();
    E = graph->getEdgesCounter();
    allPathNodes = new PathNode[N];
    GraphWithoutNegativeCycles = bellmanFord();
}

void Paths::printPathAndCalculateTheLength(int index, double &length){
    if(allPathNodes[index].prevNode)
    {
        int u = allPathNodes[index].prevNode->getIndex();
        length = length + graph->getEdgeValue(u, index);
        printPathAndCalculateTheLength(u, length);
    }
    cout<<index<<" --> ";
}

void Paths::printPathToNodeWithGivenIndex(int index){
    if(GraphWithoutNegativeCycles){
        double length = 0;
        cout<<endl<<"Congratulations the algorithm found the shortest path! Here it is:"<<endl;
        printPathAndCalculateTheLength(index, length);
        cout<<"LENGTH:  "<<length<<endl;
    }
    else{
        cout<<endl<<"The algorithm didn't find the shortest path, because the graph has negative cycles!"<<endl;
    }
}
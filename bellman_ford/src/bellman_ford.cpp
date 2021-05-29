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

void Paths::relaxation(Graph::Edge * edge){
    double w = edge->getValue();
    int v = edge->getEndNodeIndex();
    int u = edge->getStartNodeIndex();
    if(allPathNodes[v].minValue > allPathNodes[u].minValue + w){
        allPathNodes[v].minValue = allPathNodes[u].minValue + w;
        allPathNodes[v].prevNode = graph->getNode(u);
    }
}

bool Paths::check(Graph::Edge * edge){
    double w = edge->getValue();
    int v = edge->getEndNodeIndex();
    int u = edge->getStartNodeIndex();
    if(allPathNodes[v].minValue > allPathNodes[u].minValue + w)
        return false;
    return true;
}

bool Paths::bellmanFord(){
    allPathNodes[startNodeIndex] = {0, nullptr};
    for(int i = 0; i < N - 1; i++)
        for(int j = 0; j < E; j++)
            relaxation(graph->getEdge(j));

    for(int j = 0; j < E; j++)
        if(!(check(graph->getEdge(j)))) return false;
    return true;
}
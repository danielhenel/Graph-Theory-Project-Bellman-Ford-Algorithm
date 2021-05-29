#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H
#include "graph.h"

class Paths{
    struct PathNode{
        double minValue = 1000000;
        Graph::Node * prevNode = nullptr;
    };

    private:
        Graph * graph;
        int startNodeIndex;
        int N;
        int E;
        int GraphWithoutNegativeCycles;
        PathNode * allPathNodes;
        void relaxation(Graph::Edge * edge){
            double w = edge->getValue();
            int v = edge->getEndNodeIndex();
            int u = edge->getStartNodeIndex();
            if(allPathNodes[v].minValue > allPathNodes[u].minValue + w){
                allPathNodes[v].minValue = allPathNodes[u].minValue + w;
                allPathNodes[v].prevNode = graph->getNode(u);
            }
        }
        bool check(Graph::Edge * edge){
            double w = edge->getValue();
            int v = edge->getEndNodeIndex();
            int u = edge->getStartNodeIndex();
            if(allPathNodes[v].minValue > allPathNodes[u].minValue + w)
                return false;
            return true;
        }
        bool bellmanFord(){
            allPathNodes[startNodeIndex] = {0, nullptr};
            for(int i = 0; i < N - 1; i++)
                for(int j = 0; j < E; j++)
                    relaxation(graph->getEdge(j));

            for(int j = 0; j < E; j++)
                if(!(check(graph->getEdge(j)))) return false;
            return true;
        }
        void printPathAndCalculateTheLength(int index, double &length);

    public:
        Paths(Graph * graph, int startNodeIndex);
        void printPathToNodeWithGivenIndex(int index);


};




#endif

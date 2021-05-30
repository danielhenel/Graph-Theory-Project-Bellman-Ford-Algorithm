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
        void relaxation(Graph::Edge * edge);
        bool check(Graph::Edge * edge);
        bool bellmanFord();
        void printPathAndCalculateTheLength(int index, double &length);

    public:
        Paths(Graph * graph, int startNodeIndex);
        ~Paths(){delete [] allPathNodes;}
        void printPathToNodeWithGivenIndex(int index);
};


//----------------User Interface----------------//
void userInterface(Graph * graph);


#endif

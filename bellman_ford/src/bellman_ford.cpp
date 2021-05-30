#include "graph.h"
#include "bellman_ford.h"

using namespace std;

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

//----------------User Interface----------------//
void userInterface(Graph * graph){
    int nodesCounter = graph->getNodesCounter();
    int edgesCounter = graph->getEdgesCounter();
    if (nodesCounter > 0 && edgesCounter > 0){
        cout<<endl<<"The graph has been loaded successfully"<<endl
        <<"Number of nodes:\t"<<nodesCounter<<endl
        <<"Number of edges:\t"<<edgesCounter<<endl;


        while(true){
            cout<<"\n\nWhat do you want to do with your graph?\n"
            <<"Select A to print the adjacency list\n"
            <<"Select I to print the incident list\n"
            <<"Select B to search for the shortest paths with the Bellman Ford algorithm\n"
            <<"Select Q to quit the program\n";

            char s;
            while(cin>>s && s!='I' && s!='A' && s!='B' && s!='Q'){
            cout<<"What do you want to do with your graph?\n"
            <<"Select A to print the adjacency list\n"
            <<"Select I to print the incident list\n"
            <<"Select B to search for the shortest paths with the Bellman Ford algorithm\n"
            <<"Select Q to quit the program\n";
            }

            switch (s)
            {
            case 'I':
                graph->printIncidentMatrix();
                break;
            case 'A':
                graph->printAdjacencyList();
                break;
            case 'B':
            {
                cout<<"\nBELLMAN FORD ALGORITHM\n\n";
                bool exitWhile = false;
                while(true){
                    cout<<"Select a start node\n";
                    int startNode;
                       cout<<nodesCounter;
                    while(cin>>startNode && ((startNode >= nodesCounter && startNode > 0)||startNode < 0))
                        {cout<<"Such node does not exist - select it once again\n";}
                    Paths * x = new Paths(graph, startNode);
                    while(true){
                        cout<<"Select a end node\n";
                        int endNode;
                        bool quit = false;
                        while(cin>>endNode && ((endNode >= nodesCounter && endNode > 0)||endNode < 0))
                            cout<<"Such node does not exist - select it once again\n";
                        x->printPathToNodeWithGivenIndex(endNode);
                        cout<<"\nSelect X to find a path to another destination from the same starting node\n"
                        <<"Select Y to find a path from another starting node\n"
                        <<"Select Q to quit the bellman ford\n";

                        while(cin>>s && s!='X' && s!='Y' && s!='Q'){
                        cout<<"\nSelect X to find a path to another destination from the same starting node\n"
                        <<"Select Y to find a path from another starting node\n"
                        <<"Select Q to quit the bellman ford\n";  
                        }
                        switch (s)
                        {
                        case 'X':
                            break;
                        case 'Y':
                            delete x;
                            quit = true;
                            break;
                        case 'Q':
                            delete x;
                            exitWhile = true;
                            quit = true;
                            break;
                        default:
                            return;
                            break;
                        }
                        if(quit) break;
                    }
                    if(exit) break;
                }
                }
                break;
            case 'Q':
                return;
                break;
            default:
                return;
                break;
            }
        }
    }
    else{
        cout<<"\nERROR - the graph has not been loaded\n";
        return;
    }
}
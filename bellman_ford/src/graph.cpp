#include <iostream>
#include <fstream>
#include "graph.h"
using namespace std;

Graph::Graph(const char * fileName, bool v) {
ifstream file(fileName);




}

Graph::Graph(const char * fileName_1, const char * fileName_2, bool v){
ifstream file_1(fileName_1);
ifstream file_2(fileName_2);


}

void Graph::addEdge(int start, int end, int value){
    if(start > nodesCounter - 1 && start > 0){
        addNode(start);
    }
    if(end > nodesCounter - 1 && end > 0){
        addNode(end);
    }
    Edge * newEdge = new Edge(nodes->getNode(start), nodes->getNode(end), value, edgesCounter);
    edgesCounter++;
    if(edges) edges->addElement(newEdge);
}

void Graph::addNode(int index){

}

Graph::Node * Graph::NodesList::getNode(int index){}




void Graph::addNode(int index){
    if(!nodes->getNode(index)){
        Node * newNode = new Node(index);
        nodes->addElement(newNode);
        nodesCounter++;
    }
}

//----------------Graph::Node----------------//
Graph::Node::Node(int i){
    index = i;
    adjacentNodes = nullptr;
}

Graph::Node::~Node(){
    adjacentNodes->deleteIndexesList();
}

//----------------Graph::Edge----------------//
Graph::Edge::Edge(Node * s, Node * e, double v, int i){
    start = s;
    end = e;
    value = v;
    index = i;
}
Graph::Edge::~Edge(){}

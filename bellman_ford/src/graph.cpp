#include <iostream>
#include <fstream>
#include "graph.h"
using namespace std;

//----------------Graph----------------//
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
    Edge newEdge(nodes.getNode(start), nodes.getNode(end), value, edgesCounter);
    edges.addElement(newEdge);
    edgesCounter++;
}


void Graph::addNode(int index){
    if(!nodes.getNode(index)){
        Node newNode(index);
        nodes.addElement(newNode);
        nodesCounter++;
    }
}

//----------------Graph::Node----------------//
Graph::Node::Node(int i){
    index = i;
    adjacentNodes = nullptr;
}

Graph::Node::~Node(){
    adjacentNodes->~IndexesList();
}

bool Graph::Node::operator==(Node x){
    if(this->index == x.index) return true;
    else return false;
}

bool Graph::Node::operator==(int x){
    if(this->index == x) return true;
    else return false;
}

//----------------Graph::Edge----------------//
Graph::Edge::Edge(Node * s, Node * e, double v, int i){
    start = s;
    end = e;
    value = v;
    index = i;
}
Graph::Edge::~Edge(){}

bool Graph::Edge::operator==(Edge x){
    if(this->index == x.index) return true;
    else return false;
}

bool Graph::Edge::operator==(int x){
    if(this->index == x) return true;
    else return false;
}

//----------------Graph::EdgesList----------------//
Graph::EdgesList::EdgesList(){
    firstElement = nullptr;
    lastElement = nullptr;
}
Graph::EdgesList::~EdgesList(){this->deleteEdgesList();}

void Graph::EdgesList::addElement(Edge newElement){
    if(!firstElement && !lastElement){
        firstElement = lastElement = new EdgesListElement{newElement, nullptr, nullptr};
    }
    else{
        lastElement->pNext = new EdgesListElement{newElement, lastElement, nullptr};
        lastElement = lastElement->pNext;
    }

}
void Graph::EdgesList::deleteElement(Edge deletedElement){
    if(firstElement && firstElement->element == deletedElement){ //when we want to remove first element
        if(firstElement != lastElement){ //more then one element in the list
            EdgesListElement * temp = firstElement;
            firstElement = firstElement->pNext;
            delete temp;
            return;
        }
        else{ //only one element in the list
            EdgesListElement * temp = firstElement;
            firstElement = lastElement = nullptr;
            delete temp;
            return;
        }

    }
    else if(lastElement && lastElement->element == deletedElement){ //when we want to remove last element
        EdgesListElement * temp = lastElement;
        if(lastElement->pPrev){ //more then one element in the list
            lastElement->pPrev->pNext = lastElement->pNext;
            delete temp;
            return;
        }
        else{ //only one element in the list
            lastElement = firstElement = nullptr;
            delete temp;
            return;
        }
    }
    else{ //when the deleted element isn't first and last
        EdgesListElement * temp = firstElement;
        while(temp)
        {
            if(temp->element == deletedElement){
                temp->pPrev->pNext = temp->pNext;
                delete temp;
                break;
            }
            temp = temp->pNext;
        }
    }
}

void Graph::EdgesList::deleteEdgesList(){
    while(firstElement){
        this->deleteElement(firstElement->element);
    }
}


//----------------Graph::NodesList----------------//
Graph::NodesList::NodesList(){
    firstElement = nullptr;
    lastElement = nullptr;
}
Graph::NodesList::~NodesList(){this->deleteNodesList();}

void Graph::NodesList::addElement(Node newElement){
    if(!firstElement && !lastElement){
        firstElement = lastElement = new NodesListElement{newElement, nullptr, nullptr};
    }
    else{
        lastElement->pNext = new NodesListElement{newElement, lastElement, nullptr};
        lastElement = lastElement->pNext;
    }

}
void Graph::NodesList::deleteElement(Node deletedElement){
    if(firstElement && firstElement->element == deletedElement){ //when we want to remove first element
        if(firstElement != lastElement){ //more then one element in the list
            NodesListElement * temp = firstElement;
            firstElement = firstElement->pNext;
            delete temp;
            return;
        }
        else{ //only one element in the list
            NodesListElement * temp = firstElement;
            firstElement = lastElement = nullptr;
            delete temp;
            return;
        }

    }
    else if(lastElement && lastElement->element == deletedElement){ //when we want to remove last element
        NodesListElement * temp = lastElement;
        if(lastElement->pPrev){ //more then one element in the list
            lastElement->pPrev->pNext = lastElement->pNext;
            delete temp;
            return;
        }
        else{ //only one element in the list
            lastElement = firstElement = nullptr;
            delete temp;
            return;
        }
    }
    else{ //when the deleted element isn't first and last
        NodesListElement * temp = firstElement;
        while(temp)
        {
            if(temp->element == deletedElement){
                temp->pPrev->pNext = temp->pNext;
                delete temp;
                break;
            }
            temp = temp->pNext;
        }
    }
}

void Graph::NodesList::deleteNodesList(){
    while(firstElement){
        this->deleteElement(firstElement->element);
    }
}


Graph::Node * Graph::NodesList::getNode(int index){
    NodesListElement * temp = firstElement;
    while(temp){
        if(temp->element == index) return &(temp->element);
        temp = temp->pNext;
    }
    return nullptr;
}


//----------------Graph::IndexesList----------------//
Graph::IndexesList::IndexesList(){
    firstElement = nullptr;
    lastElement = nullptr;
}
Graph::IndexesList::~IndexesList(){this->deleteIndexesList();}

void Graph::IndexesList::addElement(int newElement){
    if(!firstElement && !lastElement){
        firstElement = lastElement = new IndexesListElement{newElement, nullptr, nullptr};
    }
    else{
        lastElement->pNext = new IndexesListElement{newElement, lastElement, nullptr};
        lastElement = lastElement->pNext;
    }

}
void Graph::IndexesList::deleteElement(int deletedElement){
    if(firstElement && firstElement->value == deletedElement){ //when we want to remove first element
        if(firstElement != lastElement){ //more then one element in the list
            IndexesListElement * temp = firstElement;
            firstElement = firstElement->pNext;
            delete temp;
            return;
        }
        else{ //only one element in the list
            IndexesListElement * temp = firstElement;
            firstElement = lastElement = nullptr;
            delete temp;
            return;
        }

    }
    else if(lastElement && lastElement->value == deletedElement){ //when we want to remove last element
        IndexesListElement * temp = lastElement;
        if(lastElement->pPrev){ //more then one element in the list
            lastElement->pPrev->pNext = lastElement->pNext;
            delete temp;
            return;
        }
        else{ //only one element in the list
            lastElement = firstElement = nullptr;
            delete temp;
            return;
        }
    }
    else{ //when the deleted element isn't first and last
        IndexesListElement * temp = firstElement;
        while(temp)
        {
            if(temp->value == deletedElement){
                temp->pPrev->pNext = temp->pNext;
                delete temp;
                break;
            }
            temp = temp->pNext;
        }
    }
}

void Graph::IndexesList::deleteIndexesList(){
    while(firstElement){
        this->deleteElement(firstElement->value);
    }
}
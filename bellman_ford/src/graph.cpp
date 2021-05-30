#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "graph.h"
using namespace std;

//----------------Graph----------------//
Graph::Graph(string fileName, bool v) {
vector<vector<int>> tab = readFile(fileName);
    if(v){ //incident matrix
        for(int j = 0; j < tab[0].size(); j++){
            int start = -1;
            int end = -1;
            for(int i = 0; i < tab.size(); i++){
                if(tab[i][j] == 1) start = i;
                if(tab[i][j] == -1) end = i;
                if(start >= 0 && end >=0){
                    addEdge(start, end, randomValue());
                    break;
                }
            }
        }
    }
    else{ //adjacency list
        for(int i = 0; i < tab.size(); i++)
            for(int j = 0; j < tab[i].size(); j++)
                addEdge(i, tab[i][j], randomValue());
    }
    srand(time(NULL));
}


Graph::Graph(string fileName_1, string fileName_2, bool v){
vector<vector<int>> tab = readFile(fileName_1);
vector<vector<double>> values = readFile2(fileName_2);
    if(v){ //incident matrix
        for(int j = 0; j < tab[0].size(); j++){
            int start = -1;
            int end = -1;
            for(int i = 0; i < tab.size(); i++){
                if(tab[i][j] == 1) start = i;
                if(tab[i][j] == -1) end = i;
                if(start >= 0 && end >=0){
                    addEdge(start, end, values[start][end]);
                    break;
                }
            }
        }
    }
    else{ //adjacency list
        for(int i = 0; i < tab.size(); i++)
            for(int j = 0; j < tab[i].size(); j++)
                addEdge(i, tab[i][j], values[i][tab[i][j]]);
    }
    srand(time(NULL));
}


void Graph::addEdge(int start, int end, double value){


    if(!nodes.getNode(start)){
        addNode(start);
    }
    if(!nodes.getNode(end)){
        addNode(end);
    }
    Edge newEdge(nodes.getNode(start), nodes.getNode(end), value, edgesCounter);
    edges.addElement(newEdge);
    nodes.getNode(start)->addNewAdjacentNode(end);
    edgesCounter++;
}


void Graph::addNode(int index){
    if(!nodes.getNode(index)){
        Node newNode(index);
        nodes.addElement(newNode);
        nodesCounter++;
    }
}

vector<vector<int>> Graph::readFile(string fileName){
ifstream file(fileName);
    vector<vector<int>> tab;
    if(file){
        string row;
        while(getline(file, row)){
            stringstream ss;
            vector<int> numbers;
            ss << row;
            int number;
            while(ss >> number){
                numbers.push_back(number);
            }
            tab.push_back(numbers);
        }
    }
    return tab;
}

vector<vector<double>> Graph::readFile2(string fileName){
ifstream file(fileName);
    vector<vector<double>> tab;
    if(file){
        string row;
        while(getline(file, row)){
            stringstream ss;
            vector<double> numbers;
            ss << row;
            double number;
            while(ss >> number){
                numbers.push_back(number);
            }
            tab.push_back(numbers);
        }
    }
    return tab;
}

int Graph::randomValue(){
    return (rand()%1000)+19;
}

void Graph::operator=(Graph x){
    this->nodes = x.nodes;
    this->edges = x.edges;
    this->nodesCounter = x.nodesCounter;
    this->edgesCounter = x.edgesCounter;
}

Graph::~Graph(){}

void Graph::printEdges(){
    edges.printEdges();
}

void Graph::printIncidentMatrix(){
    cout<<endl<<"INCIDENT MATRIX"<<endl;
    int tab[nodesCounter][edgesCounter];
    for(int i = 0; i < nodesCounter; i++)
        for(int j = 0; j < edgesCounter; j++)
            tab[i][j] = 0;

    for(int j = 0; j < edgesCounter; j++){
        int u = edges.getEdge(j)->getStartNodeIndex();
        int v = edges.getEdge(j)->getEndNodeIndex();
        tab[u][j] = 1;
        tab[v][j] = -1;
    }

    cout<<"\t";
    for(int j = 0; j < edgesCounter; j++)
    {
        cout.width(3);
        cout<<j;
    }
    cout<<endl<<endl;
        
    for(int i = 0; i < nodesCounter; i++)
    {
        cout<<i<<"\t";
        for(int j = 0; j < edgesCounter; j++)
        {
            cout.width(3);
            cout<<tab[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}


void Graph::printAdjacencyList(){
    cout<<endl<<"ADJACENCY LIST:"<<endl;
    for(int i = 0 ; i < nodesCounter; i++){
        cout.width(0);
        cout<<i<<":\t";
        for(int j = 0; j < nodesCounter; j++){
            cout.width(3);
            if(getEdge(i,j))cout<<j;
        }
        cout<<endl;
    }
    cout<<endl;
}

//----------------Graph::Node----------------//
Graph::Node::Node(int i){
    index = i;
    adjacentNodes = new IndexesList();
}

Graph::Node::~Node(){}

bool Graph::Node::operator==(Node x){
    if(this->index == x.index) return true;
    else return false;
}

bool Graph::Node::operator==(int x){
    if(this->index == x) return true;
    else return false;
}

void Graph::Node::addNewAdjacentNode(int index){
    adjacentNodes->addElement(index);
}

int Graph::Node::getIndex(){
    return index;
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

void Graph::Edge::printEdge(){
    cout<<index<<"::\t"<<start->getIndex()<<" ---> "<<end->getIndex()<<"\tvalue: "<<value<<endl;
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
        lastElement->pNext = new EdgesListElement{newElement, nullptr, lastElement};
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

void::Graph::EdgesList::printEdges(){
    EdgesListElement * temp = firstElement;
    while(temp){
        temp->element.printEdge();
        temp = temp->pNext;
    }
}

Graph::Edge * Graph::EdgesList::getEdge(int u, int v){
    EdgesListElement * temp = firstElement;
    while(temp){
        if(temp->element.getStartNodeIndex() == u && temp->element.getEndNodeIndex() == v) return &(temp->element);
        temp = temp->pNext;
    }
    return nullptr;
}

Graph::Edge * Graph::EdgesList::getEdge(int index){
    EdgesListElement * temp = firstElement;
    while(temp){
        if(temp->element == index) return &(temp->element);
        temp = temp->pNext;
    }
    return nullptr;
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
        lastElement->pNext = new NodesListElement{newElement, nullptr, lastElement};
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
        lastElement->pNext = new IndexesListElement{newElement, nullptr, lastElement};
        lastElement = lastElement->pNext;
    }

}
void Graph::IndexesList::deleteElement(int deletedElement){
    if(firstElement && firstElement->value == deletedElement){ //when we want to remove first element
        if(firstElement != lastElement){ //more then one element in the list
            IndexesListElement * temp = firstElement;
            firstElement = firstElement->pNext;
            firstElement->pPrev = nullptr;
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

//----------------Load Graph----------------//
Graph * loadGraph(){
    cout<<"Hello! Load your Graph!\n";
    cout<<"Select A to load a graph from the adjacency list\n";
    cout<<"Select I to load a graph from the incident list\n";
    char s;
    while(cin>>s && s!='I' && s!='A'){
        cout<<"Select A to load a graph from the adjacency list\n";
        cout<<"Select I to load a graph from the incident list\n";
    }
    if(s == 'I'){
        cout<<"Select R to set random edges values\n";
        cout<<"Select F to load edges values from the file\n";
        while(cin>>s && s!='R' && s!='F'){
            cout<<"Select R to set random edges values\n";
            cout<<"Select F to load edges values from the file\n";
        }
        if(s == 'F'){
            string fileName_1;
            string fileName_2;
            cout<<"Enter name of the file with an incident matrix\n";
            cin >> fileName_1;
            cout<<"Enter name of the file with a value matrix\n";
            cin >> fileName_2;
            cout<<"GRAPH LOADING\n";
            Graph * graph = new Graph(fileName_1, fileName_2, true); //
            return graph;
        }
        if(s == 'R'){
            string fileName;
            cout<<"Enter name of the file with an incident matrix\n";
            cin >> fileName;
            cout<<"GRAPH LOADING\n";
            Graph * graph = new Graph(fileName, true); //
            return graph;
        }
    }
    if(s == 'A'){
        cout<<"Select R to set random edges values\n";
        cout<<"Select F to load edges values from the file\n";
        while(cin>>s && s!='R' && s!='F'){
            cout<<"Select R to set random edges values\n";
            cout<<"Select F to load edges values from the file\n";
        }
        if(s == 'F'){
            string fileName_1;
            string fileName_2;
            cout<<"Enter name of the file with an adjacency list\n";
            cin >> fileName_1;
            cout<<"Enter name of the file with a value matrix\n";
            cin >> fileName_2;
            cout<<"GRAPH LOADING\n";
            Graph * graph = new Graph(fileName_1, fileName_2, false); //
            return graph;
        }
        if(s == 'R'){
            string fileName;
            cout<<"Enter name of the file with an adjacency list\n";
            cin >> fileName;
            cout<<"GRAPH LOADING\n";
            Graph * graph = new Graph(fileName, false);
            return graph;
        }
    }
    return 0;
}
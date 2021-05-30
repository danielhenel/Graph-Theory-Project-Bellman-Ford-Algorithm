#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//a class to represent the graph
class Graph{
public:
    class Node;
    class NodeListElement;
    class NodesList;
    class Edge;
    class EdgesListElement;
    class EdgesList;
    class IndexesListElement;
    class IndexesList;

    //a class to represent nodes in the graph
    class Node{
        private:
            int index; ///< node index
            IndexesList * adjacentNodes; ///< a list containing indexes of adjacent nodes of this node
        public:
            /** Node constructor
            @param index ///< node index
            */
            Node(int index);
            /** Node destructor
            */
            ~Node();
            bool operator==(Node x);
            bool operator==(int x);
            void addNewAdjacentNode(int index);
            int getIndex();
    };
    
    //a class to represent edges in the graph
    class Edge{
        private:
            Node * start; ///< a pointer to start node of edge
            Node * end; ///< a pointer to end node of edge
            double value; ///< egde value
            int index; ///< egde index
        public:
            /** Edge constructor
            @param start //< a pointer to start node of edge
            @param end ///< a pointer to end node of edge
            @param value ///< egde value
            @param index ///< egde index
            */
            Edge(Node * start, Node * end, double value, int index);
            ~Edge();
            bool operator==(Edge x);
            bool operator==(int x);
            void printEdge();
            int getStartNodeIndex(){return start->getIndex();}
            int getEndNodeIndex(){return end->getIndex();}
            double getValue(){return value;}
    };

    //a struct to represent one element of list of edges
    struct EdgesListElement{
        Edge element; ///< edge
        EdgesListElement * pNext; ///< a pointer to next element
        EdgesListElement * pPrev; ///< a pointer to previous element
    };

    //a struct to represent one element of list of nodes
    struct NodesListElement{
        Node element; ///< node
        NodesListElement * pNext; ///< a pointer to next element
        NodesListElement * pPrev; ///< a pointer to previous element
    };

    //a class to represent list of edges
    class EdgesList{
        private:
            EdgesListElement * firstElement; ///< a pointer to first element
            EdgesListElement * lastElement; ///< a pointer to last element
            /** use this function to delete all edges
            */
            void deleteEdgesList();
        public:
            /** edge list constructor: default pointer to first and last element is nullptr
            */
            EdgesList();
            /** egde list destructor: all edges will be deleted
            */
            ~EdgesList();
            /** use this function to add new element
            @param newElement ///< new edge
             */
            void addElement(Edge newEdge);
            /** use this function to delete a element
            @param deletedElement ///< deleted edge
             */
            void deleteElement(Edge deletedEdge);
            void printEdges();
            Edge * getEdge(int u, int v);
            Edge * getEdge(int index);
    };

    //a class to represent list of nodes
    class NodesList{
        private:
            NodesListElement * firstElement; ///< a pointer to first element
            NodesListElement * lastElement; ///< a pointer to last element
            /** use this function to delete all nodes
            */
            void deleteNodesList();
        public:
            /** node list constructor: default pointer to first and last element is nullptr
            */
            NodesList();
            /** node list destructor: all nodes will be deleted
            */
            ~NodesList();
            /** use this function to add new element
            @param newElement ///< new node
             */
            void addElement(Node newNode);
            /** use this function to delete a element
            @param deletedNode ///< deleted node
             */
            void deleteElement(Node deletedNode);
            Node * getNode(int index);
            //void printNodes();
    };

    struct IndexesListElement{
        int value;
        IndexesListElement * pNext;
        IndexesListElement * pPrev;
    };
    class IndexesList{
        private:
            IndexesListElement * firstElement;
            IndexesListElement * lastElement;
            /** use this function to delete indexes list
            */
            void deleteIndexesList();
        public:
            /** indexes list constructor: default pointer to first and last element is nullptr
            */
            IndexesList();
            /** indexes list destructor: all indexes list elements will be deleted
            */
            ~IndexesList();
            /** use this function to add a element
            @param deletedNode ///< new value
             */
            void addElement(int value);
            /** use this function to delete a element
            @param value ///< deleted value
             */
            void deleteElement(int value);
    };

    private:
        NodesList nodes; ///< list of nodes in the graph
        EdgesList edges; ///< list of edges in the graph
        int nodesCounter = 0; ///< number of nodes in the graph
        int edgesCounter = 0; ///< number of edges in the graph

        /** the function adds a new edge to the graph, if nodes do not exist it creates them
         @param start ///< start node index
         @param end ///< end node index
         @param value ///< edge value
        */
        void addEdge(int start, int end, double value);

        /** the function adds a new node to the graph
         @param index ///< new node index
        */
        void addNode(int index);
        
        void removeEgde();
        void removeNode();
        vector<vector<int>> readFile(string fileName);
        vector<vector<double>> readFile2(string fileName);
        int randomValue();
        

    public:
    /** graph creator - random values
        @param fileName ///< a file with incident matrix or adjacency list
        @param v ///< if true fileName_1 is incident matrix else fileName_2 is adjacency list
    */
        Graph(string fileName, bool v); ///< graph creator - random values

    /** graph creator - values from file
        @param fileName_1 ///< a file with incident matrix or adjacency list
        @param filneName_2 ///< a file with edges values
        @param v ///< if true fileName_1 contains incident matrix else fileName_1 constains adjacency list
    */
        Graph(string fileName_1, string fileName_2, bool v);
    
    /** graph destructor
    */
        ~Graph();
        Graph(){}
        void operator=(Graph x);
        void printEdges();
        int getNodesCounter(){return  nodesCounter;}
        int getEdgesCounter(){return  edgesCounter;}
        Node * getNode(int index){return nodes.getNode(index);}
        Edge * getEdge(int u, int v){return edges.getEdge(u,v);}
        Edge * getEdge(int index){return edges.getEdge(index);}
        double getEdgeValue(int index){return edges.getEdge(index)->getValue();}
        double getEdgeValue(int u, int v){return edges.getEdge(u, v)->getValue();}
        int getEdgeStartNodeIndex(int index){return edges.getEdge(index)->getStartNodeIndex();}
        int getEdgeEndNodeIndex(int index){return edges.getEdge(index)->getEndNodeIndex();}
        void printIncidentMatrix();



};

Graph * loadGraph();

#endif
#include <iostream>
using namespace std;

//a class to represent the graph
class Graph{

    class NodesList;
    class Node;
    class EdgesList;
    class Edge;
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

            //Node * getNode(int index);
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
        void addEdge(int start, int end, int value);

        /** the function adds a new node to the graph
         @param index ///< new node index
        */
        void addNode(int index);
        
        void removeEgde();
        void removeNode();
        

    public:
    /** graph creator - random values
        @param fileName ///< a file with incident matrix or adjacency list
        @param v ///< if true fileName_1 is incident matrix else fileName_2 is adjacency list
    */
        Graph(const char * fileName, bool v); ///< graph creator - random values

    /** graph creator - values from file
        @param fileName_1 ///< a file with incident matrix or adjacency list
        @param filneName_2 ///< a file with edges values
        @param v ///< if true fileName_1 contains incident matrix else fileName_1 constains adjacency list
    */
        Graph(const char * fileName_1, const char * fileName_2, bool v);
    
    /** graph destructor
    */
        ~Graph();



};

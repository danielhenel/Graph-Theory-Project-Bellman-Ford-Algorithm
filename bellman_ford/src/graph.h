#include <iostream>
using namespace std;

//a class to represent the graph
class Graph{

    class NodeList;
    class Node;
    class EdgeList;
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
    };

    //a class to represent one element of list of edges
    class EdgesListElement{
        private:
            Edge element; ///< edge
            EdgesListElement * pNext; ///< a pointer to next element
            EdgesListElement * pPrev; ///< a pointer to previous element
    };

    //a class to represent one element of list of nodes
    class NodesListElement{
        private:
            Node element; ///< node
            NodesListElement * pNext; ///< a pointer to next element
            NodesListElement * pPrev; ///< a pointer to previous element
    };

    //a class to represent list of edges
    class EdgesList{
        private:
            EdgesListElement * firstElement; ///< a pointer to first element
            EdgesListElement * lastElement; ///< a pointer to last element
        public:
            EdgesList();
            ~EdgesList();
            void addElement(Edge * newElement);
            void deleteElement(Edge * deletedElement);
    };

    //a class to represent list of nodes
    class NodesList{
        private:
            NodesListElement * firstElement; ///< a pointer to first element
            NodesListElement * lastElement; ///< a pointer to last element
        public:
            NodesList();
            ~NodesList();
            void addElement(Node * newNode);
            void deleteElement(Node * deletedNode);
            Node * getNode(int index);
    };

    class IndexesListElement{
        int value;
        IndexesListElement * pNext;
    };
    class IndexesList{
        private:
            IndexesListElement * firstElement;
            IndexesListElement * lastElement;
        public:
            void addElement(int value);
            void deleteElement(int value);
            void deleteIndexesList();
    };
    private:
        NodesList * nodes; ///< list of nodes in the graph
        EdgesList * edges; ///< list of edges in the graph
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

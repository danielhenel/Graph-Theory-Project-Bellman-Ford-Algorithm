#include <iostream>
using namespace std;

//a class to represent the graph
class Graph{

    class NodeList;
    class Node;
    class EdgeList;
    class Edge;

    //a class to represent nodes in the graph
    class Node{
        private:
            int index; ///< node index
            int * adjacentNodes; ///< a list containing adjacent nodes of this node
        public:
           Node(int index, int * nodes);
           // ~Node();
    };
    
    //a class to represent edges in the graph
    class Edge{
        private:
            Node * start; ///< a pointer to start node of edge
            Node * end; ///< a pointer to end node of edge
            double value; ///< egde value
            int index; ///< egde index
        public:
           Edge(Node * s, Node * e, double v, int i);
           // ~Edge();
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
            void addElement();
            void deleteElement();
            Node * getNode(int index);
    };

    class IndexesListElement{
        int value;
        IndexesListElement * pNext;
    };
    class IndexesList{
        IndexesListElement * firstElement;
        IndexesListElement * lastElement;
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

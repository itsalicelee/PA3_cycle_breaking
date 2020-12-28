#include<list>
#include<vector>
#include<iostream>
#include <cstdlib> 
#include <iostream> 


#ifndef _CYCLE_BREAKING_H
#define _CYCLE_BREAKING_H


typedef						std::vector<int> int_arr;
typedef						std::vector<char> char_arr;
typedef 					std::vector<bool> bool_arr;
typedef 					std::list<struct Node> node_arr;
// typedef 					std::vector<std::vector<bool ,int> > vp_arr;

const int MAX_WEIGHT = 999;


// Data structure to store Adjacency list nodes
struct Node {
	int nodeKey, cost;
	Node* root;
	//Node* pi = nullptr;
	Node* next;
	char color = 'w';
	int d = 0;  // for DFS
	int f = 0;  // for DFS
	int rank = 0;  // for Kruskal
};

// Data structure to store graph edges
class Edge {
public:
	int src, dest, weight;
};

class subset {
public:
    int parent;
    int rank;
	
};


class Graph
{
private:
	int cost = 0;
	int edgeNum;
	char graphType;
    char_arr color;
	int_arr d, f, weight, pi;
	bool_arr visit;
	node_arr remove;
	// vp_arr visited_weight;
	Node* getAdjListNode(int value, int weight, Node* head);
	

public:
	std::vector<std::vector<int> > edgeSet;
	std::vector<std::vector<int> > weightSet;
	std::vector<Edge > edgeList;
	
	
	int nodeNum;	// number of nodes in the graph
	
	bool hasCycle;
	std::list<int>* h;
	
	Node** head;  // An array of pointers to Node to represent adjacency list
	Graph(int nodeNum, char graphType);  // Constructor
	Graph(int edgeNum, int nodeNum, char graphType);  // Constructor
	~Graph();  // Destructor
	void printGraph();
	void printList(int i);  // print (start,end,weight) of a given vertix
	bool DFS_visit(int u, int& time);
	void printDFS();
	void DFS();
	void PrimMST(int start);
	std::vector<Edge> KruskalMST();
	std::vector<Edge> KruskalRemoveEdge(std::vector<std::vector<int> > mst, std::vector<Edge> treeVec);
	int  ExtractMax(bool_arr visited, int_arr weight);
	void printPrim();
	void initialize();	
	// void removeEdge();	
	void primRemoveEdge();
	bool isCyclicUtil(int v, bool_arr visited, bool *rs);
	std::vector<Edge > countingSort(std::vector<Edge > edgeList);
	std::vector<Edge> addEdge(std::vector<Edge>& tree, std::vector<Edge>& removeEdget);
	int find(subset subsets[], int i);
	void Union(subset subsets[], int x, int y);
	bool isCyclicUtil(int v, bool visited[], bool *recStack);
	bool isCyclic();
	int getCost(){return cost;};
	

};



// Data structure for Min Heap
struct PriorityQueue 
{
private:
    // vector to store heap elements
    std::vector<int> A;
    int PARENT(int i) { return (i - 1) / 2; }  // don't call this function if i is already a root
    int LEFT(int i) { return (2 * i + 1); }  // return left child of A[i]    
    int RIGHT(int i) { return (2 * i + 2);}  // return right child of A[i] 
 
    // Recursive Heapify-down algorithm
    // the node at index i and its two direct children
    void heapify_down(int i);  // violates the heap property
    void heapify_up(int i);  // Recursive Heapify-up algorithm
    
public:
    unsigned int size(){return A.size();}  // return size of the heap
    bool empty(){return size() == 0;}  // function to check if heap is empty or not
    void push(int key);  // insert key into the heap
    void pop();  // function to remove element with lowest priority (present at root)
    int top();  // function to return element with lowest priority (present at root)
	bool inQueue(int n);
	void printQueue();
};


class BinaryHeap {
private:
        void    MinHeapify(std::vector<int>&, int); // make tree with given root be a max-heap 
        void    BuildMinHeap(std::vector<int>&); // make data become a max-heap
        
		
public:
		int     heapSize; // heap size used in heap sort
		void    HeapSort(std::vector<int>&); // sort data using heap sort
		int 	ExtractMaxFromHeap(std::vector<int>&);
		void  	printMinHeap(std::vector<int>& );

};

#endif
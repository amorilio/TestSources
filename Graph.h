#pragma once

#include<iostream>
#include <list>

#define ROW 5
#define COL 5

class Graph
{
    int V;                      // No. of vertices
    int E;                      // No. of Edges
    std::list<int> *adj;        // Pointer to an array containing adjacency lists

    void DFSUtil(int v, bool visited[]);  // A function used by DFS

    int isSafe(int M[][COL], int row, int col, bool visited[][COL]);
    void DFS_For_Islands(int M[][COL], int row, int col, bool visited[][COL]);

public:
    Graph(int V);               // Constructor
    
	void printGraph();

    int numVertexes()   { return V; }
    int numEdges()      { return E; }

    void addEdge(int v, int w); // function to add an edge to graph
    int degree(int v);
    int maxDegree();
    double averageDegree();
    int numberOfSelfLoops();

    void BFS(int s);            // prints BFS traversal from a given source s
    void DFS();                 // prints DFS traversal of the complete graph

    int countIslands(int M[][COL]);

    bool isReachable(int s, int d);
};

extern void GraphTest();
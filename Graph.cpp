#include "Graph.h"
#include <iterator> 

using namespace std;

void GraphTest()
{
    cout << "--------------- Starting Graph Test --------------- " << endl;

    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.printGraph();

    cout << endl << "Following is Breadth First Traversal (starting from vertex 2)" << endl;
    g.BFS(2);

    cout << endl << "Following is Breadth First Traversal (starting from vertex 2)" << endl;
    g.DFS();
    
    int M[ROW][COL] = { { 1, 1, 0, 0, 0 },
                        { 0, 1, 0, 0, 1 },
                        { 1, 0, 0, 1, 1 },
                        { 0, 0, 0, 0, 0 },
                        { 1, 0, 1, 0, 1 }
                      };

    printf("\nNumber of islands is: %d\n", g.countIslands(M));
    cout << "--------------- Finished Graph Test --------------- " << endl;
}

Graph::Graph(int V)
{
    E = 0;
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::printGraph()
{
    cout << "The Graph has " << numVertexes() << " vertexes and " << numEdges() << " edges." << endl;
    for (int v = 0; v < numVertexes(); v++)
    {
        cout << "Vertex " << v << " connected to : ";
        list<int>::iterator it = adj[v].begin();
        while (it != adj[v].end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    E++;
}

// Degree of Vertex is number of edges from it
int Graph::degree(int v)
{
    int degree = 0;
    list<int> adjList = adj[v];
    for (unsigned int w=0; w < adjList.size(); w++)
        degree++;
    return degree;
}

int Graph::maxDegree()
{
    int max = 0;
    for (int v = 0; v < V; v++)
        if (degree(v) > max)
            max = degree(v);
    return max;
}

double Graph::averageDegree()
{
    return 2.0 * numEdges() / numVertexes();
}

int Graph::numberOfSelfLoops()
{
    int count = 0;
    for (int v = 0; v < numVertexes(); v++)
    {
        for(unsigned int i = 0; i < adj[v].size(); i++)
        {
            list<int>::iterator it = adj[v].begin();
            while(it != adj[v].end())
            {
                if (v == *it) 
                    count++;		
            }
        }
    }
     
    return count / 2; // each edge counted twice
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    std::list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent vertices of a vertex
    std::list<int>::iterator i;

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        std::cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    std::cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

// The function to do DFS traversal. It uses recursive DFSUtil()
void Graph::DFS()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print DFS traversal
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            DFSUtil(i, visited);
}

// A function to check if a given cell (row, col) can be included in DFS
int Graph::isSafe(int M[ROW][COL], int row, int col, bool visited[ROW][COL])
{
    return	(row >= 0) && (row < ROW) &&			// row number is in range
            (col >= 0) && (col < COL) &&			// column number is in range
            (M[row][col] && !visited[row][col]);	// value is 1 and not yet visited
}

// A utility function to do DFS for a 2D boolean matrix. It only considers the 8 neighbors as adjacent vertices
void Graph::DFS_For_Islands(int M[][COL], int row, int col, bool visited[][COL])
{
    // These arrays are used to get row and column numbers of 8 neighbors of a given cell
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    // Mark this cell as visited
    visited[row][col] = true;

    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
            DFS_For_Islands(M, row + rowNbr[k], col + colNbr[k], visited);
}

// The main function that returns count of islands in a given boolean 2D matrix
int Graph::countIslands(int M[ROW][COL])
{
    // Make a bool array to mark visited cells and initially all cells are unvisited
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    // Initialize count as 0 and travese through the all cells of given matrix
    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
            if (M[i][j] && !visited[i][j]) // If a cell with value 1 is not visited yet, then new island found
            {                              
                DFS_For_Islands(M, i, j, visited);  // Visit all cells in this island.
                ++count;                            // and increment island count
            }

    return count;
}

// A BFS based function to check whether d is reachable from s.
bool Graph::isReachable(int s, int d)
{
    // Base case
    if (s == d)
        return true;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // it will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            // If this adjacent node is the destination node, then return true
            if (*i == d)
                return true;

            // Else, continue to do BFS
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    return false;
}
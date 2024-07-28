#include <bits/stdc++.h>
using namespace std;

// Graphs
// Cyclic - acyclic
// directed undirected
// weighted or not

// dag directed acyclic graph gives dependecy graph

// Bipartite Graphs
// 2 sets of A , B Nodes
// edges can go from A -> B
// edges can go from B -> A
// internal linking not allowed

// to check if graph is bipitrate , do 2 - colouring problem check on nodes
// bipitrate can't have odd numbered cycles

// Questions

// 1 Connectivity Source -> Destination

// 2 Shortest Path
//  non Weighted (BFS)
// 3 Weighted ( dijkstra (no negative cycle), bellman ford (negative cycle), floyd warshall (too many calculations of source to dest))

// connected components , disconnected graphs (cant reach some points when starting from random node)

// 4 bridges / articulation point
//  bridge is an edge that if removed from the graph increases the connected components
//  articulation point is a node that if removed increase connected components

// 5 Minimum Spanning Tree
// prim's , kruskal

// 6 Network Flow
//  capacity of each edge (how much water can flow)
//  how much is flowing
//  direction
// ford furlkarsen , edmond karp

// 7 travelling salesman

// 8 Strongly connected componenets

class Graph
{

public:
    bool undirected;
    int size;
    list<int> *adj;

    Graph(int V, bool undirected = false)
    {
        this->undirected = undirected;
        this->size = V;
        this->adj = new list<int>[this->size];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        // undirected
        if (this->undirected)
        {
            adj[v].push_back(u);
        }
    }
};

void DFS(Graph *graph, int source, vector<bool> &visited, vector<int> &result)
{
    visited[source] = true;
    result.push_back(source);
    for (auto itr = graph->adj[source].begin(); itr != graph->adj[source].end(); itr++)
    {
        if (!visited[*itr])
        {
            DFS(graph, *itr, visited, result);
        }
    }
}
vector<int> DFS(Graph *graph)
{
    int source = 0;
    vector<bool> visited(graph->size, false);
    vector<int> result;

    int count = 0;
    for (int i = 0; i < graph->size; i++)
    {
        if (!visited[i])
        {
            count++;
            DFS(graph, i, visited, result);
        }
    }

    cout << count << "completed component" << endl;
    return result;
}

vector<int> BFS(Graph *graph)
{
    int source = 0;
    vector<bool> visited(graph->size, false);
    vector<int> result;

    list<int> Q;
    visited[source] = true;
    Q.push_back(source);
    while (!Q.empty())
    {
        source = Q.front();
        Q.pop_back();
        result.push_back(source);

        for (auto itr = graph->adj[source].begin(); itr != graph->adj[source].end(); itr++)
        {
            if (!visited[*itr])
            {
                visited[*itr] = true;
                Q.push_back(*itr);
            }
        }
    }

    return result;
}

bool isCyclic(Graph *graph, int source, vector<bool> &visited, bool &result, int parent)
{
    visited[source] = true;
    for (auto itr = graph->adj[source].begin(); itr != graph->adj[source].end(); itr++)
    {
        if (visited[*itr] && *itr != parent)
        {
            result = true;
            break;
        }
        if (!visited[*itr] && *itr != parent)
        {
            if (isCyclic(graph, *itr, visited, result, source))
            {
                break;
            }
        }
    }
    return result;
}
bool isCyclic(Graph *graph)
{
    int source = 0;
    vector<bool> visited(graph->size, false);
    bool result;

    for (int i = 0; i < graph->size; i++)
    {
        if (!visited[i])
        {
            if (isCyclic(graph, i, visited, result, -1))
            {
                break;
            }
        }
    }

    return result;
}

bool isCyclicDirected(Graph *graph, int source, vector<bool> &visited, bool &result, unordered_map<int, bool> &path)
{
    visited[source] = true;

    for (auto itr = graph->adj[source].begin(); itr != graph->adj[source].end(); itr++)
    {
        if (visited[*itr] && path[*itr] == true)
        {
            path[*itr] = false;
            result = true;
            break;
        }
        if (!visited[*itr] && path[*itr] == false)
        {
            path[*itr] = true;
            if (isCyclicDirected(graph, *itr, visited, result, path))
            {
                path[*itr] = false;
                break;
            }
        }
        path[*itr] = false;
    }
    path[source] = false;
    return result;
}
bool isCyclicDirected(Graph *graph)
{
    int source = 0;
    vector<bool> visited(graph->size, false);
    unordered_map<int, bool> path;
    for (int i = 0; i < graph->size; i++)
    {
        path[i] = false;
    }
    bool result;

    for (int i = 0; i < graph->size; i++)
    {
        if (!visited[i])
        {
            path[i] = true;
            isCyclicDirected(graph, i, visited, result, path);
        }
    }

    return result;
}

int main()
{
    Graph *graph;
    graph = new Graph(5);
    graph->addEdge(1, 2);
    graph->addEdge(2, 3);
    graph->addEdge(3, 0);
    graph->addEdge(3, 4);
    graph->addEdge(4, 1);

    cout << isCyclicDirected(graph) << endl;
    return 0;
}
// g++ file.cpp -o
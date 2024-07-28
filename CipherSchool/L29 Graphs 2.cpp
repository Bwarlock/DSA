#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    DisjointSet(int N) {}

    int Find(int u)
    {
        return 0;
    }

    void Union(int u, int v) {}
};

class Edge
{
public:
    int source;
    int destination;
    double weight;
    Edge(int source,
         int destination,
         double weight) : source(source), destination(destination), weight(weight) {}
};

bool comparator(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

class Graph
{
public:
    int V;
    vector<Edge> edges;

    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int u, int v, double w)
    {
        this->edges.push_back(Edge(u, v, w));
    }
};

pair<vector<Edge>, double> kruskalMinimumSpanningTree(Graph *graph)
{
    vector<Edge> result;
    double minWeight = 0.0;
    sort(graph->edges.begin(), graph->edges.end(), comparator);

    // still need to study
    DisjointSet ds(graph->V);

    for (auto itr = graph->edges.begin(); itr != graph->edges.end(); itr++)
    {
        int u = itr->source, v = itr->destination;
        int parentU = ds.Find(u);
        int parentV = ds.Find(v);

        if (parentU != parentV)
        {
            // The u and v aren't connected according to Union Find
            minWeight += itr->weight;
            result.push_back(*itr);
            ds.Union(u, v);
        }
    }
    return {result, minWeight};
}

class GraphList
{

public:
    bool undirected;
    int size;
    list<int> *adj;

    GraphList(int V, bool undirected = false)
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

void topologicalSort(GraphList *graph, int source, vector<bool> &visited, vector<int> &result)
{
    visited[source] = true;
    for (auto itr = graph->adj[source].begin(); itr != graph->adj[source].end(); itr++)
    {
        if (!visited[*itr])
        {
            topologicalSort(graph, *itr, visited, result);
        }
    }
    result.push_back(source);
}
vector<int> topologicalSort(GraphList *graph)
{
    int source = 0;
    vector<bool> visited(graph->size, false);
    vector<int> result;

    for (int i = 0; i < graph->size; i++)
    {
        if (!visited[i])
        {
            topologicalSort(graph, i, visited, result);
        }
    }
    reverse(result.begin(), result.end());

    return result;
}

// Topological sort Question COURSE Scheduling
// alien dictionary Question
// floyd warshall all nodes to all other nodes
// bellman ford

class GraphMarix
{
public:
    int size;
    vector<vector<int>> matrix;
    GraphMarix(int size)
    {
        this->size = size;
        for (int i = 0; i < this->size; i++)
        {
            vector<int> temp(this->size, 0);
            this->matrix.push_back(temp);
        }
    }

    void addEdge(int u, int v, int w)
    {
        this->matrix[u][v] = w;
        this->matrix[v][u] = w;
    }
};

vector<int> dijkastra(GraphMarix *graph, int src)
{
    vector<bool> visited(graph->size, false);
    vector<int> result(graph->size, INT_MAX);
    result[src] = 0;

    for (int o = 0; o < graph->size - 1; o++)
    {
        int min_cost = INT_MAX, min_index;
        for (int i = 0; i < graph->size; i++)
        {
            if (!visited[i] && result[i] <= min_cost)
            {
                min_index = i;
                min_cost = result[i];
            }
        }

        visited[min_index] = true;
        for (int i = 0; i < graph->size; i++)
        {
            if (!visited[i] && result[min_index] != INT_MAX && graph->matrix[min_index][i] != 0)
            {
                result[i] = min(result[i], result[min_index] + graph->matrix[min_index][i]);
            }
        }
    }

    return result;
}

// not complete
vector<vector<int>> floydWarshal_MultiSourceShortestPath(Graph *graph)
{
    vector<vector<int>> result;

    for (int i = 0; i < graph->V; i++)
    {
        for (int k = 0; k < graph->V; k++)
        {
            if (k == i)
            {
                result[i][k] = 0;
            }
            else
            {
                result[i][k] = INT_MAX;
            }
        }
    }

    for (Edge edge : graph->edges)
    {
        result[edge.source][edge.destination] = edge.weight;
    }
    for (Edge edge : graph->edges)
    {
        result[edge.source][edge.destination] = edge.weight;
        for (Edge edge2 : graph->edges)
        {
            for (Edge edge3 : graph->edges)
            {
                if (edge2.source == edge.source && edge3.destination == edge.destination)
                {
                    if (result[edge2.source][edge2.destination] != INT_MAX && result[edge3.source][edge3.destination] != INT_MAX && result[edge2.source][edge2.destination] != 0 && result[edge3.source][edge3.destination] != 0)
                    {
                        result[edge.source][edge.destination] = min(result[edge.source][edge.destination], )
                    }
                }
            }
        }
    }
    return result;
}

int main()
{
    GraphList *graph;
    graph = new GraphList(5);
    graph->addEdge(1, 2);
    graph->addEdge(2, 3);
    graph->addEdge(3, 0);
    graph->addEdge(3, 4);

    // for (int i : topologicalSort(graph))
    // {
    //     cout << i << endl;
    // }

    GraphMarix *graph2;
    graph2 = new GraphMarix(5);
    graph2->addEdge(1, 2, 1);
    graph2->addEdge(2, 3, 3);
    graph2->addEdge(3, 0, 5);
    graph2->addEdge(3, 4, 9);
    for (int i : dijkastra(graph2, 1))
    {
        cout << i << endl;
    }

    return 0;
}
// g++ file.cpp -o
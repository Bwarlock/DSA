// Alice and Bob have an undirected graph of n nodes and three types of edges:

// Type 1: Can be traversed by Alice only.
// Type 2: Can be traversed by Bob only.
// Type 3: Can be traversed by both Alice and Bob.
// Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

// Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

#include <bits/stdc++.h>
using namespace std;

int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
{
    // Not exaclty hard , didnt know union find
    class UnionFind
    {
    public:
        vector<int> parent, size;
        int components;
        UnionFind(int n)
        {
            components = n;
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for (int i = 0; i <= n; ++i)
            {
                parent[i] = i;
            }
        }

        int find(int x)
        {
            if (parent[x] != x)
            {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        bool unite(int x, int y)
        {
            int rootX = find(x), rootY = find(y);
            if (rootX == rootY)
                return false;
            if (size[rootX] < size[rootY])
                swap(rootX, rootY);
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            components--;
            return true;
        }

        bool isConnected()
        {
            return components == 1;
        }
    };

    UnionFind alice(n), bob(n);
    int edgesRequired = 0;

    for (const auto &edge : edges)
    {
        if (edge[0] == 3)
        {
            if (alice.unite(edge[1], edge[2]) | bob.unite(edge[1], edge[2]))
            {
                edgesRequired++;
            }
        }
    }

    for (const auto &edge : edges)
    {
        if (edge[0] == 1)
        {
            if (alice.unite(edge[1], edge[2]))
            {
                edgesRequired++;
            }
        }
        else if (edge[0] == 2)
        {
            if (bob.unite(edge[1], edge[2]))
            {
                edgesRequired++;
            }
        }
    }

    if (alice.isConnected() && bob.isConnected())
    {
        return edges.size() - edgesRequired;
    }

    return -1;
}

int main()
{
    vector<vector<int>> edges = {{1, 1, 2}, {2, 1, 2}, {3, 1, 2}};

    cout << maxNumEdgesToRemove(2, edges) << endl;

    return 0;
}
// g++ file.cpp -o
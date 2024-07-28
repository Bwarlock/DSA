// You are given a positive integer k. You are also given:

// a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
// a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
// The two arrays contain integers from 1 to k.

// You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

// The matrix should also satisfy the following conditions:

// The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
// The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
// Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<vector<int>> &edges, int n)
{
    vector<vector<int>> adj(n + 1);
    vector<int> order;
    // 0: not visited, 1: visiting, 2: visited
    vector<int> visited(n + 1, 0);
    bool hasCycle = false;

    // Build adjacency list
    for (auto &x : edges)
    {
        adj[x[0]].push_back(x[1]);
    }

    // Perform DFS for each node
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, adj, visited, order, hasCycle);
            // Return empty if cycle detected
            if (hasCycle)
                return {};
        }
    }
    // Reverse to get the correct order
    reverse(order.begin(), order.end());
    return order;
}

void dfs(int node, vector<vector<int>> &adj, vector<int> &visited,
         vector<int> &order, bool &hasCycle)
{
    visited[node] = 1; // Mark node as visiting
    for (int neighbor : adj[node])
    {
        if (visited[neighbor] == 0)
        {
            dfs(neighbor, adj, visited, order, hasCycle);
            // Early exit if a cycle is detected
            if (hasCycle)
                return;
        }
        else if (visited[neighbor] == 1)
        {
            // Cycle detected
            hasCycle = true;
            return;
        }
    }
    // Mark node as visited
    visited[node] = 2;
    // Add node to the order
    order.push_back(node);
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
{
    // havent studied this yet
    vector<int> orderRows = topoSort(rowConditions, k);
    vector<int> orderColumns = topoSort(colConditions, k);

    if (orderRows.empty() or orderColumns.empty())
        return {};

    vector<vector<int>> matrix(k, vector<int>(k, 0));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (orderRows[i] == orderColumns[j])
            {
                matrix[i][j] = orderRows[i];
            }
        }
    }
    return matrix;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
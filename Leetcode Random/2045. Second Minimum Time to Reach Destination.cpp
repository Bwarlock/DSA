// A city is represented as a bi-directional connected graph with n vertices where each vertex is labeled from 1 to n (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. The time taken to traverse any edge is time minutes.

// Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. All signals change at the same time. You can enter a vertex at any time, but can leave a vertex only when the signal is green. You cannot wait at a vertex if the signal is green.

// The second minimum value is defined as the smallest value strictly larger than the minimum value.

// For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.
// Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.

// Notes:

// You can go through any vertex any number of times, including 1 and n.
// You can assume that when the journey starts, all signals have just turned green.

#include <bits/stdc++.h>
using namespace std;

int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
{
    vector<vector<int>> graph(n + 1);
    int edgeSize = edges.size();

    for (int i = 0; i < edgeSize; i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    queue<pair<int, int>> Q;
    vector<int> dist1(n + 1, -1), dist2(n + 1, -1);
    Q.push({1, 1});
    dist1[1] = 0;

    while (!Q.empty())
    {
        pair<int, int> temp = Q.front();
        Q.pop();

        int timeTaken = temp.second == 1 ? dist1[temp.first] : dist2[temp.first];

        if ((timeTaken / change) % 2)
        {
            timeTaken = change * (timeTaken / change + 1) + time;
        }
        else
        {
            timeTaken = timeTaken + time;
        }

        for (int &neighbor : graph[temp.first])
        {
            if (dist1[neighbor] == -1)
            {
                dist1[neighbor] = timeTaken;
                Q.push({neighbor, 1});
            }
            else if (dist2[neighbor] == -1 && dist1[neighbor] != timeTaken)
            {
                if (neighbor == n)
                    return timeTaken;
                dist2[neighbor] = timeTaken;
                Q.push({neighbor, 2});
            }
        }
    }
    return 0;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
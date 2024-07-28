// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

#include <bits/stdc++.h>
using namespace std;

void floyd(int n, vector<vector<int>> &distanceMatrix)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                distanceMatrix[i][j] =
                    min(distanceMatrix[i][j],
                        distanceMatrix[i][k] + distanceMatrix[k][j]);
            }
        }
    }
}

int getCityWithFewestReachable(int n,
                               const vector<vector<int>> &distanceMatrix,
                               int distanceThreshold)
{
    int cityWithFewestReachable = -1;
    int fewestReachableCount = n;

    for (int i = 0; i < n; i++)
    {
        int reachableCount = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (distanceMatrix[i][j] <= distanceThreshold)
            {
                reachableCount++;
            }
        }
        if (reachableCount <= fewestReachableCount)
        {
            fewestReachableCount = reachableCount;
            cityWithFewestReachable = i;
        }
    }
    return cityWithFewestReachable;
}

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{

    const int INF = 1e9 + 7;
    vector<vector<int>> distanceMatrix(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++)
    {
        distanceMatrix[i][i] = 0;
    }

    for (const auto &edge : edges)
    {
        int start = edge[0];
        int end = edge[1];
        int weight = edge[2];
        distanceMatrix[start][end] = weight;
        distanceMatrix[end][start] = weight;
    }

    floyd(n, distanceMatrix);
    return getCityWithFewestReachable(n, distanceMatrix, distanceThreshold);
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
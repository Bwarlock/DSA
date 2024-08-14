// An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

// Given the grid grid represented as a string array, return the number of regions.

// Note that backslash characters are escaped, so a '\' is represented as '\\'.

#include <bits/stdc++.h>
using namespace std;

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

void countCycle(GraphMarix *graph, int &result, vector<bool> &visited, const int &len, int current, int parent)
{
    for (int i = 0; i < len; i++)
    {
        if (graph->matrix[current][i] && visited[i] && i != parent && i == 0)
        {
            cout << current << "going" << i << "p" << parent << endl;
            result++;
            return;
        }
        if (graph->matrix[current][i] && !visited[i])
        {
            visited[i] = true;
            countCycle(graph, result, visited, len, i, current);
            visited[i] = false;
        }
    }
}

int regionsBySlashes(vector<string> &grid)
{
    // tfuck was this shit
    // how did they solve this using disjoint set
    int result = 0;
    int len = grid.size();
    vector<vector<int>> edgeIndex;
    GraphMarix *grph = new GraphMarix((len + 1) * (len + 1));

    for (int i = 0; i < len + 1; i++)
    {
        vector<int> temp = {};
        for (int j = 0; j < len + 1; j++)
        {
            cout << j + i * (len + 1) << " ";
            temp.push_back(j + (i * (len + 1)));
        }
        edgeIndex.push_back(temp);
        cout << endl;
    }

    // Connect Outside Box
    for (int i = 0; i < len; i++)
    {
        // top
        cout << edgeIndex[0][i] << edgeIndex[0][i + 1] << endl;
        grph->addEdge(edgeIndex[0][i], edgeIndex[0][i + 1], 1);
    }

    for (int i = 0; i < len; i++)
    {
        // left
        cout << "hi" << edgeIndex[i][0] << edgeIndex[i + 1][0] << endl;
        grph->addEdge(edgeIndex[i][0], edgeIndex[i + 1][0], 1);
    }

    for (int i = 0; i < len; i++)
    {
        // bottom
        cout << edgeIndex[len][i] << edgeIndex[len][i + 1] << endl;
        grph->addEdge(edgeIndex[len][i], edgeIndex[len][i + 1], 1);
    }

    for (int i = 0; i < len; i++)
    {
        // right
        cout << edgeIndex[i][len] << edgeIndex[i + 1][len] << endl;
        grph->addEdge(edgeIndex[i][len], edgeIndex[i + 1][len], 1);
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            // if (grid[i][j] == ' ')
            // {
            // }
            if (grid[i][j] == '/')
            {
                grph->addEdge(edgeIndex[i][j + 1], edgeIndex[i + 1][j], 1);
            }
            if (grid[i][j] == '\\')
            {
                grph->addEdge(edgeIndex[i][j], edgeIndex[i + 1][j + 1], 1);
            }
        }
    }
    vector<bool> visited(grph->size, false);
    visited[0] = true;
    countCycle(grph, result, visited, grph->size, 0, 0);
    return result;
}

int main()
{
    vector<string> grid = {"/\\", "\\/"};
    cout << regionsBySlashes(grid) << endl;
    return 0;
}
// g++ file.cpp -o
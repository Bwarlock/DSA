// unique-path-3 , cover every room before reaching the end
#include <bits/stdc++.h>
using namespace std;

vector<int> Xmoves = {0, 0, 1, -1};
vector<int> Ymoves = {1, -1, 0, 0};

bool isSafe(vector<vector<int>> &maze, int x, int y, int R, int C, vector<vector<bool>> &visited)
{
    return ((x >= 0 && x < R && y >= 0 && y < C) && (!visited[x][y]) && (maze[x][y] == 1));
    // within bounds     &&     not visited     &&    no cross(0) on maze
}

void recursionRatInMaze(vector<vector<int>> &maze, int x, int y, int R, int C, vector<vector<bool>> &visited, vector<vector<vector<bool>>> &result)
{
    if (x == R - 1 && y == C - 1)
    {
        visited[x][y] = true;
        for (int i = 0; i < R; i++)
        {
            for (int k = 0; k < C; k++)
            {
                if (maze[i][k] == 1 && !visited[i][k])
                {
                    return;
                }
            }
        }
        result.push_back(visited);
        return;
    }
    if (isSafe(maze, x, y, R, C, visited))
    {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int nextx = x + Xmoves[i];
            int nexty = y + Ymoves[i];
            recursionRatInMaze(maze, nextx, nexty, R, C, visited, result);
        }
        visited[x][y] = false;
    }
}

vector<vector<vector<bool>>> ratInMaze(vector<vector<int>> maze)
{

    int R = maze.size();
    if (R < 1)
    {
        return {};
    }
    int C = maze[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C));
    vector<vector<vector<bool>>> result{};
    if (maze[R - 1][C - 1] == 0 || maze[0][0] == 0)
    {
        return {};
    }

    recursionRatInMaze(maze, 0, 0, R, C, visited, result);
    return result;
}

int main()
{
    vector<vector<int>> maze = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {0, 0, 1}};
    vector<vector<vector<bool>>> result = ratInMaze(maze);
    for (vector<vector<bool>> i : result)
    {
        for (vector<bool> j : i)
        {
            for (bool k : j)
            {
                cout << k << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << result.size() << " Ways to Do it" << endl;
    return 0;
}
// g++ file.cpp -o
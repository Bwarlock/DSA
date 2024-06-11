#include <bits/stdc++.h>
using namespace std;

vector<int> Xmoves = {0, 0, 1, -1};
vector<int> Ymoves = {1, -1, 0, 0};

bool isSafe(vector<vector<int>> &maze, int x, int y, int R, int C, vector<vector<bool>> &visited)
{
    return ((x >= 0 && x < R && y >= 0 && y < C) && (!visited[x][y]) && (maze[x][y] == 1));
    // within bounds     &&     not visited     &&    no cross(0) on maze
}

bool recursionRatInMaze(vector<vector<int>> &maze, int x, int y, int R, int C, vector<vector<bool>> &visited)
{
    if (x == R - 1 && y == C - 1)
    {
        visited[x][y] = true;
        return true;
    }
    if (isSafe(maze, x, y, R, C, visited))
    {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int nextx = x + Xmoves[i];
            int nexty = y + Ymoves[i];
            if (recursionRatInMaze(maze, nextx, nexty, R, C, visited))
            {
                return true;
            };
        }
        visited[x][y] = false;
    }
    return false;
}

bool ratInMaze(vector<vector<int>> maze)
{

    int R = maze.size();
    if (R < 1)
    {
        return true;
    }
    int C = maze[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C));

    if (maze[R - 1][C - 1] == 0 || maze[0][0] == 0)
    {
        return false;
    }
    return recursionRatInMaze(maze, 0, 0, R, C, visited);
}

int main()
{
    vector<vector<int>> maze = {{1, 0, 1}, {1, 0, 1}, {1, 0, 1}};

    cout << ratInMaze(maze) << endl;
    return 0;
}
// g++ file.cpp -o
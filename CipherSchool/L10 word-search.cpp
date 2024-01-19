#include <bits/stdc++.h>
using namespace std;

// All possible searches

vector<int> Xmoves = {0, 0, 1, -1};
vector<int> Ymoves = {1, -1, 0, 0};

bool isSafe(vector<vector<char>> &board, vector<vector<bool>> &visited, int x, int y, int R, int C, int index, string &word)
{
    return ((x >= 0 && x < R && y >= 0 && y < C) && (!visited[x][y]) && (board[x][y] == word[index]));
}

void recursionWordSearch(vector<vector<char>> &board, vector<vector<bool>> &visited, int x, int y, int R, int C, int nextIndex, string &word, vector<vector<vector<bool>>> &result)
{
    if (nextIndex >= word.size())
    {
        visited[x][y] = true;
        result.push_back(visited);
        visited[x][y] = false;
        return;
    }
    else
    {
        visited[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int nextx = x + Xmoves[i];
            int nexty = y + Ymoves[i];
            if (isSafe(board, visited, nextx, nexty, R, C, nextIndex, word))
            {
                recursionWordSearch(board, visited, nextx, nexty, R, C, nextIndex + 1, word, result);
            }
        }

        // Backtracking
        visited[x][y] = false;
        return;
    }
}

vector<vector<vector<bool>>> wordSearch(vector<vector<char>> &board, string word)
{
    if (word == "")
    {
        return {};
    }

    int R = board.size();
    if (R == 0)
    {
        return {};
    }

    int C = board[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    vector<vector<vector<bool>>> result;

    for (int i = 0; i < R; i++)
    {
        for (int k = 0; k < C; k++)
        {
            if (board[i][k] == word[0])
            {
                recursionWordSearch(board, visited, i, k, R, C, 1, word, result);
            }
        }
    }
    return result;
}

int main()
{
    vector<vector<char>> board = {{'a', 'b', 'c'}, {'a', 'b', 'c'}, {'a', 'b', 'c'}};
    vector<vector<vector<bool>>> result = wordSearch(board, "abc");
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
    cout << result.size() << " Possible position for Word" << endl;
    return 0;
}
// g++ file.cpp -o
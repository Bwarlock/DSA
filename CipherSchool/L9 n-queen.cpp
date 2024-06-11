#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<bool>> &Chess, int r, int c, int N)
{
    for (int y = c; y >= 0; y--)
    {
        if (Chess[r][y])
        {
            return false;
        }
    }

    for (int y = c, x = r; x >= 0 && y >= 0; x--, y--)
    {
        if (Chess[x][y])
        {
            return false;
        }
    }

    for (int y = c, x = r; x < N && y >= 0; x++, y--)
    {
        if (Chess[x][y])
        {
            return false;
        }
    }
    return true;
}

void recursionNQueen(vector<vector<bool>> &Chess, int c, int N, vector<vector<vector<bool>>> &result)
{
    if (c == N)
    {
        result.push_back(Chess);
        return;
    }

    // choose Row for current Column's Queen
    for (int r = 0; r < N; r++)
    {
        if (isSafe(Chess, r, c, N))
        {
            Chess[r][c] = true;
            recursionNQueen(Chess, c + 1, N, result);
            Chess[r][c] = false;
        }
    }
}

vector<vector<vector<bool>>> NQueen(int N)
{
    if (N < 4)
    {
        return {};
    }
    vector<vector<bool>> Chess(N, vector<bool>(N, false));
    vector<vector<vector<bool>>> result;
    recursionNQueen(Chess, 0, N, result);
    return result;
}

int main()
{
    int n = 5;
    vector<vector<vector<bool>>> result = NQueen(n);
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
    return 0;
}
// g++ file.cpp -o
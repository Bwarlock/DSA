// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

// Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

// Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

#include <bits/stdc++.h>
using namespace std;

bool checkWindow(const int &i, const int &j, const int &k, vector<vector<int>> &grid)
{
    unordered_map<int, bool> checkMap;
    for (int u = k; u <= k + 2; u++)
    {
        for (int v = i; v <= j; v++)
        {
            if (grid[u][v] < 1 || grid[u][v] > 9 || checkMap.find(grid[u][v]) != checkMap.end())
            {
                checkMap.clear();
                return false;
            }
            checkMap[grid[u][v]] = true;
        }
    }
    checkMap.clear();
    // Horizontal
    if (grid[k + 1][i] + grid[k + 1][i + 1] + grid[k + 1][j] != 15)
    {
        return false;
    }

    if (grid[k + 2][i] + grid[k + 2][i + 1] + grid[k + 2][j] != 15)
    {
        return false;
    }
    // Down Vertical
    if (grid[k][i] + grid[k + 1][i] + grid[k + 2][i] != 15)
    {
        return false;
    }
    if (grid[k][i + 1] + grid[k + 1][i + 1] + grid[k + 2][i + 1] != 15)
    {
        return false;
    }
    if (grid[k][j] + grid[k + 1][j] + grid[k + 2][j] != 15)
    {
        return false;
    }
    // Diagonal
    if (grid[k][i] + grid[k + 1][i + 1] + grid[k + 2][j] != 15)
    {
        return false;
    }
    if (grid[k + 2][i] + grid[k + 1][i + 1] + grid[k][j] != 15)
    {
        return false;
    }
    return true;
}
int numMagicSquaresInside(vector<vector<int>> &grid)
{
    int lenRow = grid.size();
    int lenCol = grid[0].size();
    if (lenRow < 3 || lenCol < 3)
    {
        return 0;
    }

    int i = 0;
    int j = 2;
    int window = 0;
    int result = 0;
    for (int k = 0; k < lenRow - 2; k++)
    {
        i = 0;
        j = 2;
        int window = grid[k][0] + grid[k][1] + grid[k][2];
        while (j < lenCol)
        {
            if (i != 0)
            {

                window += grid[k][j] - grid[k][i - 1];
            }
            if (window == 15)
            {
                if (checkWindow(i, j, k, grid))
                {
                    result++;
                }
            }
            i++;
            j++;
        }
    }
    return result;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
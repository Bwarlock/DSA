#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        int size = rows * cols, currentRow = rStart, currentCol = cStart;
        vector<vector<int>> result;
        vector<vector<int>> visited(rows + 2, vector<int>(cols + 2, 0));
        while (size > 0)
        {
            // Right
            do
            {
                if (currentRow >= 0 && currentCol >= 0)
                {
                    result.push_back({currentRow, currentCol});
                    visited[currentRow + 1][currentCol + 1] = size;
                    size--;
                }
                currentCol++;
            } while (visited[currentRow + 1 + 1][currentCol + 1] > 0);
            if (size <= 0)
            {
                break;
            }

            // Down
            do
            {
                if (currentCol < cols && currentRow >= 0)
                {
                    result.push_back({currentRow, currentCol});
                    visited[currentRow + 1][currentCol + 1] = size;
                    size--;
                }
                currentRow++;
            } while (visited[currentRow + 1][currentCol + 1 - 1] > 0);
            if (size <= 0)
            {
                break;
            }

            // Left
            do
            {
                if (currentRow < rows && currentCol < cols)
                {
                    result.push_back({currentRow, currentCol});
                    visited[currentRow + 1][currentCol + 1] = size;
                    size--;
                }
                currentCol--;
            } while (visited[currentRow + 1 - 1][currentCol + 1] > 0);
            if (size <= 0)
            {
                break;
            }

            // Top
            do
            {
                if (currentCol >= 0 && currentRow < rows)
                {
                    result.push_back({currentRow, currentCol});
                    visited[currentRow + 1][currentCol + 1] = size;
                    size--;
                }
                currentRow--;
            } while (visited[currentRow + 1][currentCol + 1 + 1] > 0);
        }
        return result;
    }
};

int main()
{

    for (vector<int> i : Solution::spiralMatrixIII(5, 6, 1, 4))
    {
        cout << "[ ";
        for (int k : i)
        {
            cout << k << " ";
        }
        cout << " ]" << endl;
    }
    cout << endl;
    return 0;
}
// g++ file.cpp -o
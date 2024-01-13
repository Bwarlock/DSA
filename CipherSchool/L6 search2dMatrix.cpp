#include <bits/stdc++.h>
using namespace std;

// Time : m+n
vector<int> search2dMatrix(vector<vector<int>> matrix, int x)
{
    int row = 0, col = matrix[0].size() - 1;
    if (matrix.size() > 0)
    {
        while (row < matrix.size() && col > -1)
        {
            if (matrix[row][col] == x)
            {
                return {row, col};
            }
            else if (matrix[row][col] < x)
            {
                row++;
            }
            else if (x < matrix[row][col])
            {
                col--;
            }
        }
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> matrix = {{1, 0, 3}, {4, 5, 6}, {7, 5, 9}, {0, 11, 12}};
    vector<int> result = search2dMatrix(matrix, 5);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
// g++ file.cpp -o
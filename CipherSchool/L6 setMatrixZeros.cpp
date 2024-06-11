#include <bits/stdc++.h>
using namespace std;

// DP
// Time : O(2(m*n)) as compared to brute force O((m*n)*(m+n))
// Space : O(m+n)
vector<vector<int>> setMatrixZeros(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if (n > 0)
    {
        vector<bool> row(n), col(m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> ques = {{1, 0, 3}, {4, 5, 6}, {7, 8, 9}, {0, 11, 12}};
    vector<vector<int>> matrix = setMatrixZeros(ques);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// g++ file.cpp -o
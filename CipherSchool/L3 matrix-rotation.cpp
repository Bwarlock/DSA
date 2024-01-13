#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixRotation(vector<vector<int>> a)
{
    int n = a.size() - 1;
    if (n > -1)
    {
        int m = a.at(0).size();
        vector<vector<int>> result(m, vector<int>(a.size()));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // transpose [j][i] = [i][j]
                // and then swap [j][i - n]
                // |0-2| = 2
                // |1-2| = 1
                // |2-2| = 0
                result[j][abs(i - n)] = a.at(i).at(j);
            }
        }
        return result;
    }
    else
    {
        return {};
    }
}

int main()
{
    vector<vector<int>> ques = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    vector<vector<int>> matrix = matrixRotation(ques);
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
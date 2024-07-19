// Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

// A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

#include <bits/stdc++.h>
using namespace std;

vector<int> luckyNumbers(const vector<vector<int>> &matrix)
{
    int rowLength = matrix.size();
    int colLength = matrix[0].size();
    if (rowLength == 1)
    {
        return {*min_element(matrix[0].begin(), matrix[0].end())};
    }
    if (colLength == 1)
    {
        int high = 0;
        for (vector<int> i : matrix)
        {
            if (high < i[0])
            {
                high = i[0];
            }
        }
        return {high};
    }
    vector<int> result;
    vector<int> luckyRow(rowLength);
    vector<int> luckyCol(colLength, 0);

    for (int i = 0; i < rowLength; i++)
    {

        luckyRow[i] = matrix[i][0];
        for (int k = 0; k < colLength; k++)
        {
            if (luckyRow[i] > matrix[i][k])
            {
                luckyRow[i] = matrix[i][k];
            }
            if (luckyCol[k] < matrix[i][k])
            {
                luckyCol[k] = matrix[i][k];
            }
        }
    }

    for (int i = 0; i < rowLength; i++)
    {
        for (int k = 0; k < colLength; k++)
        {
            if (matrix[i][k] == luckyRow[i] && matrix[i][k] == luckyCol[k])
            {
                result.push_back(matrix[i][k]);
                break;
            }
        }
    }

    return result;
}

int main()
{
    cout << luckyNumbers({{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}})[0] << endl;
    return 0;
}
// g++ file.cpp -o
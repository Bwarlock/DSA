// You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements in the ith row and colSum[j] is the sum of the elements of the jth column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.

// Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.

// Return a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at least one matrix that fulfills the requirements exists.
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
{
    int rowLendth = rowSum.size();
    int colLength = colSum.size();
    vector<vector<int>> result(rowLendth, vector<int>(colLength, 0));
    for (int i = 0; i < rowLendth; i++)
    {
        for (int k = 0; k < colLength; k++)
        {
            int temp = min(rowSum[i], colSum[k]);
            rowSum[i] -= temp;
            colSum[k] -= temp;
            result[i][k] = temp;
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
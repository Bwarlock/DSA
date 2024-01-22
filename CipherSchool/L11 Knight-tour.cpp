
#include <bits/stdc++.h>
using namespace std;

vector<int> rowMoves = {-2, -2, 2, 2, -1, 1, -1, 1};
vector<int> colMoves = {-1, 1, -1, 1, -2, -2, 2, 2};

bool isSafe(vector<vector<int>> &board, int rowSize, int colSize, int row, int col)
{
    return ((row < rowSize && row >= 0 && col < colSize && col >= 0) && (board[row][col] == 0));
}

bool recurseKnightTour(vector<vector<int>> &board, int rowSize, int colSize, int row, int col, int count)
{
    if (count > rowSize * colSize)
    {
        return true;
    }

    for (int i = 0; i < 8; i++)
    {
        int nextRow = row + rowMoves[i];
        int nextCol = col + colMoves[i];
        if (isSafe(board, rowSize, colSize, nextRow, nextCol))
        {
            // cout << nextRow << nextCol << count << endl;
            board[nextRow][nextCol] = count;
            if (recurseKnightTour(board, rowSize, colSize, nextRow, nextCol, count + 1))
            {
                return true;
            }
            board[nextRow][nextCol] = 0;
        }
    }
    return false;
}

bool knightTour(vector<vector<int>> &board, int rowSize, int colSize, int rowStart, int colStart)
{
    board[rowStart][colStart] = 1;
    if (rowSize == 1 && colSize == 1)
    {
        return true;
    }
    if (rowSize < 4 || colSize < 4)
    {
        return false;
    }
    if (recurseKnightTour(board, rowSize, colSize, rowStart, colStart, 2))
    {
        return true;
    }
    else
    {

        return false;
    }
}

int main()
{
    // takes too long on 8 * 8
    int rowSize = 7, colSize = 7, rowStart = 0, colStart = 0;
    vector<vector<int>> board(rowSize, vector<int>(colSize, 0));
    if (knightTour(board, rowSize, colSize, rowStart, colStart))
    {
        for (vector<int> i : board)
        {
            for (int k : i)
            {
                cout << k << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << false;
    }
    return 0;
}
// g++ file.cpp -o
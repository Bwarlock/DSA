#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &sudoku, int size, int row, int col, int boxSize, int fill)
{
    int rowStart = row - row % boxSize;
    int colStart = col - col % boxSize;

    // Box Check
    for (int i = 0; i < boxSize; i++)
    {
        for (int k = 0; k < boxSize; k++)
        {
            if (sudoku[i + rowStart][k + colStart] == fill)
            {
                return false;
            }
        }
    }

    // Row Check
    for (int i = 0; i < size; i++)
    {
        if (sudoku[row][i] == fill)
        {
            return false;
        }
    }

    // Column Check
    for (int i = 0; i < size; i++)
    {
        if (sudoku[i][col] == fill)
        {
            return false;
        }
    }

    // Diagonal Check
    if (row == col)
    {
        for (int i = 0, k = 0; i < size, k < size; i++, k++)
        {
            if (sudoku[i][k] == fill)
            {
                return false;
            }
        }
    }
    if (row + col + 1 == size)
    {
        for (int i = 0, k = size - 1; i < size, k >= 0; i++, k--)
        {
            if (sudoku[i][k] == fill)
            {
                return false;
            }
        }
    }

    return true;
}

bool recurseSudoku(vector<vector<int>> &sudoku, int size, int row, int col)
{
    int flag = false;
    // Check Empty Cell
    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size; k++)
        {
            if (sudoku[i][k] == 0)
            {
                row = i;
                col = k;
                flag = true;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    if (!flag)
    {
        // If no empy cell
        return true;
    }

    for (int i = 1; i <= size; i++)
    {
        if (isSafe(sudoku, size, row, col, int(sqrt(size)), i))
        {

            sudoku[row][col] = i;
            if (recurseSudoku(sudoku, size, row, col))
            {
                return true;
            }
            // Backtrack and try another
            sudoku[row][col] = 0;
        }
    }

    // No value Worked
    return false;
}

bool sudokuSolver(vector<vector<int>> &sudoku, int size)
{
    if (size < 1)
    {
        return true;
    }
    if (int(sqrt(size)) * int(sqrt(size)) != size)
    {
        return false;
    }
    if (recurseSudoku(sudoku, size, 0, 0))
    {
        return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> sudoku = {
        {0, 1, 0, 0},
        {2, 3, 0, 0},
        {1, 4, 0, 0},
        {3, 0, 0, 0}};
    int size = sudoku.size();
    if (sudokuSolver(sudoku, size))
    {
        for (vector<int> i : sudoku)
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
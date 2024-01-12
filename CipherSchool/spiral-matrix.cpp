#include <bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> a)
{
    int top = 0, bottom = a.size() - 1, left = 0, right = a.at(0).size() - 1;
    vector<int> result;
    if (bottom > -1)
    {
        while (top <= bottom && left <= right)
        {

            for (int i = left; i <= right; i++)
            {
                result.push_back(a.at(top).at(i));
            }
            top++;

            for (int i = top; i <= bottom; i++)
            {
                result.push_back(a.at(i).at(right));
            }
            right--;
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    result.push_back(a.at(bottom).at(i));
                }
                bottom--;
            }
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    result.push_back(a.at(i).at(left));
                }
                left++;
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
    vector<vector<int>> ques = {{2, 4, 6}, {8, 10, 12}};
    for (int num : spiralMatrix(ques))
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
// g++ file.cpp -o
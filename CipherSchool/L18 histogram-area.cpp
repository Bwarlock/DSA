#include <bits/stdc++.h>
using namespace std;

// O(n) O(n)
vector<int> nextSmallerElementLeft(vector<int> &nums)
{
    int size = nums.size();
    stack<int> stk;
    vector<int> result(size);

    for (int i = 0; i < size; i++)
    {
        while (!stk.empty() && nums[i] <= nums[stk.top()])
        {
            stk.pop();
        }
        if (stk.empty())
        {
            result[i] = -1 + 1;
            stk.push(i);
        }
        else
        {
            result[i] = stk.top() + 1;
            stk.push(i);
        }
    }
    return result;
}

// O(n) O(n)
vector<int> nextSmallerElementRight(vector<int> &nums)
{
    int size = nums.size();
    stack<int> stk;
    vector<int> result(size);

    for (int i = size - 1; i >= 0; i--)
    {
        while (!stk.empty() && nums[i] <= nums[stk.top()])
        {
            stk.pop();
        }
        if (stk.empty())
        {
            result[i] = size - 1;
            stk.push(i);
        }
        else
        {
            result[i] = stk.top() - 1;
            stk.push(i);
        }
    }
    return result;
}

// Base = Right - Left + 1
// Height = arr[i]
int maxArea(vector<int> &heights)
{
    vector<int> left = nextSmallerElementLeft(heights);
    vector<int> right = nextSmallerElementRight(heights);
    int maxA = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        maxA = max(maxA, (right[i] - left[i] + 1) * heights[i]);
    }
    return maxA;
}

int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    cout << maxArea(arr) << endl;
    return 0;
}
// g++ file.cpp -o
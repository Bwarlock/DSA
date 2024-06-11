#include <bits/stdc++.h>
using namespace std;

// O(n) O(n)
vector<int> nextGreaterElement(vector<int> &nums)
{
    int size = nums.size();
    stack<int> stk;
    vector<int> result(size);

    for (int i = size - 1; i >= 0; i--)
    {
        while (!stk.empty() && nums[i] >= nums[stk.top()])
        {
            stk.pop();
        }
        if (stk.empty())
        {
            result[i] = -1;
            stk.push(i);
        }
        else
        {
            result[i] = nums[stk.top()];
            stk.push(i);
        }
    }
    return result;
}

// O(2n) O(n)
vector<int> nextGreaterCircularElement(vector<int> &nums)
{
    int size = nums.size();
    stack<int> stk;
    vector<int> result(size);

    for (int i = size - 1; i >= 0; i--)
    {
        while (!stk.empty() && nums[i] >= nums[stk.top()])
        {
            stk.pop();
        }
        stk.push(i);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        while (!stk.empty() && nums[i] >= nums[stk.top()])
        {
            stk.pop();
        }
        if (stk.empty())
        {
            result[i] = -1;
            stk.push(i);
        }
        else
        {
            result[i] = nums[stk.top()];
            stk.push(i);
        }
    }
    return result;
}

vector<int> nextSmallerElement(vector<int> &nums)
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
            result[i] = -1;
            stk.push(i);
        }
        else
        {
            result[i] = nums[stk.top()];
            stk.push(i);
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {8, 11, 7, 6, 13, 6, 14, 5};
    for (int i : nextSmallerElement(arr))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
// g++ file.cpp -o
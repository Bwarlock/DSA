// Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.

// Return the minimum number of patches required.

#include <bits/stdc++.h>
using namespace std;

int minPatches(vector<int> &nums, int n)
{
    int result = 0;
    long long possibleSum = 0, k = 1;
    vector<int> resultArr;
    size_t i = 0;
    while (possibleSum < n)
    {
        if (i < nums.size() && nums[i] <= k)
        {
            possibleSum += nums[i]; // Even tho possible = k - 1 always
            k += nums[i];
            ++i;
        }
        else
        {
            ++result;
            resultArr.push_back(k);
            possibleSum += k;
            k += k;
        }
    }
    for (int i : resultArr)
    {
        cout << i << " ";
    }
    cout << endl;
    return result;
}

int main()
{
    int n = 2147483647;
    vector<int> nums = {1, 2, 31, 33};
    cout << minPatches(nums, n);
    cout << endl;
    return 0;
}
// g++ file.cpp -o
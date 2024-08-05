// You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

// Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.

#include <bits/stdc++.h>
using namespace std;

void combine(vector<int> &nums, unordered_map<int, vector<pair<int, int>>> &sum, int group, const int &len)
{
    for (pair<int, int> p : sum[group - 1])
    {
        for (int i = p.second + 1; i < len; i++)
        {
            sum[group].push_back({p.first + nums[i], i});
        }
    }
}

int rangeSum(vector<int> &nums, int n, int left, int right)
{
    unordered_map<int, vector<pair<int, int>>> sum;
    // pair<int,int>  O (2 * total outcomes n * (n + 1) / 2)
    vector<int> combineArr;
    int result = 0;
    int len = nums.size();

    for (int i = 0; i < len; i++)
    {
        // n
        sum[1].push_back({nums[i], i});
    }

    for (int i = 2; i <= len; i++)
    {
        // n^2 for start 2 case , then n^3 for 3 case
        // not as optimized hah
        combine(nums, sum, i, len);
    }

    for (auto v : sum)
    {
        for (auto p : v.second)
        {
            combineArr.push_back(p.first);
        }
    }
    sort(combineArr.begin(), combineArr.end());
    for (int i = left - 1; i < right; i++)
    {
        result += combineArr[i];
    }
    return result;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
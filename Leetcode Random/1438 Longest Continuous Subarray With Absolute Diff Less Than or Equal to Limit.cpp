// Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums, int limit)
{
    // Not
    // need study
    deque<int> maxq;
    deque<int> minq;
    int j = 0;
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!maxq.empty() && nums[i] > maxq.back())
        {
            maxq.pop_back();
        }
        maxq.push_back(nums[i]);

        while (!minq.empty() && nums[i] < minq.back())
        {
            minq.pop_back();
        }
        minq.push_back(nums[i]);

        if (maxq.front() - minq.front() > limit)
        {
            if (nums[j] == maxq.front())
                maxq.pop_front();
            if (nums[j] == minq.front())
                minq.pop_front();
            j++;
        }
        result = max(result, i - j + 1);
    }
    return result;
}

int main()
{
    int limit = 4;
    vector<int> nums = {8, 2, 4, 7};
    cout << longestSubarray(nums, limit);
    cout << endl;
    return 0;
}
// g++ file.cpp -o
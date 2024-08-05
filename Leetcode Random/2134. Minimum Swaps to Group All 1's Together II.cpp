// A swap is defined as taking two distinct positions in an array and swapping the values in them.

// A circular array is defined as an array where we consider the first element and the last element to be adjacent.

// Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &nums)
{
    int len = nums.size();
    int total = 0;
    for (int i = 0; i < len; i++)
    {
        if (nums[i] == 1)
        {
            total++;
        }
    }
    int end = 0;
    int count = nums[0];
    int maxCount = 0;
    for (int start = 0; start < len; start++)
    {
        if (start != 0)
        {
            count -= nums[start - 1];
        }
        while (end - start + 1 < total)
        {
            end++;
            count += nums[end % len];
        }

        maxCount = max(maxCount, count);
    }

    return (total - maxCount);
}

int main()
{
    vector<int> nums = {0, 1, 0, 1, 1, 0, 0};
    cout << minSwaps(nums) << endl;
    return 0;
}
// g++ file.cpp -o
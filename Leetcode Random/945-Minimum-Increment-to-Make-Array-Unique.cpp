// You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

// Return the minimum number of moves to make every value in nums unique.

// The test cases are generated so that the answer fits in a 32-bit integer.

#include <bits/stdc++.h>
using namespace std;

int minIncrementForUnique(vector<int> &nums)
{
    int result = 0;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] <= nums[i - 1])
        {
            int ad = 1 + nums[i - 1] - nums[i];
            nums[i] += ad;
            result += ad;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {0, 1, 0, 0, 2, 0, 2};
    cout << minIncrementForUnique(nums);
    cout << endl;
    return 0;
}
// g++ file.cpp -o
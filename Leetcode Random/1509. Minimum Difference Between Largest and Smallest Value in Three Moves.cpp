// You are given an integer array nums.

// In one move, you can choose one element of nums and change it to any value.

// Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

#include <bits/stdc++.h>
using namespace std;

int minDifference(vector<int> &nums)
{
    // n + n + 8logn
    // space n + n + 12
    if (nums.size() <= 4)
    {
        return 0;
    }
    // heapify O(n);
    priority_queue<int, vector<int>, greater<int>> lowQ(greater<int>(), nums);
    priority_queue<int, vector<int>, less<int>> highQ(less<int>(), nums);
    vector<int> low(4);
    vector<int> high(4);
    for (int i = 0; i < 4; ++i)
    {
        low[i] = lowQ.top();
        high[i] = highQ.top();
        cout << low[i] << high[i] << endl;
        lowQ.pop();
        highQ.pop();
    }
    int result1 = abs(high[0] - low[3]);
    int result2 = abs(high[3] - low[0]);
    int result3 = abs(high[1] - low[2]);
    int result4 = abs(high[2] - low[1]);

    return min(min(result1, result2), min(result3, result4));
}

// int minDifference(vector<int> &nums)
// {
//     // nlogn
//     if (nums.size() <= 4)
//     {
//         return 0;
//     }
//     sort(nums.begin(), nums.end());
//     int high = nums.size() - 1;
//     int result1 = abs(nums[high] - nums[3]);
//     int result2 = abs(nums[high - 3] - nums[0]);
//     int result3 = abs(nums[high - 1] - nums[2]);
//     int result4 = abs(nums[high - 2] - nums[1]);

//     return min(min(result1, result2), min(result3, result4));
// }

int main()
{
    vector<int> nums1 = {1, 4, 2, 4, 5, 6};

    cout << minDifference(nums1) << " ";

    cout << endl;
    return 0;
}
// g++ file.cpp -o
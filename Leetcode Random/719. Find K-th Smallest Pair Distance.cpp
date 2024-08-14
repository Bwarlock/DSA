// The distance of a pair of integers a and b is defined as the absolute difference between a and b.

// Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

#include <bits/stdc++.h>
using namespace std;

int countPairsWithMaxDistance(vector<int> &nums, int maxDistance)
{
    int count = 0;
    int arraySize = nums.size();
    int left = 0;

    for (int right = 0; right < arraySize; ++right)
    {

        while (nums[right] - nums[left] > maxDistance)
        {
            ++left;
        }
        count += right - left;
    }
    return count;
}

int smallestDistancePair(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int arraySize = nums.size();

    int low = 0;
    int high = nums[arraySize - 1] - nums[0];

    while (low < high)
    {
        int mid = (low + high) / 2;
        int count = countPairsWithMaxDistance(nums, mid);

        if (count < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

// MY Approach
int MinesmallestDistancePair(vector<int> &nums, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int absDiff = abs(nums[i] - nums[j]);
            if (pq.size() < k)
            {
                pq.push(absDiff);
            }
            else if (absDiff < pq.top())
            {
                pq.push(absDiff);
                pq.pop();
            }
        }
    }
    return pq.top();
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
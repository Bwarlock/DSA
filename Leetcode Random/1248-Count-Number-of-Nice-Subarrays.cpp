// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int> &nums, int k)
{
    // Not
    int result = 0;
    int cnt = 0;
    int i = 0, j = 0;

    while (j < nums.size())
    {
        if (nums[j] % 2 != 0)
        {
            k--;
            cnt = 0;
        }

        while (k == 0)
        {
            if (nums[i] % 2 != 0)
            {
                k++;
            }
            cnt++;
            i++;
        }

        result += cnt;
        j++;
    }

    return result;
}

int main()
{
    int k = 2;
    vector<int> nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    cout << numberOfSubarrays(nums, k);
    cout << endl;
    return 0;
}
// g++ file.cpp -o
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int i = 0, j = 0, k = nums.size() - 1;
    while (i <= k)
    {
        if (nums[i] == 0)
        {
            swap(nums[i], nums[j]);
            j++;
            i++;
        }
        else if (nums[i] == 2)
        {
            swap(nums[i], nums[k]);
            k--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 0, 2, 0, 2};
    sortColors(nums);
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
// g++ file.cpp -o
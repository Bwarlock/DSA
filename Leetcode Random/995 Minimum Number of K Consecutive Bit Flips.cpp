// You are given a binary array nums and an integer k.

// A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

// Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.

// A subarray is a contiguous part of an array.

#include <bits/stdc++.h>
using namespace std;

int minKBitFlips(vector<int> &nums, int k)
{
    // HARD
    int n = nums.size();
    int flips = 0;
    int j = 0;

    for (int i = 0; i < n; i++)
    {

        if (i >= k)
        {

            if (nums[i - k] == 2)
            {
                // destroy the influence of previous window starting index's flip
                // coz current index is not part of it
                // if the whole window 3 size was flipped at each index (j value) 0 -> 1 , 1 -> 0 , 0 -> 1
                // and current index is not part of first index flip , it should have been flipped 2 times not 3
                // so add another flip to change the parity back
                j ^= 1;
            }
        }

        // Only flip when 0 xor 0 -> 0 , 1 xor 1 -> 0
        // if the current is 0 and it was not flipped , if current is 1 and it was flipped
        if ((nums[i] ^ j) == 0)
        {

            if (i + k > n)
            {
                return -1;
            }

            flips++;
            j ^= 1;
            nums[i] = 2; // mark as flipped
        }
    }

    return flips;
}
int main()
{
    int k = 2;
    vector<int> nums = {1, 0, 1, 0};
    cout << minKBitFlips(nums, k);
    cout << endl;
    return 0;
}
// g++ file.cpp -o
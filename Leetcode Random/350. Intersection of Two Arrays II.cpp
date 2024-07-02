// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> count(0);
    vector<int> result;
    if (nums1.size() < nums2.size())
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            count[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (count[nums2[i]] > 0)
            {
                count[nums2[i]]--;
                result.push_back(nums2[i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < nums2.size(); i++)
        {
            count[nums2[i]]++;
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            if (count[nums1[i]] > 0)
            {
                count[nums1[i]]--;
                result.push_back(nums1[i]);
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    for (int i : intersect(nums1, nums2))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
// g++ file.cpp -o
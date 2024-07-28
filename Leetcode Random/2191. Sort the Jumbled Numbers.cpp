// You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

// The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

// You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

// Notes:

// Elements with the same mapped values should appear in the same relative order as in the input.
// The elements of nums should only be sorted based on their mapped values and not be replaced by them.

#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> &a, pair<int, int> &b)
{
    return a.first < b.first;
}

vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
{
    vector<int> result;
    vector<pair<int, int>> mapped;

    for (int i = 0; i < nums.size(); i++)
    {
        pair<int, int> temp;
        string tempInt = to_string(nums[i]);
        // int resultInt = 0;
        for (int k = 0; k < tempInt.length(); k++)
        {
            // cout << tempInt[k] << endl;
            // cout << tempInt[k] << char(mapping[int(tempInt[k]) - 48] + 48) << endl;
            tempInt[k] = char(mapping[int(tempInt[k]) - 48] + 48);
        }
        mapped.push_back({stoi(tempInt), i});
    }

    sort(mapped.begin(), mapped.end(), comparator);

    for (int i = 0; i < mapped.size(); i++)
    {
        // cout << mapped[i].first << mapped[i].second << endl;
        result.push_back(nums[mapped[i].second]);
    }

    return result;
}

int main()
{
    vector<int> mapping = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
    vector<int> nums = {991, 338, 38};
    cout << sortJumbled(mapping, nums)[1] << endl;
    return 0;
}
// g++ file.cpp -o
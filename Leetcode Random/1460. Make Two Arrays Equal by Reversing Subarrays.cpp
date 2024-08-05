// You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.

// Return true if you can make arr equal to target or false otherwise.

#include <bits/stdc++.h>
using namespace std;

bool canBeEqual(vector<int> &target, vector<int> &arr)
{
    unordered_map<int, int> countTarget;
    unordered_map<int, int> countArr;

    for (int i : target)
    {
        countTarget[i]++;
    }
    for (int i : arr)
    {
        countArr[i]++;
    }
    for (auto i : countTarget)
    {
        if (countArr[i.first] != i.second)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
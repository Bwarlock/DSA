// Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
#include <bits/stdc++.h>
using namespace std;

bool threeConsecutiveOdds(vector<int> &arr)
{
    short count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] & 1)
        {
            count++;
            if (count == 3)
            {
                return true;
            }
        }
        else
        {
            count = 0;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {2, 6, 4, 1};

    cout << threeConsecutiveOdds(arr) << endl;

    return 0;
}
// g++ file.cpp -o
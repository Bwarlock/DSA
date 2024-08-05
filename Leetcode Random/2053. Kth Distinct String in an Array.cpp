// A distinct string is a string that is present only once in an array.

// Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".

// Note that the strings are considered in the order in which they appear in the array.

#include <bits/stdc++.h>
using namespace std;

string kthDistinct(vector<string> &arr, int k)
{
    unordered_map<string, int> count;
    for (string s : arr)
    {
        count[s]++;
    }
    int index = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count[arr[i]] == 1)
        {
            index++;
            if (index == k)
            {
                return arr[i];
            }
        }
    }
    return "";
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
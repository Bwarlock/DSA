// You are given an integer array bloomDay, an integer m and an integer k.

// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

#include <bits/stdc++.h>
using namespace std;

int minDays(vector<int> &bloomDay, int m, int k)
{
    // Not
    int s = 0, e = 1e9;
    int maxM = s + (e - s) / 2, result = -1;
    while (s <= e)
    {
        int con = 0, buk = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= maxM)
            {
                con++;
                if (con >= k)
                {
                    buk++;
                    con = 0;
                }
            }
            else
                con = 0;
        }

        if (buk >= m)
        {
            result = maxM;
            e = maxM - 1;
        }
        else
            s = maxM + 1;
        maxM = s + (e - s) / 2;
    }
    return result;
}

int main()
{
    int m = 2, k = 3;
    vector<int> bloom = {7, 7, 7, 7, 12, 7, 7};
    vector<int> capitals = {1, 0, 1};
    cout << minDays(bloom, m, k);
    cout << endl;
    return 0;
}
// g++ file.cpp -o
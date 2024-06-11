#include <bits/stdc++.h>
using namespace std;

int rainwaterTrapping(vector<int> heights)
{
    int n = heights.size(), water = 0;
    vector<int> lmax(n), rmax(n);

    lmax[0] = heights[0];
    rmax[n - 1] = heights[n - 1];
    for (int i = 1; i < n; i++)
    {
        lmax[i] = max(lmax[i - 1], heights[i]);
        rmax[n - 1 - i] = max(rmax[n - i], heights[n - 1 - i]);
    }

    // water isnt trapping on either ends 0 , n-1
    for (int i = 1; i < n - 1; i++)
    {
        water += min(lmax[i], rmax[i]) - heights[i];
    }

    return water;
}

int main()
{
    vector<int> heights = {9, 2, 4, 5, 8, 9, 9};
    cout << rainwaterTrapping(heights) << endl;
    return 0;
}
// g++ file.cpp -o
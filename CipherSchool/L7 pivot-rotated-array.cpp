#include <bits/stdc++.h>
using namespace std;

int pivotRotatedArray(vector<int> a)
{
    int low = 0;
    int high = a.size() - 1;
    int mid;
    if (low == high)
    {
        return low;
    }
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] > a[mid + 1])
            return mid + 1;

        if (a[mid] < a[mid - 1])
            return mid;

        // check last and mid
        // low = mid + 1 or high = mid - 1 was giving problems
        if (a[mid] <= a[high])
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {7, 8, 9, 10, 11, 2, 3};
    cout << pivotRotatedArray(a) << endl;
    return 0;
}
// g++ file.cpp -o1
#include <bits/stdc++.h>
using namespace std;

// Edge case {9,3,2,1} gives -1
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
        {
            if (a[mid] > a[mid - 1])
            {
                return mid;
            }
            // move left
            high = mid - 1;
        }
        else if (a[mid] < a[mid + 1])
        {
            // move right
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {7, 9, 3, 2, 1};
    cout << "peak : " << pivotRotatedArray(a) << endl;
    return 0;
}
// g++ file.cpp -o1
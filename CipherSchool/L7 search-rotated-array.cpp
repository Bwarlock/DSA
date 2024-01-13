#include <bits/stdc++.h>
using namespace std;

int searchRotatedArray(vector<int> a, int x)
{
    int low = 0;
    int high = a.size() - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        if (a[mid] == a[low] && a[mid] == a[high])
        {
            low++;
            high--;
            continue;
        }

        // check last and mid
        // low = mid + 1 or high = mid - 1 was giving problems
        if (a[mid] <= a[high])
        {
            if (a[mid] < x && x < a[high])
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        else
        {
            if (a[low] < x && x < a[mid])
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {7, 8, 9, 11, 1, 2, 3};
    cout << searchRotatedArray(a, 2) << endl;
    return 0;
}
// g++ file.cpp -o1
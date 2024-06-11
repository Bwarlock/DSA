#include <bits/stdc++.h>
using namespace std;

int searchRotatedArray(vector<int> a, int x)
{
    int low = 0;
    int high = a.size() - 1;
    int mid;
    while (low <= high)
    {
        cout << low << high << mid << endl;
        mid = (low + high) / 2;
        if (a[mid] == x)
        {
            return mid;
        }

        if (a[mid] == a[low])
        {
            low = mid + 1;
            continue;
        }
        if (a[mid] == a[high])
        {
            high = mid - 1;
            continue;
        }

        // check last and mid
        // low = mid + 1 or high = mid - 1 was giving problems
        if (a[mid] <= a[high])
        {
            if (a[mid] < x && x <= a[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else
        {
            if (a[low] <= x && x < a[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {1, 2, 3};
    cout << searchRotatedArray(a, 3) << endl;
    return 0;
}
// g++ file.cpp -o1
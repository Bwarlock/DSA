#include <bits/stdc++.h>
using namespace std;

vector<int> sort012(vector<int> nums)
{
    int p0 = 0, p1 = 0, p2 = nums.size() - 1;
    while (p1 <= p2)
    {
        switch (nums[p1])
        {
        case 0:
            swap(nums[p0], nums[p1]);
            p0++;
            p1++;
            break;
        case 1:
            p1++;
            break;
        case 2:
            swap(nums[p1], nums[p2]);
            p2--;
            break;
        default:
            break;
        }
    }

    return nums;
}

int main()
{
    vector<int> nums = {0, 1, 0, 0, 2, 0, 2};
    for (int i : sort012(nums))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
// g++ file.cpp -o
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int> nums)
{
    int n = nums.size();
    vector<vector<int>> result;

    if (n <= 2)
    {
        return {};
    }

    sort(nums.begin(), nums.end()); // nLogn(n)

    for (int i = 0; i < n; i++) // n*n
    {
        int start = i + 1;
        int end = n - 1;
        while (start < end) // n
        {
            if (nums[i] + nums[start] + nums[end] == 0)
            {
                result.push_back({nums[i], nums[start], nums[end]});
                start++;
                end--;

                while (start < end && nums[start - 1] == nums[start])
                {
                    start++;
                }
                while (start < end && nums[end + 1] == nums[end])
                {
                    end--;
                }
            }
            else if (nums[i] + nums[start] + nums[end] < 0)
            {
                start++;
            }
            else if (nums[i] + nums[start] + nums[end] > 0)
            {
                end--;
            }
        }

        while (i < n - 1 && nums[i + 1] == nums[i])
        {
            i++;
        }
    }

    return result; // nLogn(n) + n*n
}

int main()
{
    vector<int> nums = {-1, -1, 0, 4, 2, 1};
    for (vector<int> i : triplets(nums))
    {
        for (int k : i)
        {
            cout << k << " ";
        }
        cout << endl;
    }
    return 0;
}
// g++ file.cpp -o
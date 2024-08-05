#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<int> result(0, 0);
    for (int i : nums)
    {
        if (target - i > 0)
        {
            int temp = binary_search(nums.begin(), nums.end(), target - i);
            if (temp)
            {
                result[0] = i;
                result[1] = target - i;
                return result;
            }
        }
    }
    return {-1, -1};
}

int minimumDeletions(string s)
{
    int len = s.size();
    vector<int> countA_ahead(len + 2, 0);
    vector<int> countB_behind(len + 2, 0);
    int result = len;
    for (char c : s)
    {

        if (c == 'a')
        {
            countA_ahead[0]++;
        }
        else if (c == 'b')
        {
            countB_behind[len + 1]++;
        }
    }
    for (int i = 0; i < len; i++)
    {
        countA_ahead[i + 1] = s[i] == 'a' ? countA_ahead[i] - 1 : countA_ahead[i];
        countB_behind[len - i] = s[len - i - 1] == 'b' ? countB_behind[len - i + 1] - 1 : countB_behind[len - i + 1];
    }
    for (int i = 1; i < len + 1l; i++)
    {
        result = min(result, countA_ahead[i] + countB_behind[i]);
    }
    return result;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
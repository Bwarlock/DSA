#include <bits/stdc++.h>
using namespace std;

void recursionPowerSet(vector<int> &tempCombo, vector<vector<int>> &result, int start, int length, vector<int> &nums)
{
    if (tempCombo.size() == length)
    {
        result.push_back(tempCombo);
        return;
    }
    else
    {
        for (int i = start; i < nums.size(); i++)
        {
            tempCombo.push_back(nums[i]);
            recursionPowerSet(tempCombo, result, i + 1, length, nums);
            tempCombo.pop_back();
        }
    }
}

vector<vector<int>> powerSet(vector<int> nums)
{
    vector<vector<int>> result;
    vector<int> tempCombo = {};
    int start = 0;

    // usually in dynamic languages composite dataTypes are passed by reference by default
    for (int i = 0; i <= nums.size(); i++)
    {
        recursionPowerSet(tempCombo, result, start, i, nums);
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 3};
    vector<vector<int>> result = powerSet(nums);
    for (vector<int> i : result)
    {
        cout << "{ ";
        for (int k : i)
        {
            cout << k << " ";
        }
        cout << "}" << endl;
    }
    cout << endl;
    cout << "should be possible values : " << pow(2, nums.size()) << endl;
    cout << result.size() << " Possibilities";
    return 0;
}
// g++ file.cpp -o
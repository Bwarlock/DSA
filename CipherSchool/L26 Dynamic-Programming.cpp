
#include <bits/stdc++.h>
using namespace std;

int minCoinChange(const vector<int> &coins, const int sum)
{
    int size = coins.size();
    vector<vector<int>> dp(size + 1, vector<int>(sum + 1, INT_MAX));
    // c | s 0 1   2 . . . 11
    // 0 |   0 Inf Inf . . Inf
    // 1 |   0 1   2 . . . 11

    // dp[row][col]
    for (int i = 0; i < size; i++)
    {
        dp[i][0] = 0;
    }
    for (int s = 1; s <= sum; s++)
    {
        for (int c = 1; c <= size; c++)
        {
            // [c - 1] coz its 1 to size not 0 to size - 1
            if (coins[c - 1] <= s && dp[c][s - coins[c - 1]] < INT_MAX)
            {
                // Int_Max + 1 = Int_Min
                // Check if current new coin is lower than needed sum otherwise take previous best option for needed sum
                dp[c][s] = min(1 + dp[c][s - coins[c - 1]], dp[c - 1][s]);
            }
            else
            {
                dp[c][s] = dp[c - 1][s];
            }
        }
    }
    return dp[size][sum];
}
int minCoinChangeWithoutRepition(const vector<int> &coins, const int sum)
{
    int size = coins.size();
    vector<vector<int>> dp(size + 1, vector<int>(sum + 1, INT_MAX));
    // c | s 0 1   2 . . . 11
    // 0 |   0 Inf Inf . . Inf
    // 1 |   0 1   2 . . . 11

    // dp[row][col]
    for (int i = 0; i < size; i++)
    {
        dp[i][0] = 0;
    }
    for (int s = 1; s <= sum; s++)
    {
        for (int c = 1; c <= size; c++)
        {
            // [c - 1] coz its 1 to size not 0 to size - 1
            if (coins[c - 1] <= s && dp[c][s - coins[c - 1]] < INT_MAX)
            {
                // Int_Max + 1 = Int_Min
                // Check if current new coin is lower than needed sum otherwise take previous best option for needed sum
                // Since Repition is not allowed if 1 + coin is choosen
                // One have to choose the resultant sum (s - current coin) solution from previous coins instead (c - 1)
                dp[c][s] = min(1 + dp[c - 1][s - coins[c - 1]], dp[c - 1][s]);
            }
            else
            {
                dp[c][s] = dp[c - 1][s];
            }
        }
    }
    return dp[size][sum];
}

int subsetSum(const vector<int> &nums, const int sum)
{
    int size = nums.size();
    vector<vector<bool>> dp(size + 1, vector<bool>(sum + 1, false));

    // dp[row][col]
    for (int i = 0; i < size; i++)
    {
        dp[i][0] = true;
    }
    for (int s = 1; s <= sum; s++)
    {
        for (int n = 1; n <= size; n++)
        {
            if (nums[n - 1] <= s)
            {
                dp[n][s] = dp[n - 1][s - nums[n - 1]] || dp[n - 1][s];
            }
            else
            {
                dp[n][s] = dp[n - 1][s];
            }
        }
    }
    return dp[size][sum];
}

int rodCutting(const vector<int> &prices)
{
    int length = prices.size();
    vector<int> dp(length + 1, 0);
    for (int i = 1; i <= length; i++)
    {
        dp[i] = prices[i - 1];
        for (int k = 1; k < i; k++)
        {
            dp[i] = max(dp[k] + dp[i - k], dp[i]);
        }
    }
    return dp[length];
}

int jumpGame(const vector<int> &jumps)
{
    int length = jumps.size();
    vector<int> dp(length, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= length - 1; i++)
    {
        for (int k = 1; k <= jumps[length - i - 1]; k++)
        {
            if (i - k >= 0 && dp[i - k] < INT_MAX)
            {
                dp[i] = min(1 + dp[i - k], dp[i]);
            }
        }
    }
    return dp[length - 1];
}

int longestIncreasingSubsequence(const vector<int> &nums)
{
    int length = nums.size();
    vector<int> dp(length, 1);
    for (int i = 0; i < length; i++)
    {
        for (int k = 0; k < i; k++)
        {
            if (nums[k] < nums[i])
            {
                dp[i] = max(dp[i], 1 + dp[k]);
            }
        }
    }
    return dp[length - 1];
}
int longestIncreasingSubsequenceSum(const vector<int> &nums)
{
    int length = nums.size();
    vector<int> dp(length);
    for (int i = 0; i < length; i++)
    {
        dp[i] = nums[i];
        for (int k = 0; k < i; k++)
        {
            if (nums[k] < nums[i])
            {
                dp[i] = max(dp[i], nums[i] + dp[k]);
            }
        }
    }
    return dp[length - 1];
}

int longestIncreasingPathInMatrix(const vector<vector<int>> &arr, int row, int col, vector<vector<int>> &dp, int prev)
{
    if (row < 0 || arr.size() <= row || col < 0 || arr[0].size() <= col || arr[row][col] <= prev)
    {
        return 0;
    }
    if (dp[row][col] == 0)
    {
        int left = longestIncreasingPathInMatrix(arr, row, col - 1, dp, arr[row][col]);
        int right = longestIncreasingPathInMatrix(arr, row, col + 1, dp, arr[row][col]);
        int top = longestIncreasingPathInMatrix(arr, row - 1, col, dp, arr[row][col]);
        int bottom = longestIncreasingPathInMatrix(arr, row + 1, col, dp, arr[row][col]);
        dp[row][col] = 1 + max(max(left, right), max(top, bottom));
    }
    return dp[row][col];
}

int longestIncreasingPathInMatrix(const vector<vector<int>> &arr)
{
    int result = 0;
    vector<vector<int>> dp(arr.size(), vector<int>(arr[0].size(), 0));
    for (int i = 0; i < arr.size(); i++)
    {
        for (int k = 0; k < arr[0].size(); k++)
        {
            result = max(result, longestIncreasingPathInMatrix(arr, i, k, dp, 0));
        }
    }
    return result;
}

int longestPalindromeSubstring(const string &s)
{
    int len = s.length();
    // Another question of total possibles
    int totalPossible = 0;
    if (len < 3)
    {
        if (s[0] == s[len - 1])
        {
            return len;
        }
        else
        {
            return 1;
        }
    }
    string result = "";
    int maxLen = 0;
    vector<vector<int>> dp(len, vector<int>(len, 0));
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
    }
    totalPossible += len;
    maxLen = 1;
    result = s.substr(len - 1, 1);

    for (int window = 1; window < len; window++)
    {
        for (int i = 0; i + window < len; i++)
        {
            if (window == 1)
            {
                if (s[i] == s[i + window])
                {
                    dp[i][i + window] = 2;
                    maxLen = max(maxLen, 2);
                    result = s.substr(i, 2);
                    totalPossible++;
                }
                else
                {
                    dp[i][i + window] = 0;
                }
                continue;
            }
            if (s[i] == s[i + window] && dp[i + 1][i + window - 1] > 0)
            {
                dp[i][i + window] = 2 + dp[i + 1][i + window - 1];
                maxLen = max(maxLen, dp[i][i + window]);
                result = s.substr(i, window + 1);
                totalPossible++;
            }
            // else
            // {
            //     dp[i][i + k] = max(dp[i][i + k - 1], dp[i + 1][i + k]);
            // }
            else
            {
                dp[i][i + window] = 0;
            }
        }
    }

    cout << "  ";
    for (char i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < dp.size(); i++)
    {
        cout << s[i] << " ";
        for (int k : dp[i])
        {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << result << endl;

    return maxLen;
}

// void allPossibleCoinChange(vector<int> &coins, const int &sum, vector<unordered_map<int, int>> &result, unordered_map<int, int> &tempMap,int tempSum)
// {
//     if(tempSum > sum){
//         return;
//     }
//     if(tempSum == sum){
//         result.push_back(tempMap);
//         return;
//     }
//     for(int i : coins){
//     allPossibleCoinChange(coins,sum,result,);
//      //needs dp somehow , need to think
//     }
// }

vector<unordered_map<int, int>> allPossibleCoinChange(vector<int> &coins, const int sum)
{
    vector<unordered_map<int, int>> result;
    unordered_map<int, int> tempMap;
    for (int i : coins)
    {
        tempMap[i] = 0;
    }
    return result;
}

int main()
{
    // cout << longestIncreasingPathInMatrix({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    cout << longestPalindromeSubstring("ababab") << endl;

    return 0;
}
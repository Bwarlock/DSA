
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
    cout << longestIncreasingSubsequenceSum({2, 0, 1, 4});
    return 0;
}
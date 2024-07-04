
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
// vector<vector<int>> allPossibleCoinChange(vector<int> &coins,int sum){}

int main()
{
    cout << minCoinChange({1, 2, 5, 9}, 11);
    return 0;
}
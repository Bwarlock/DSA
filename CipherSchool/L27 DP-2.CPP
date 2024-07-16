
#include <bits/stdc++.h>
using namespace std;

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

int zeroOneKnapsack(const vector<vector<int>> &items, const int &W)
{
    int size = items.size();
    vector<vector<int>> dp(W + 1, vector<int>(size + 1, 0));
    for (int i = 1; i <= W; i++)
    {
        for (int k = 1; k <= size; k++)
        {
            // cout << i << " " << k << " ";
            if (items[k - 1][0] <= i)
            {
                dp[i][k] = max(items[k - 1][1] + dp[i - items[k - 1][0]][k - 1], dp[i][k - 1]);
            }
            else
            {
                dp[i][k] = dp[i][k - 1];
            }
            // cout << dp[i][k] << endl;
        }
    }

    // choose items
    vector<vector<int>> choosen;
    int i = W;
    for (int k = size; k > 0; k--)
    {
        if (dp[i][k - 1] < dp[i][k])
        {
            choosen.push_back(items[k - 1]);
            i = i - items[k - 1][0];
            cout << items[k - 1][0] << " " << items[k - 1][1] << endl;
        }
    }

    return dp[W][size];
}

int longestPalindromeSubsequence(const string &s)
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
            int j = i + window;
            if (window == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 2;
                    maxLen = max(maxLen, 2);
                    result = s.substr(i, 2);
                    totalPossible++;
                }
                else
                {
                    dp[i][j] = 1;
                }
                continue;
            }
            if (s[i] == s[j])
            {
                dp[i][j] = 2 + dp[i + 1][j - 1];
                maxLen = max(maxLen, dp[i][j]);
                cout << result << endl;
                result = s[i] + result + s[j];
                totalPossible++;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
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

string longestCommonSubsequence(const string &a, const string &b)
{
    string result = "";
    int maxLen = 0;
    int l1 = a.length(), l2 = b.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    for (int i = 1; i <= l2; i++)
    {
        for (int k = 1; k <= l1; k++)
        {
            if (b[i - 1] == a[k - 1])
            {
                cout << b[i - 1] << k - 1 << endl;
                dp[k][i] = 1 + dp[k - 1][i - 1];
            }
            else
            {
                dp[k][i] = max(dp[k - 1][i], dp[k][i - 1]);
            }
        }
    }

    cout << "  ";
    for (char i : b)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 1; i < dp.size(); i++)
    {
        cout << a[i - 1] << " ";
        for (int k = 1; k < dp[0].size(); k++)
        {
            cout << dp[i][k] << " ";
        }
        cout << endl;
    }

    maxLen = dp[l1][l2];
    int k = l1;
    int i = l2;
    while (i > 0 && k > 0)
    {
        if (a[k - 1] == b[i - 1])
        {
            result += a[k - 1];
            k--;
            i--;
        }
        else if (dp[k][i - 1] < dp[k][i])
        {
            k--;
        }
        else
        {
            i--;
        }
    }
    cout << maxLen << endl;
    reverse(result.begin(), result.end());
    return result;
}

string longestPalindromeSubsequenceString(const string &s)
{

    string rev = s;
    reverse(rev.begin(), rev.end());
    cout << s << " " << rev << endl;
    return longestCommonSubsequence(s, rev);
}

int editDistance(const string &a, const string &b)
{
    int l1 = a.length(), l2 = b.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    for (int i = 0; i <= l1; i++)
    {
        dp[i][0] = i;
    }
    for (int k = 0; k <= l2; k++)
    {
        dp[0][k] = k;
    }
    for (int k = 1; k <= l2; k++)
    {
        for (int i = 1; i <= l1; i++)
        {
            if (a[i - 1] == b[k - 1])
            {
                dp[i][k] = dp[i - 1][k - 1];
            }
            else
            {
                dp[i][k] = 1 + min(dp[i - 1][k], min(dp[i][k - 1], dp[i - 1][k - 1]));
            }
        }
    }
    return dp[l1][l2];
}

int main()
{
    // cout << zeroOneKnapsack({{3, 3}, {9, 11}, {6, 9}}, 12) << endl;

    // cout << longestCommonSubsequence("adbabadg", "abgd") << endl;
    // cout << longestPalindromeSubsequenceString("adbabadg") << endl;
    cout << editDistance("sunday", "saturday") << endl;
    return 0;
}
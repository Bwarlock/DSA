#include <bits/stdc++.h>
using namespace std;

// O(log(y)) , space O(log(y))
int exponentiationModulas(int base, int expo, int mod, unordered_map<int, int> &dp)
{
    if (expo % 2 == 0)
    {
        if (dp.find(expo) != dp.end())
        {
            return dp[expo];
        }
        else
        {
            dp[expo] = ((exponentiationModulas(base, expo / 2, mod, dp) % mod) * (exponentiationModulas(base, expo / 2, mod, dp) % mod)) % mod;
            return dp[expo];
        }
    }
    else
    {
        if (dp.find(expo) != dp.end())
        {
            return dp[expo];
        }
        else
        {
            dp[expo] = ((exponentiationModulas(base, expo - 1, mod, dp) % mod) * (exponentiationModulas(base, 1, mod, dp) % mod)) % mod;
            return dp[expo];
        }
    }
}

// Better iterative Solution i found on internet without dp need T_T
// O(log(expo))
int power(int base, int expo, int mod)
{
    int res = 1; // Initialize result

    base = base % mod; // Update base if it is more than or equal to mod

    if (base == 0)
        return 0;

    while (expo > 0)
    {

        // 10 & 1 , 100 & 1
        if (expo & 1)
            res = (res * base) % mod;

        // 10 -> 1 , 110 -> 11 , 111 -> 11
        expo = expo >> 1;
        base = (base * base) % mod;
    }
    return res;
}

int main()
{
    int base = 3, expo = 5, mod = 10;
    unordered_map<int, int> dp;
    dp[1] = base % mod;
    dp[0] = 1 % mod;
    cout << " exponent Modulas : " << exponentiationModulas(base, expo, mod, dp) << endl;
    cout << " power Modulas : " << power(base, expo, mod) << endl;
    return 0;
}
// g++ file.cpp -o
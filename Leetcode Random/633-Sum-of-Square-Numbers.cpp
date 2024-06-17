// Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
#include <bits/stdc++.h>
using namespace std;

// sqrt(c) * log(sqrt(c))
bool judgeSquareSum(int c)
{
    vector<long> arr;
    long j = 1, i = 0;
    while (i <= c)
    {
        arr.push_back(i);
        i += j;
        j += 2;
    }

    for (int i = 0; i < arr.size(); ++i)
    {
        long o = c - arr[i];
        int k = binary_search(arr.begin(), arr.end(), o);
        if (k)
        {
            return true;
        }
    }
    return false;
}

// Better Solution
// log(sqrt(c))
bool judgeSquareSumBetter(int c)
{
    long long int i = 1, j = sqrt(c);
    if (j * j == c)
        return true;
    while (i <= j)
    {
        long long sum = (i * i) + (j * j);
        if (sum == c)
            return true;
        else if (sum < c)
            i++;
        else
            j--;
    }
    return false;
}

int main()
{
    cout << judgeSquareSum(5);
    cout << endl;
    return 0;
}
// g++ file.cpp -o
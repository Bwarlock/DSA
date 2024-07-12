// You are given a string s and two integers x and y. You can perform two types of operations any number of times.

// Remove substring "ab" and gain x points.
// For example, when removing "ab" from "cabxbae" it becomes "cxbae".
// Remove substring "ba" and gain y points.
// For example, when removing "ba" from "cabxbae" it becomes "cabxe".
// Return the maximum points you can gain after applying the above operations on s.

#include <bits/stdc++.h>
using namespace std;

int maximumGain(string s, int x, int y)
{
    if (s.length() < 2)
    {
        return 0;
    }
    string better;
    string bad;
    int goodVal;
    int badVal;
    if (x > y)
    {
        better = "ab";
        bad = "ba";
        goodVal = x;
        badVal = y;
    }
    else
    {
        better = "ba";
        bad = "ab";
        goodVal = y;
        badVal = x;
    }
    int result = 0;
    stack<char> stk;
    stk.push(s[0]);
    char prev = s[0];
    for (int i = 1; i < s.length(); i++)
    {
        stk.push(s[i]);
        if (prev == better[0] && stk.top() == better[1])
        {
            stk.pop();
            stk.pop();
            result += goodVal;
        }
        prev = stk.empty() ? 'u' : stk.top();
    }
    string temp = "";
    while (!stk.empty())
    {
        temp += stk.top();
        stk.pop();
    }
    reverse(temp.begin(), temp.end());

    stk.push(temp[0]);
    prev = temp[0];
    for (int i = 1; i < temp.length(); i++)
    {
        stk.push(temp[i]);
        if (prev == bad[0] && stk.top() == bad[1])
        {
            stk.pop();
            stk.pop();
            result += badVal;
        }
        prev = stk.empty() ? 'u' : stk.top();
    }
    return result;
}

int main()
{
    cout << maximumGain("cdbcbbaaabab", 4, 5) << endl;
    return 0;
}
// g++ file.cpp -o
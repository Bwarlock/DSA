// You are given a string s that consists of lower case English letters and brackets.

// Reverse the strings in each pair of matching parentheses, starting from the innermost one.

// Your result should not contain any brackets.

#include <bits/stdc++.h>
using namespace std;

string reverseParentheses(string s)
{
    // even brute force was hard for me in the end T_T
    // also this method sure is elegant
    int n = s.length();
    stack<int> openParenthesesIndices;
    vector<int> pair(n);

    // First pass: Pair up parentheses
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(')
        {
            openParenthesesIndices.push(i);
        }
        if (s[i] == ')')
        {
            int j = openParenthesesIndices.top();
            openParenthesesIndices.pop();
            pair[i] = j;
            pair[j] = i;
        }
    }

    // Second pass: Build the result string
    string result;
    for (int currIndex = 0, direction = 1; currIndex < n;
         currIndex += direction)
    {
        if (s[currIndex] == '(' || s[currIndex] == ')')
        {
            currIndex = pair[currIndex];
            direction = -direction;
        }
        else
        {
            result += s[currIndex];
        }
    }
    return result;
}

int main()
{
    cout << reverseParentheses("a(bc)(de)i") << endl;
    return 0;
}
// g++ file.cpp -o
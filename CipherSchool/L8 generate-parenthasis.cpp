#include <bits/stdc++.h>
using namespace std;

void recursionGenerateParenthasis(string &tempStr, vector<string> &result, int open, int close)
{
    if (open < 0 || close < 0 || open > close)
    {
        // unbalanced
        return;
    }
    else if (open == 0 && close == 0)
    {
        result.push_back(tempStr);
    }
    else if (open <= close)
    {

        tempStr.push_back('(');
        recursionGenerateParenthasis(tempStr, result, open - 1, close);
        tempStr.pop_back();

        tempStr.push_back(')');
        recursionGenerateParenthasis(tempStr, result, open, close - 1);
        tempStr.pop_back();
    }
}

vector<string> generateParenthasis(const int n)
{
    vector<string> result;
    string tempStr;
    int open = n, close = n;

    // usually in dynamic languages composite dataTypes are passed by reference by default
    recursionGenerateParenthasis(tempStr, result, open, close);
    return result;
}

int main()
{
    int n;
    cout << "number of Parenthasis Pair : ";
    cin >> n;
    vector<string> result = generateParenthasis(n);
    for (string i : result)
    {
        cout << i << endl;
    }
    cout << result.size() << " Possibilities";
    return 0;
}
// g++ file.cpp -o
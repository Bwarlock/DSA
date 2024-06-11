#include <bits/stdc++.h>
using namespace std;

vector<string> dialpad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void recursionGenerateMessage(string &tempStr, vector<string> &result, int open, int close, string num)
{
    if (open == close)
    {
        result.push_back(tempStr);
        return;
    }
    else if (open < close)
    {
        for (char i : dialpad[num[open] - '0'])
        {
            tempStr.push_back(i);
            recursionGenerateMessage(tempStr, result, open + 1, close, num);
            tempStr.pop_back();
        }
    }
}

vector<string> generateMessage(const int n)
{
    vector<string> result;
    string tempStr, num = to_string(n);
    int open = 0, close = num.length();
    if (close < 1)
    {
        return {};
    }

    // usually in dynamic languages composite dataTypes are passed by reference by default
    recursionGenerateMessage(tempStr, result, open, close, num);
    return result;
}

int main()
{
    int n;
    cout << "dial number : ";
    cin >> n;
    vector<string> result = generateMessage(n);
    for (string i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
    cout << result.size() << " Posibilities" << endl;
    return 0;
}
// g++ file.cpp -o
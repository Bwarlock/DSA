#include <bits/stdc++.h>
using namespace std;

void generatePermute(string &tempStr, vector<string> &result, int start, int end)
{
    if (start >= end)
    {
        result.push_back(tempStr);
        return;
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            swap(tempStr[start], tempStr[i]);
            generatePermute(tempStr, result, start + 1, end);
            swap(tempStr[start], tempStr[i]);
        }
    }
}

vector<string> uniquePermutation(string inp)
{
    vector<string> result;
    int start = 0, end = inp.length() - 1;
    if (end < 0)
    {
        return {};
    }

    // usually in dynamic languages composite dataTypes are passed by reference by default
    generatePermute(inp, result, start, end);
    return result;
}

int main()
{
    string inp;
    cout << "enter Unique string : ";
    cin >> inp;
    vector<string> result = uniquePermutation(inp);
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
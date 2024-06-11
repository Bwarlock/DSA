#include <bits/stdc++.h>
using namespace std;

bool isMatching(char open, char close)
{
    return ((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']'));
}

bool isOpen(char ch)
{
    return (ch == '(' || ch == '{' || ch == '[');
}

bool isValid(string str)
{
    if (str.size() <= 0)
    {
        return true;
    }
    else if (str.size() & 1)
    {
        return false;
    }
    else
    {
        stack<char> bracket_stack;
        for (char i : str)
        {
            if (isOpen(i))
            {
                bracket_stack.push(i);
            }
            else if (bracket_stack.empty())
            {
                return false;
            }
            else if (isMatching(bracket_stack.top(), i))
            {
                bracket_stack.pop();
            }
            else
            {
                return false;
            }
        }
        return bracket_stack.empty();
    }
}

int minSwapForBalance(string str)
{
    int open = 0;
    for (char i : str)
    {
        if (i == '[')
        {
            open++;
        }
        else if (open != 0)
        {
            open--;
        }
    }
    return (open + 1) / 2;
    // 0 "]]][][[["
    // 1 "[]][][[]"
    // 2 "[][[]][]"
    // Not three
}
int main()
{
    cout << minSwapForBalance("]]][][[[") << endl;
    return 0;
}
// g++ file.cpp -o
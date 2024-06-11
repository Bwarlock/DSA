#include <bits/stdc++.h>
using namespace std;

// O(n) O(n)
template <class T>
void insertAtBottom(stack<T> &stk, T x)
{
    if (stk.empty())
    {
        stk.push(x);
        return;
    }
    else
    {
        T temp = stk.top();
        stk.pop();
        insertAtBottom(stk, x);
        stk.push(temp);
    }
}

// O(n^2) O(n)
// Why not just use Array at this point
template <class T>
void reverse(stack<T> &stk)
{
    if (stk.empty())
    {
        return;
    }
    else
    {
        T temp = stk.top();
        stk.pop();
        reverse(stk);
        insertAtBottom(stk, temp);
    }
}

// O(n) O(n)
void sortedPlacement(stack<int> &stk, int x)
{
    if (stk.empty() || stk.top() > x)
    {
        stk.push(x);
        return;
    }
    else
    {
        int temp = stk.top();
        stk.pop();
        sortedPlacement(stk, x);
        stk.push(temp);
    }
}

// O(n^2) O(n)
void sortStack(stack<int> &stk)
{
    if (stk.empty())
    {
        return;
    }
    else
    {
        int temp = stk.top();
        stk.pop();
        sortStack(stk);
        sortedPlacement(stk, temp);
    }
}

int main()
{
    stack<int> stk;
    stk.push(3);
    stk.push(2);
    stk.push(4);
    stk.push(10);
    sortStack(stk);
    while (!stk.empty())
    {
        cout << stk.top() << endl;
        stk.pop();
    }
    return 0;
}
// g++ file.cpp -o
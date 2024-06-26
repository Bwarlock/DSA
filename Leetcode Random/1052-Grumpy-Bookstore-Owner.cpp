// There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store. You are given an integer array customers of length n where customers[i] is the number of the customer that enters the store at the start of the ith minute and all those customers leave after the end of that minute.

// On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

// When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise, they are satisfied.

// The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, but can only use it once.

// Return the maximum number of customers that can be satisfied throughout the day.

#include <bits/stdc++.h>
using namespace std;

int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
{
    // less goo Fully Done By me  !!!!!!! Medium , first time
    // Sliding Window
    int lowIndex = 0;
    int maxSatisfaction = 0;
    int temp = 0;

    for (int i = 0; i < minutes; i++)
    {
        temp += customers[i];
    }
    maxSatisfaction = temp;

    for (int i = minutes; i < customers.size(); i++)
    {
        if (grumpy[i] == 0)
        {
            maxSatisfaction += customers[i];
        }
        temp += customers[i];
        if (grumpy[lowIndex] == 1)
        {
            cout << "hi" << i << " " << lowIndex << endl;
            temp -= customers[lowIndex];
        }

        cout << i << " " << maxSatisfaction << " " << temp << endl;
        if (temp > maxSatisfaction)
        {
            maxSatisfaction = temp;
        }
        lowIndex++;
    }
    return maxSatisfaction;
}

int main()
{
    int m = 3;
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    cout << maxSatisfied(customers, grumpy, m);
    cout << endl;
    return 0;
}
// g++ file.cpp -o
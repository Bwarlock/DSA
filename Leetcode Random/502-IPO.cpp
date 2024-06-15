// Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

// You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

// Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

// Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

// The answer is guaranteed to fit in a 32-bit signed integer.

#include <bits/stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    vector<vector<int>> projects;
    for (int i = 0; i < profits.size(); i++)
    {
        projects.push_back({capital[i], profits[i]});
    }

    sort(projects.begin(), projects.end());
    priority_queue<int> maxHeap;
    for (int i = 0; i < projects.size(); i++)
    {
        if (w >= projects[i][0])
        {
            maxHeap.push(projects[i][1]);
        }
        else if (k > 0 && maxHeap.size() > 0)
        {
            k--;
            i--;
            w += maxHeap.top();
            maxHeap.pop();
        }
    }

    while (maxHeap.size() > 0 && k > 0)
    {
        w += maxHeap.top();
        maxHeap.pop();
        k--;
    }
    return w;
}

int main()
{
    int k = 2, w = 4;
    vector<int> profits = {1, 2, 3};
    vector<int> capitals = {1, 0, 1};
    cout << findMaximizedCapital(k, w, profits, capitals);
    cout << endl;
    return 0;
}
// g++ file.cpp -o
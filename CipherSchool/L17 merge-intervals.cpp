#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> &a, pair<int, int> &b)
{
    return (a.first < b.first);
}

bool isOverlapping(pair<int, int> &a, pair<int, int> &b)
{
    return (a.second > b.first);
}

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> &intervals)
{
    if (intervals.size() <= 1)
    {
        return intervals;
    }
    vector<pair<int, int>> result;
    int top = 0;

    sort(intervals.begin(), intervals.end(), comparator);
    result.push_back(intervals[0]);

    for (pair<int, int> i : intervals)
    {
        if (isOverlapping(result[top], i))
        {
            result[top].second = max(result[top].second, i.second);
        }
        else
        {
            result.push_back(i);
            top++;
        }
    }
    return result;
}

int main()
{
    vector<pair<int, int>> arr = {{1, 3}, {2, 6}, {1, 8}, {8, 10}};
    for (pair<int, int> i : mergeIntervals(arr))
    {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
// g++ file.cpp -o
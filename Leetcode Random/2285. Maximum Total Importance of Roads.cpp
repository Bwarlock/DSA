// You are given an integer n denoting the number of cities in a country. The cities are numbered from 0 to n - 1.

// You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

// You need to assign each city with an integer value from 1 to n, where each value can only be used once. The importance of a road is then defined as the sum of the values of the two cities it connects.

// Return the maximum total importance of all roads possible after assigning the values optimally.

#include <bits/stdc++.h>
using namespace std;

class comparator
{
public:
    bool operator()(pair<int, long long> &a, pair<int, long long> &b)
    {
        return (a.second < b.second);
    }
};

// Priority Queue
long long maximumImportance(int n, vector<vector<int>> &roads)
{
    long long result = 0;
    vector<pair<int, long long>> frequency(n);
    for (int i = 0; i < n; i++)
    {
        frequency[i].first = i;
        frequency[i].second = 0;
    }
    for (long long i = 0; i < roads.size(); i++)
    {
        frequency[roads[i][0]].second++;
        frequency[roads[i][1]].second++;
    }

    // heapify O(n);
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, comparator> pq(comparator(), frequency);
    for (long long i = n; i > 0; i--)
    {
        // get the highest frequencied city (high no. of roads)
        // multiply its frequency with current highest i : n -> 1
        result += pq.top().second * i;
        pq.pop();
    }

    return result;
}

int main()
{
    vector<vector<int>> arr = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};

    cout << maximumImportance(5, arr) << endl;

    return 0;
}
// g++ file.cpp -o
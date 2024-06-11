#include <bits/stdc++.h>
using namespace std;

class comparator
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return (a.second > b.second);
    }
};

// Priority Queue
vector<int> KmostFrequency(vector<int> &nums, int K)
{
    // Need to Get Top K most frequent numbers in the array
    unordered_map<int, int> hash;
    for (int i : nums)
    {
        hash[i]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
    for (auto itr = hash.begin(); itr != hash.end(); itr++)
    {
        if (pq.size() < K)
        {
            pq.push(pair<int, int>{itr->first, itr->second});
        }
        else
        {
            cout << "hi" << endl;
            if (pq.top().second < itr->second)
            {
                pq.pop();
                pq.push(pair<int, int>{itr->first, itr->second});
            }
        }
    }

    vector<int> result;
    while (!pq.empty())
    {
        result.push_back(pq.top().first);
        pq.pop();
    }
    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9, 9, 1};
    for (int i : KmostFrequency(arr, 3))
    {
        cout << i << endl;
    }
    return 0;
}
// g++ file.cpp -o
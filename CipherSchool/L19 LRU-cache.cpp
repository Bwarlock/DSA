// Least Recently Used
#include <bits/stdc++.h>
using namespace std;

class LRUcache
{
    int size;
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;

public:
    LRUcache(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
    }
    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            // does not exist
            return -1;
        }
        else
        {
            // exist
            order.erase(cache[key].second);
            order.push_front(key);
            cache[key].second = order.begin();
            return cache[key].first;
        }
    }
    void put(int key, int value)
    {
        if (cache.find(key) == cache.end())
        {
            // Add New
            if (size == capacity)
            {
                // Evict Old
                cache.erase(order.back());
                order.pop_back();
            }
            else
            {
                size++;
            }
            order.push_front(key);
            cache[key] = {value, order.begin()};
        }
        else
        {
            // Update Old
            cache[key].first = value;
            order.erase(cache[key].second);
            order.push_front(key);
            cache[key].second = order.begin();
        }
    }
};

int main()
{
    vector<string> cmd = {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"};
    vector<vector<int>> value = {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}};
    LRUcache lr = LRUcache(value[0][0]);
    vector<int> result;
    result.push_back(9999);

    for (int i = 1; i < cmd.size(); i++)
    {
        if (cmd[i] == "get")
        {
            int temp = lr.get(value[i][0]);
            result.push_back(temp);
        }
        else if (cmd[i] == "put")
        {
            lr.put(value[i][0], value[i][1]);
            result.push_back(9999);
        }
    }
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}
// g++ file.cpp -o
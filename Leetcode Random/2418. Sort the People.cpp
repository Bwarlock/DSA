// You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

// For each index i, names[i] and heights[i] denote the name and height of the ith person.

// Return names sorted in descending order by the people's heights.

#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, string> &a, pair<int, string> &b)
{
    return (a.first > b.first);
}

vector<string> sortPeople(vector<string> &names, vector<int> &heights)
{
    vector<pair<int, string>> temp;
    vector<string> result;
    for (int i = 0; i < names.size(); i++)
    {
        temp.push_back({heights[i], names[i]});
    }
    sort(temp.begin(), temp.end(), comparator);
    for (int i = 0; i < names.size(); i++)
    {
        result.push_back(temp[i].second);
    }

    return result;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
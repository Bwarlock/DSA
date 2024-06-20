// In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

// Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

// Given the integer array position and the integer m. Return the required force.

#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<int> &position, int m)
{
    // Not
    sort(position.begin(), position.end());
    int l = 0;
    int r = (position.back() + position[0]) / (m - 1);

    int result = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (isValid(mid, position) >= m)
        {
            l = mid + 1;
            result = max(result, mid);
        }
        else
        {
            r = mid - 1;
        }
    }
    return result;
}
int isValid(int mid, vector<int> position)
{
    int total = 1;
    int curCup = position[0];
    for (int i = 1; i < position.size(); i++)
    {
        if (position[i] - curCup >= mid)
        {
            total++;
            curCup = position[i];
        }
    }
    return total;
}
int main()
{
    int m = 4;
    vector<int> position = {5, 4, 3, 2, 1, 1000000000};
    cout << maxDistance(position, m);
    cout << endl;
    return 0;
}
// g++ file.cpp -o
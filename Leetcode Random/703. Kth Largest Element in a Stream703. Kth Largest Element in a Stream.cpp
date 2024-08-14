// Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Implement KthLargest class:

// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
// int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
    int k;
    priority_queue<int, vector<int>, less<int>> pq;

public:
    KthLargest(int k, vector<int> &nums) : k(k), pq(less<int>(), nums)
    {
    }

    int add(int val)
    {
        vector<int> temp(this->k, 0);
        pq.push(val);
        for (int i = 0; i < k; i++)
        {
            temp[i] = this->pq.top();
            this->pq.pop();
        }
        for (int i = 0; i < k; i++)
        {
            this->pq.push(temp[i]);
        }
        return temp[k - 1];
    }
};

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
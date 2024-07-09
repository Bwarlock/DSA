// There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:

// arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
// timei is the time needed to prepare the order of the ith customer.
// When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.

// Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted.

#include <bits/stdc++.h>
using namespace std;

double averageWaitingTime(const vector<vector<int>> &customers)
{
    double result = 0;
    int idle = 1;
    for (int i = 0; i < customers.size(); ++i)
    {
        idle = max(idle, customers[i][0]);
        result += idle + customers[i][1] - customers[i][0];
        idle += customers[i][1];
    }
    return result / customers.size();
}

int main()
{
    cout << averageWaitingTime({{5, 2}, {5, 4}, {10, 3}, {20, 1}}) << endl;
    return 0;
}
// g++ file.cpp -o

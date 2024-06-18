// You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

// difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
// worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
// Every worker can be assigned at most one job, but one job can be completed multiple times.

// For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
// Return the maximum profit we can achieve after assigning the workers to the jobs.

#include <bits/stdc++.h>
using namespace std;

int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{
    // Time n + nLogn + mLongm + n + m
    vector<pair<int, int>> jobs;
    int maxProfit = 0;
    int result = 0;
    int j = 0;
    for (int i = 0; i < difficulty.size(); ++i)
    {
        jobs.push_back({difficulty[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end());
    sort(worker.begin(), worker.end());
    for (int i = 0; i < worker.size(); ++i)
    {
        while (j < jobs.size() && worker[i] >= jobs[j].first)
        {
            if (jobs[j].second > maxProfit)
            {
                maxProfit = jobs[j].second;
            }
            ++j;
        }
        result += maxProfit;
    }

    return result;
}
int main()
{
    vector<int> profits = {1, 2, 3};
    vector<int> diff = {1, 2, 3};
    vector<int> worker = {1, 1, 2};
    cout << maxProfitAssignment(diff, profits, worker);
    cout << endl;
    return 0;
}
// g++ file.cpp -o
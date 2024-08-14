// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> combination;
    combination2(result, combination, candidates, target, 0);
    return result;
}
void combination2(vector<vector<int>> &res, vector<int> &combination,
                  vector<int> &candidates, int target, int index)
{
    if (target == 0)
    {
        res.push_back(combination);
        return;
    }
    for (int i = index; i < candidates.size() && target >= candidates[i];
         ++i)
    {
        if (i == index || candidates[i] != candidates[i - 1])
        {
            combination.push_back(candidates[i]);
            combination2(res, combination, candidates,
                         target - candidates[i], i + 1);
            combination.pop_back();
        }
    }
}
int main()
{
    vector<int> cand = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    combinationSum2(cand, target);
    cout
        << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
// There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

// You have to form a team of 3 soldiers amongst them under the following rules:

// Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
// A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
// Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

#include <bits/stdc++.h>
using namespace std;

// int numTeams(vector<int> &rating)
// {
//     // brrute force
//     int length = rating.size();
//     // vector<int> dp(rating.size(), 1);
//     int result = 0;
//     for (int i = 0; i < length; i++)
//     {
//         for (int j = i + 1; j < length; j++)
//         {
//             for (int k = j + 1; k < length; k++)
//             {
//                 if ((rating[i] < rating[j] && rating[j] < rating[k]) || (rating[i] > rating[j] && rating[j] > rating[k]))
//                 {
//                     cout << i << k << j << endl;
//                     result++;
//                 }
//             }
//         }
//     }
//     return result;
// }

int numTeams(vector<int> &rating)
{
    // optimized with O(1) DP
    int length = rating.size();
    int result = 0;

    for (int i = 0; i < length; i++)
    {
        int leftSmaller = 0;
        int rightLarger = 0;

        for (int left = i - 1; left >= 0; left--)
        {
            if (rating[left] < rating[i])
            {
                leftSmaller++;
            }
        }

        for (int right = i + 1; right < length; right++)
        {
            if (rating[right] > rating[i])
            {
                rightLarger++;
            }
        }
        result += leftSmaller * rightLarger;

        result += leftSmaller * rightLarger;

        // Calculate soldiers with larger ratings on the left and smaller
        // ratings on the right
        int leftLarger = i - leftSmaller;
        int rightSmaller = length - i - 1 - rightLarger;

        // Calculate and add the number of descending rating teams
        // (large-mid-small)
        result += leftLarger * rightSmaller;
    }
    return result;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
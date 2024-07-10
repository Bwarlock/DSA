// The Leetcode file system keeps a log each time some user performs a change folder operation.

// The operations are described below:

// "../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
// "./" : Remain in the same folder.
// "x/" : Move to the child folder named x (This folder is guaranteed to always exist).
// You are given a list of strings logs where logs[i] is the operation performed by the user at the ith step.

// The file system starts in the main folder, then the operations in logs are performed.

// Return the minimum number of operations needed to go back to the main folder after the change folder operations.
#include <bits/stdc++.h>
using namespace std;

int minOperations(const vector<string> &logs)
{
    int result = 0;
    for (int i = 0; i < logs.size(); ++i)
    {
        if (logs[i] == "../")
        {
            if (result != 0)
            {
                --result;
            }
        }
        else if (logs[i] != "./")
        {
            ++result;
        }
    }
    return result;
}

int main()
{
    cout << minOperations({"d1/", "d2/", "../", "d21/", "./"}) << endl;
    return 0;
}
// g++ file.cpp -o
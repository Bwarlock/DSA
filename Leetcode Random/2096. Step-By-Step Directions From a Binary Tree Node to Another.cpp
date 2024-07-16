// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

// Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void backtrack(TreeNode *root, const int &startValue, const int &destValue, vector<char> &sValue, vector<char> &tValue, bool &sFound, bool &tFound)
{
    if (root->val == startValue)
    {
        sFound = true;
    }
    if (root->val == destValue)
    {
        tFound = true;
    }
    if (root->left != NULL)
    {

        if (!sFound)
        {
            sValue.push_back('L');
        }
        if (!tFound)
        {
            tValue.push_back('L');
        }
        if (!sFound || !tFound)
        {
            backtrack(root->left, startValue, destValue, sValue, tValue, sFound, tFound);
        }
        if (!sFound)
        {
            sValue.pop_back();
        }
        if (!tFound)
        {
            tValue.pop_back();
        }
    }

    if (root->right != NULL)
    {

        if (!sFound)
        {
            sValue.push_back('R');
        }
        if (!tFound)
        {
            tValue.push_back('R');
        }
        if (!sFound || !tFound)
        {
            backtrack(root->right, startValue, destValue, sValue, tValue, sFound, tFound);
        }
        if (!sFound)
        {
            sValue.pop_back();
        }
        if (!tFound)
        {
            tValue.pop_back();
        }
    }
}

string getDirections(TreeNode *root, const int &startValue, const int &destValue)
{
    string result = "";
    if (root == NULL)
    {
        return result;
    }
    vector<char> sValue;
    vector<char> tValue;
    bool sFound = false;
    bool tFound = false;
    backtrack(root, startValue, destValue, sValue, tValue, sFound, tFound);
    int i = 0, k = 0;
    int sLen = sValue.size();
    int tLen = tValue.size();

    while (i < sLen && k < tLen && sValue[i] == tValue[k])
    {
        cout << "hi" << endl;
        i++;
        k++;
    }
    while (i < sLen)
    {
        result += 'U';
        i++;
    }
    while (k < tLen)
    {
        result += tValue[k];
        k++;
    }
    return result;
}
int main()
{
    //          5
    //      1       2
    //  3          6    4
    TreeNode *t1;
    t1 = new TreeNode(5);
    t1->left = new TreeNode(1);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(3);
    t1->right->left = new TreeNode(6);

    t1->right->right = new TreeNode(4);

    cout << getDirections(t1, 2, 1) << endl;
    return 0;
}
// g++ file.cpp -o

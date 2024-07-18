// Given the root of a binary tree, each node in the tree has a distinct value.

// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

// Return the roots of the trees in the remaining forest. You may return the result in any order.

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

vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
{
    if (root == NULL)
    {
        return {};
    }
    vector<TreeNode *> result;
    queue<TreeNode *> Q;
    unordered_map<int, bool> deleteMap;
    unordered_map<int, bool> addMap;
    for (int i : to_delete)
    {
        deleteMap[i] = true;
    }
    TreeNode *temp = root;

    Q.push(temp);
    Q.push(NULL);
    if (deleteMap.find(temp->val) == deleteMap.end())
    {
        result.push_back(temp);
    }

    while (!Q.empty())
    {
        while (Q.front() != NULL)
        {
            temp = Q.front();
            Q.pop();
            if (deleteMap.find(temp->val) != deleteMap.end())
            {
                if (temp->left != NULL)
                {
                    Q.push(temp->left);
                    addMap[temp->left->val] = true;
                    temp->left = NULL;
                }
                if (temp->right != NULL)
                {
                    Q.push(temp->right);
                    addMap[temp->right->val] = true;
                    temp->right = NULL;
                }
            }
            else
            {
                if (addMap.find(temp->val) != addMap.end())
                {
                    result.push_back(temp);
                }
                if (temp->left != NULL)
                {
                    Q.push(temp->left);
                    if (deleteMap.find(temp->left->val) != deleteMap.end())
                    {
                        temp->left = NULL;
                    }
                }
                if (temp->right != NULL)
                {
                    Q.push(temp->right);
                    if (deleteMap.find(temp->right->val) != deleteMap.end())
                    {
                        temp->right = NULL;
                    }
                }
            }
        }
        Q.pop();
        if (!Q.empty())
        {
            Q.push(NULL);
        }
    }
    return result;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
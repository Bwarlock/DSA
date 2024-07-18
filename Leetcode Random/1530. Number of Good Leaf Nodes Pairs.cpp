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

void backtrack(TreeNode *root, int distance, unordered_map<TreeNode *, TreeNode *> &parent, int &result, TreeNode *backing)
{
    if (root == NULL || distance < 0)
    {
        return;
    }
    if (backing != NULL)
    {
        if (root->left == NULL && root->right == NULL && distance >= 0)
        {
            result++;
            return;
        }
        if (root->left != NULL && root->left != backing)
        {
            backtrack(root->left, distance - 1, parent, result, root);
        }
        if (root->right != NULL && root->right != backing)
        {
            backtrack(root->right, distance - 1, parent, result, root);
        }
        if (parent[root] != backing)
        {
            backtrack(parent[root], distance - 1, parent, result, root);
        }
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            backtrack(parent[root], distance - 1, parent, result, root);
        }
        if (root->left != NULL)
        {
            parent[root->left] = root;
            backtrack(root->left, distance, parent, result, NULL);
        }
        if (root->right != NULL)
        {
            parent[root->right] = root;
            backtrack(root->right, distance, parent, result, NULL);
        }
    }
}

int countPairs(TreeNode *root, const int distance)
{
    // dONT KNOW HOW BUT IT SOLVED ??? , ON  FIRST TRY , WAS SURE WOULD HAVE TO SPEND NEXT HOUR FIXING EDGE CASES
    unordered_map<TreeNode *, TreeNode *> parent;
    int result = 0;
    backtrack(root, distance, parent, result, NULL);
    return result / 2;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
// Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

// As a reminder, a binary search tree is a tree that satisfies these constraints:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *bstToGst(TreeNode *root)
{
    // Self put bad 3n
    // possible with morris traversal n , 1
    vector<int> inorder = {};
    stack<TreeNode *> stk;
    TreeNode *temp = root;
    while (true)
    {
        while (temp != NULL)
        {
            stk.push(temp);
            // L
            temp = temp->left;
        }

        if (stk.empty())
        {
            break;
        }

        // D
        inorder.push_back(stk.top()->val);

        // R
        temp = stk.top()->right;
        stk.pop();
    }

    for (int i = inorder.size() - 2; i >= 0; i--)
    {
        inorder[i] += inorder[i + 1];
    }

    int i = 0;
    temp = root;
    while (true)
    {
        while (temp != NULL)
        {
            stk.push(temp);
            // L
            temp = temp->left;
        }

        if (stk.empty())
        {
            break;
        }

        // D
        // inorder.push_back(stk.top()->val);

        stk.top()->val = inorder[i];
        i++;

        // R
        temp = stk.top()->right;
        stk.pop();
    }

    return root;
}
vector<int> inorderIterative(TreeNode *root)
{
    // 4 2 5 1 3 7
    if (root == NULL)
    {
        return {};
    }
    vector<int> result = {};
    stack<TreeNode *> stk;
    TreeNode *temp = root;
    while (true)
    {
        while (temp != NULL)
        {
            stk.push(temp);
            // result.push_back(temp->val);
            // L
            temp = temp->left;
        }

        if (stk.empty())
        {
            break;
        }

        // D
        result.push_back(stk.top()->val);

        // R
        temp = stk.top()->right;
        stk.pop();
    }
    return result;
}

int main()
{
    //          4
    //      2       6
    //  0   3           9
    TreeNode *t1;
    t1 = new TreeNode(4);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(6);
    t1->left->left = new TreeNode(0);
    t1->left->right = new TreeNode(3);

    t1->right->right = new TreeNode(9);
    // cout << diameter(t1) << endl;
    for (int i : inorderIterative(bstToGst(t1)))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
// g++ file.cpp -o
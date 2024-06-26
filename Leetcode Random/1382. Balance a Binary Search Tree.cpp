// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

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

void createLevel(TreeNode *&root, int low, int high, vector<int> &inorder)
{
    cout << low << " " << high << " yo ";
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    cout << mid << " hi " << endl;
    root = new TreeNode(inorder[mid]);
    createLevel(root->left, low, mid, inorder);
    createLevel(root->right, mid + 1, high, inorder);
}
TreeNode *balanceBST(TreeNode *root)
{
    // Self
    if (root == NULL)
    {
        return root;
    }
    vector<int> inorder = {};
    stack<TreeNode *> stk;
    TreeNode *temp = root;
    TreeNode *result;
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
        inorder.push_back(stk.top()->val);

        // R
        temp = stk.top()->right;
        stk.pop();
    }

    createLevel(result, 0, inorder.size(), inorder);
    cout << result->val << "lo";
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
    for (int i : inorderIterative(balanceBST(t1)))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
// g++ file.cpp -o
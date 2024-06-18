
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

// Binary Tree Traversles

// In   LDR
// Pre DLR
// Post LRD

// Recursion ::::
void inorder(TreeNode *root, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }
    // LDR
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

vector<int> inorder(TreeNode *root)
{
    vector<int> result;
    inorder(root, result);
    return result;
}

// Iteration ::::
vector<int> preorderIterative(TreeNode *root)
{
    // 1 2 4 5 3 7
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
            // D
            result.push_back(temp->val);
            // L
            temp = temp->left;
        }

        if (stk.empty())
        {
            break;
        }
        // R
        temp = stk.top()->right;
        stk.pop();
    }
    return result;
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

vector<int> postOrderIterative(TreeNode *root)
{
    // 4 5 2 7 3 1
    //  Whatever Abomination This is LOL
    //  OK sO The best 1 stack code isnt looking any better than mine So whatever
    if (root == NULL)
    {
        return {};
    }
    vector<int> result = {};
    stack<TreeNode *> stk;
    TreeNode *temp = root;
    while (true)
    {
        if (!stk.empty() && temp == stk.top())
        {
            // IF Right was Not Choosen , that is ->Val was pushed without updating the temp
            // so now we need to go right instead of left of stk.top()  , so skipping left loop
            stk.pop();
        }
        else
        {
            while (temp != NULL)
            {
                stk.push(temp);
                // L
                temp = temp->left;
            }
            temp = stk.top();
        }

        if (stk.empty())
        {
            break;
        }

        // R
        if (stk.top()->right != NULL && stk.top()->right != temp)
        {
            temp = stk.top()->right;
        }
        else
        {
            // D
            result.push_back(stk.top()->val);
            temp = stk.top();
        }
    }
    return result;
}

// BFS
int height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + max(height(root->left), height(root->right));
    }
}

void traverseLevel(TreeNode *root, int level, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 0)
    {
        result.push_back(root->val);
        return;
    }
    else
    {
        traverseLevel(root->left, level - 1, result);
        traverseLevel(root->right, level - 1, result);
    }
}

// Recursion ::::
vector<int> levelOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }

    int H = height(root);
    vector<int> result;
    for (int h = 0; h < H; h++)
    {
        traverseLevel(root, h, result);
    }
    return result;
}

// Iteration ::::
vector<int> levelOrderIterative(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<int> result;
    queue<TreeNode *> Q;
    Q.push(root);
    Q.push(NULL);
    while (!Q.empty())
    {
        if (Q.front() == NULL)
        {
            // Current Level Traversed
            Q.pop();
            if (!Q.empty())
            {
                Q.push(NULL);
            }
        }
        else
        {
            root = Q.front();
            Q.pop();
            result.push_back(root->val);
            if (root->left != NULL)
            {
                Q.push(root->left);
            }
            if (root->right != NULL)
            {
                Q.push(root->right);
            }
        }
    }
    return result;
}

int main()
{
    //          1
    //      2       3
    //  4   5           7
    TreeNode *t1;
    t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->left->left = new TreeNode(4);
    t1->left->right = new TreeNode(5);

    t1->right->right = new TreeNode(7);
    for (int i : postOrderIterative(t1))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
// g++ file.cpp -o
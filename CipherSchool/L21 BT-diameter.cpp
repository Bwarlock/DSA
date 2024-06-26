
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

int diameter(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh + rh + 1, max(diameter(root->left), diameter(root->left)));
}

int diameterOptimized(TreeNode *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0, ld = 0, rd = 0;
    ld = diameterOptimized(root->left, &lh);
    rd = diameterOptimized(root->right, &rh);
    return max(lh + rh + 1, max(ld, rd));
}

vector<int> zigzagLevelOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<int> result;
    queue<TreeNode *> Q;
    int level = 0;
    Q.push(root);
    Q.push(NULL);
    while (!Q.empty())
    {
        vector<int> temp;
        while (Q.front() != NULL)
        {
            root = Q.front();
            Q.pop();
            temp.push_back(root->val);
            if (root->left != NULL)
            {
                Q.push(root->left);
            }
            if (root->right != NULL)
            {
                Q.push(root->right);
            }
        }
        if (level & 1)
        {
            for (auto it = temp.rbegin(); it != temp.rend(); ++it)
            {
                result.push_back(*it);
            }
        }
        else
        {
            for (auto it = temp.begin(); it != temp.end(); ++it)
            {
                result.push_back(*it);
            }
        }
        Q.pop();
        level++;
        if (!Q.empty())
        {
            Q.push(NULL);
        }
    }
    return result;
}

void inorder(TreeNode *root, map<int, vector<int>> &leveledResult, int level, int *lw, int *rw)
{
    if (root == NULL)
    {
        return;
    }
    // LDR
    inorder(root->left, leveledResult, level - 1, lw, rw);
    leveledResult[level].push_back(root->val);

    if (level < *lw)
    {
        *lw = level;
    }
    if (level > *rw)
    {
        *rw = level;
    }
    cout << root->val << " at level " << level << endl;
    inorder(root->right, leveledResult, level + 1, lw, rw);
}

vector<int> verticalOrder(TreeNode *root)
{
    // Using Inorder Recursive

    vector<int> result;
    map<int, vector<int>> leveledResult;
    int lw = 0;
    int rw = 0;
    inorder(root, leveledResult, 0, &lw, &rw);
    for (int i = lw; i <= rw; i++)
    {
        // Concat only first element to result
        result.insert(result.end(), leveledResult[i].begin(), leveledResult[i].end());
    }
    return result;
}

vector<int> leftView(TreeNode *root)
{
    // Using LevelOrder
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
        result.push_back(Q.front()->val);
        while (Q.front() != NULL)
        {
            root = Q.front();
            Q.pop();
            if (root->left != NULL)
            {
                Q.push(root->left);
            }
            if (root->right != NULL)
            {
                Q.push(root->right);
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
vector<int> rightView(TreeNode *root)
{
    // Using LevelOrder
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
        vector<int> temp;
        while (Q.front() != NULL)
        {
            root = Q.front();
            Q.pop();
            temp.push_back(root->val);
            if (root->left != NULL)
            {
                Q.push(root->left);
            }
            if (root->right != NULL)
            {
                Q.push(root->right);
            }
        }
        result.push_back(temp.back());
        Q.pop();
        if (!Q.empty())
        {
            Q.push(NULL);
        }
    }
    return result;
}
vector<int> topView(TreeNode *root)
{
    // Using Inorder Recursive
    vector<int> result;
    map<int, vector<int>> leveledResult;
    int lw = 0;
    int rw = 0;
    inorder(root, leveledResult, 0, &lw, &rw);
    for (int i = lw; i <= rw; i++)
    {
        // Concat only first element to result
        result.push_back(leveledResult[i].back());
    }
    return result;
}
vector<int> bottomView(TreeNode *root)
{
    // Using Inorder Recursive
    vector<int> result;
    map<int, vector<int>> leveledResult;
    int lw = 0;
    int rw = 0;
    inorder(root, leveledResult, 0, &lw, &rw);
    for (int i = lw; i <= rw; i++)
    {
        // Concat only first element to result
        result.push_back(leveledResult[i][0]);
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
    // cout << diameter(t1) << endl;
    for (int i : rightView(t1))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
// g++ file.cpp -o
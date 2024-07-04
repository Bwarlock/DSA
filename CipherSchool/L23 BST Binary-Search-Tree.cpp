
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

void nodeBetweenRange(TreeNode *root, pair<int, int> &range, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }

    if (root->val < range.first)
    {
        nodeBetweenRange(root->right, range, result);
    }
    else if (root->val > range.second)
    {
        nodeBetweenRange(root->left, range, result);
    }
    else
    {
        nodeBetweenRange(root->left, range, result);
        result.push_back(root->val);
        nodeBetweenRange(root->right, range, result);
    }
}

vector<int> nodeBetweenRange(TreeNode *root, pair<int, int> &range)
{
    if (root == NULL)
    {
        return {};
    }
    vector<int> result = {};
    nodeBetweenRange(root, range, result);
    return result;
}

bool checkIfBst(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    stack<TreeNode *> stk;
    TreeNode *temp = root;
    TreeNode *prev = NULL;
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
        if (prev != nullptr)
        {
            if (prev->val > stk.top()->val)
            {
                return false;
            }
            prev = stk.top();
        }
        else
        {
            prev = stk.top();
        }
        // R
        temp = stk.top()->right;
        stk.pop();
    }
    return true;
}

TreeNode *bstFromPreorder(vector<int> &preorder, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    TreeNode *node = new TreeNode(preorder[start]);

    int index = start;
    for (int i = start; i <= end; i++)
    {
        if (preorder[i] > node->val)
        {
            index = i - 1;
            break;
        }
    }
    node->left = bstFromPreorder(preorder, start + 1, index);
    node->right = bstFromPreorder(preorder, index + 1, end);
    return node;
}

// every node is balanced
int balancedBinaryTree(TreeNode *root, bool &result)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = balancedBinaryTree(root->left, result);
    int right = balancedBinaryTree(root->right, result);
    if (abs(left - right) > 1)
    {
        result = false;
    }
    return 1 + max(left, right);
}

bool balancedBinaryTree(TreeNode *root)
{
    bool result = true;
    balancedBinaryTree(root, result);
    return result;
}

void createLevel(TreeNode *&root, int low, int high, vector<int> &inorder)
{

    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    root = new TreeNode(inorder[mid]);
    createLevel(root->left, low, mid, inorder);
    createLevel(root->right, mid + 1, high, inorder);
}

TreeNode *bstFromSortedArray(vector<int> &arr)
{
    TreeNode *node = NULL;
    createLevel(node, 0, arr.size(), arr);
    return node;
}

TreeNode *leastCommonAncestorOfBST(TreeNode *root, const int &left, const int &right)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->val > left && root->val < right)
    {
        return root;
    }
    else if (root->val < left)
    {
        return leastCommonAncestorOfBST(root->right, left, right);
    }
    else if (root->val > right)
    {
        return leastCommonAncestorOfBST(root->left, left, right);
    }
    return NULL;
}

// Catlann formula 1 , 1, 2 , 5
// ( 2n C n ) / (n+1)
// dp problem  , count given n , all possible bst's for 1 till n numbers array

// 1 , 0 give 1
// 2 give n(0)n(1) + n(1)n(0)
// 3 give n(0)n(2) + n(1)n(1) + n(2)n(0)

// Return all unique binary search trees

// vector<TreeNode *> uniqueBstArray(int n) {}
vector<int> cousinOfNodes(TreeNode *root, TreeNode *node)
{
    if (root == NULL)
    {
        return {};
    }
    TreeNode *temp;
    bool check = false;
    vector<int> result;
    queue<TreeNode *> Q;
    Q.push(root);
    Q.push(NULL);
    while (!Q.empty())
    {
        if (check)
        {
            while (Q.front() != NULL)
            {
                temp = Q.front();
                Q.pop();
                result.push_back(temp->val);
            }
            Q.pop();
            break;
        }
        while (Q.front() != NULL)
        {
            temp = Q.front();
            Q.pop();
            if (temp->left == node || temp->right == node)
            {
                check = true;
            }
            else
            {
                if (temp->left != NULL)
                {
                    Q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    Q.push(temp->right);
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

void nodesAtKdistance(vector<int> &level, vector<int> &result, int index, const int &k, int count, bool left, bool right, bool parent)
{
    if (index < 0 || index >= level.size())
    {
        cout << index << endl;
        return;
    }
    if (count == k)
    {
        cout << left << right << parent << index << endl;
        if (level[index] != -1)
        {
            result.push_back(level[index]);
        }
        return;
    }
    if (!left)
    {
        cout << index << "left" << endl;
        nodesAtKdistance(level, result, 2 * index + 1, k, count + 1, false, false, true);
    }
    if (!right)
    {
        cout << index << "right" << endl;
        nodesAtKdistance(level, result, 2 * index + 2, k, count + 1, false, false, true);
    }
    if (!parent)
    {
        double parentIndex = (index - 1) / (double)2;
        cout << index << !(index & 1) << parentIndex << endl;
        if (parentIndex >= 0)
        {
            nodesAtKdistance(level, result, parentIndex, k, count + 1, index & 1, !(index & 1), false);
        }
    }
}

vector<int> nodesAtKdistance(TreeNode *root, TreeNode *node, const int k)
{
    if (root == NULL)
    {
        return {};
    }
    int ht = height(root);
    int size = pow(2, ht) - 1;
    vector<int> level(size, -1);
    vector<int> result;
    int index = -1;

    pair<TreeNode *, int> temp;
    queue<pair<TreeNode *, int>> Q;
    Q.push({root, 0});
    Q.push({NULL, 0});
    while (!Q.empty())
    {
        while (Q.front().first != NULL)
        {
            temp = Q.front();
            Q.pop();
            level[temp.second] = temp.first->val;
            if (temp.first == node)
            {
                index = temp.second;
            }
            if (temp.first->left != NULL)
            {
                Q.push({temp.first->left, 2 * temp.second + 1});
            }
            if (temp.first->right != NULL)
            {
                Q.push({temp.first->right, 2 * temp.second + 2});
            }
        }
        Q.pop();
        if (!Q.empty())
        {
            Q.push({NULL, 0});
        }
    }
    for (int i : level)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << index << "hi" << endl;
    nodesAtKdistance(level, result, index, k, 0, false, false, false);
    return result;
}

// DP
// optimalBinarySearchTree(vector<int>& nodes,vector<int>& cost){}

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
    pair<int, int> p = {2, 8};
    vector<int> result = preorderIterative(t1);
    vector<int> sortedArr = {1, 2, 3, 4, 5, 6};
    for (int i : nodesAtKdistance(t1, t1->left, 3))
    {
        cout << i << " ";
    }
    cout << endl;
    // cout << checkIfBst(t1) << endl;
    // cout << balancedBinaryTree(t1) << endl;
    // cout << leastCommonAncestorOfBST(t1, 0, 3)->val << endl;
    return 0;
}
// g++ file.cpp -o
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

void maxPath(TreeNode *root, int sum, int &maxSum)
{
    if (root == NULL)
    {
        return;
    }
    sum = sum + root->val;
    if (root->left == NULL && root->right == NULL)
    {
        maxSum = max(maxSum, sum);
    }
    maxPath(root->left, sum, maxSum);
    maxPath(root->right, sum, maxSum);
}

int maxPath(TreeNode *root)
{
    // ROOT -> LEAF
    int maxSum = 0;
    maxPath(root, 0, maxSum);
    return maxSum;
}

int leafToLeafMaxSum(TreeNode *root, int *maxSum)
{
    if (root == NULL)
    {
        return 0;
    }
    int lSum = 0, rSum = 0;
    if (root->left == NULL && root->right == NULL)
    {
        return root->val;
    }
    else if (root->left != NULL && root->right != NULL)
    {
        lSum = leafToLeafMaxSum(root->left, maxSum);
        rSum = leafToLeafMaxSum(root->right, maxSum);
        *maxSum = max(*maxSum, root->val + lSum + rSum);

        return root->val + max(lSum, rSum);
    }
    else
    {
        lSum = leafToLeafMaxSum(root->left, maxSum);
        rSum = leafToLeafMaxSum(root->right, maxSum);
        return root->val + (lSum == 0 ? rSum : lSum);
    }
}

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

TreeNode *buildTree(vector<int> &inorder, vector<int> &preorder, int start, int end, int &curr)
{
    if (start > end)
    {
        return NULL;
    }
    TreeNode *newNode = new TreeNode(preorder[curr]);
    curr++;
    if (start == end)
    {
        return newNode;
    }
    else
    {
        int index = -1;
        for (int i = start; i <= end; i++)
        {
            if (inorder[i] == newNode->val)
            {
                index = i;
                break;
            }
        }
        newNode->left = buildTree(inorder, preorder, start, index - 1, curr);
        newNode->right = buildTree(inorder, preorder, index + 1, end, curr);
    }
    return newNode;
}

TreeNode *buildTreePostOrder(vector<int> &inorder, vector<int> &postorder, int start, int end, int &curr)
{
    if (start > end)
    {
        return NULL;
    }
    TreeNode *newNode = new TreeNode(postorder[curr]);
    curr--;
    if (start == end)
    {
        return newNode;
    }
    else
    {
        int index = -1;
        for (int i = start; i <= end; i++)
        {
            if (inorder[i] == newNode->val)
            {
                index = i;
                break;
            }
        }
        newNode->right = buildTreePostOrder(inorder, postorder, index + 1, end, curr);
        newNode->left = buildTreePostOrder(inorder, postorder, start, index - 1, curr);
    }
    return newNode;
}

void rootToLeafPath(TreeNode *root, vector<vector<int>> &paths, vector<int> &pathSoFar)
{
    if (root == NULL)
    {
        return;
    }
    pathSoFar.push_back(root->val);
    if (root->left == NULL && root->right == NULL)
    {
        paths.push_back(pathSoFar);
    }
    else
    {
        rootToLeafPath(root->left, paths, pathSoFar);
        rootToLeafPath(root->right, paths, pathSoFar);
    }
    pathSoFar.pop_back();
}

vector<vector<int>> rootToLeafPath(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<vector<int>> paths;
    vector<int> pathSoFar;
    rootToLeafPath(root, paths, pathSoFar);
    return paths;
}

vector<int> ancestorOfNode(TreeNode *root) {}
TreeNode *LCA_Of_BT(TreeNode *root) {}
void doubly_LinkList_From_Preorder(TreeNode *root) {}
void doubly_LinkList_From_Inorder(TreeNode *root) {}
void populateRandomPointer(TreeNode *root) {}
int main()
{
    //          1
    //      2       3
    //  4   5           7
    int curr = 5;
    vector<int> inorde = {4, 2, 5, 1, 3, 7};
    vector<int> preorder = {1, 2, 4, 5, 3, 7};
    vector<int> postorder = {4, 5, 2, 7, 3, 1};
    TreeNode *t1 = buildTreePostOrder(inorde, postorder, 0, 5, curr);
    cout << t1->right->right->val << endl;
    for (int i : inorder(t1))
    {
        cout << i << " ";
    }
    cout << endl;
    for (vector<int> k : rootToLeafPath(t1))
    {
        for (int i : k)
        {
            cout << i << " ";
        }
    }

    // TreeNode *t1;
    // t1 = new TreeNode(1);
    // t1->left = new TreeNode(2);
    // t1->right = new TreeNode(3);
    // t1->left->left = new TreeNode(4);
    // t1->left->right = new TreeNode(5);

    // t1->right->right = new TreeNode(7);
    // int *maxSum;
    // *maxSum = 0;
    // cout << leafToLeafMaxSum(t1, maxSum);
    cout << endl;
    return 0;
}
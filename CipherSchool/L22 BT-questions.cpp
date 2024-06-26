#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *random;
    TreeNode() : val(0), random(nullptr), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), random(nullptr), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), random(nullptr), left(left), right(right) {}
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

bool ancestorOfNode(TreeNode *root, TreeNode *node, vector<int> &ancestors)
{
    if (root == NULL)
    {
        return false;
    }
    if (root == node)
    {
        return true;
    }
    ancestors.push_back(root->val);
    if (ancestorOfNode(root->left, node, ancestors) ||
        ancestorOfNode(root->right, node, ancestors))
    {
        return true;
    }
    ancestors.pop_back();
    return false;
}

vector<int> ancestorOfNode(TreeNode *root, TreeNode *node)
{
    if (root == NULL)
    {
        return {};
    }
    vector<int> ancestors;
    ancestorOfNode(root, node, ancestors);
    return ancestors;
}

bool LCA_Of_BT(TreeNode *root, TreeNode *node1, TreeNode *node2, TreeNode *&common)
{
    if (root == NULL)
    {
        return false;
    }
    if (root == node1 || root == node2)
    {
        return true;
    }
    bool left = LCA_Of_BT(root->left, node1, node2, common);
    bool right = LCA_Of_BT(root->right, node1, node2, common);
    if (left && right)
    {
        common = root;
    }
    if (left || right)
    {
        return true;
    }
    return false;
}

TreeNode *LCA_Of_BT(TreeNode *root, TreeNode *node1, TreeNode *node2)
{
    if (root == NULL)
    {
        return NULL;
    }
    TreeNode *common;
    LCA_Of_BT(root, node1, node2, common);
    return common;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : val(x), prev(prev), next(next) {}
};

ListNode *doubly_LinkList_From_Preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    // vector<int> result = {};
    stack<TreeNode *> stk;
    TreeNode *temp = root;
    ListNode *start = NULL;
    ListNode *prev = NULL;
    ListNode *curr = NULL;
    while (true)
    {

        while (temp != NULL)
        {
            stk.push(temp);
            // D
            // result.push_back(temp->val);
            if (curr != nullptr)
            {
                prev = curr;
                curr = new ListNode(temp->val);
                curr->prev = prev;
                prev->next = curr;
            }
            else
            {
                curr = new ListNode(temp->val);
                start = curr;
            }
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
    return start;
}
ListNode *doubly_LinkList_From_Inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    // vector<int> result = {};
    stack<TreeNode *> stk;
    TreeNode *temp = root;
    ListNode *start = NULL;
    ListNode *prev = NULL;
    ListNode *curr = NULL;
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
        // result.push_back(stk.top()->val);
        if (curr != nullptr)
        {
            prev = curr;
            curr = new ListNode(stk.top()->val);
            curr->prev = prev;
            prev->next = curr;
        }
        else
        {
            curr = new ListNode(stk.top()->val);
            start = curr;
        }
        // R
        temp = stk.top()->right;
        stk.pop();
    }
    return start;
}

void populateRandomPointer(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    vector<int> result;
    queue<TreeNode *> Q;
    TreeNode *temp = root;
    TreeNode *prev = NULL;
    TreeNode *curr = NULL;
    Q.push(temp);
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
            curr = NULL;
        }
        else
        {
            while (Q.front() != NULL)
            {
                temp = Q.front();
                Q.pop();
                if (temp->left != NULL)
                {
                    Q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    Q.push(temp->right);
                }
                if (curr != nullptr)
                {
                    prev = curr;
                    curr = temp;
                    prev->random = curr;
                }
                else
                {
                    curr = temp;
                }
            }
        }
    }
    return;
}

vector<TreeNode *> iterate(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<TreeNode *> result;
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
            result.push_back(root);
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
    int curr = 5;
    vector<int> inorde = {4, 2, 5, 1, 3, 7};
    vector<int> preorder = {1, 2, 4, 5, 3, 7};
    vector<int> postorder = {4, 5, 2, 7, 3, 1};
    TreeNode *t1 = buildTreePostOrder(inorde, postorder, 0, 5, curr);
    for (int i : inorder(t1))
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i : ancestorOfNode(t1, t1->right->right))
    {
        cout << i << " ";
    }
    cout << endl;
    // cout << LCA_Of_BT(t1, t1->left->left, t1->right->right)->val;
    // cout << endl;

    ListNode *head = doubly_LinkList_From_Inorder(t1);
    while (head != NULL)
    {
        cout << head->val << "hi ";
        head = head->next;
    }
    cout << endl;
    populateRandomPointer(t1);

    for (TreeNode *i : iterate(t1))
    {
        if (i->random != nullptr)
        {
            cout << i->val << " " << i->random->val << endl;
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
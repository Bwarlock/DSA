// You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

// If isLefti == 1, then childi is the left child of parenti.
// If isLefti == 0, then childi is the right child of parenti.
// Construct the binary tree described by descriptions and return its root.

// The test cases will be generated such that the binary tree is valid.

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

void createNode(unordered_map<int, TreeNode *> &track, vector<int> &i)
{
    if (i[2] == 1)
    {
        if (track.find(i[1]) == track.end())
        {
            track[i[1]] = new TreeNode(i[1]);
        }
        track[i[0]]->left = track[i[1]];
    }
    if (i[2] == 0)
    {
        if (track.find(i[1]) == track.end())
        {
            track[i[1]] = new TreeNode(i[1]);
        }
        track[i[0]]->right = track[i[1]];
    }
}

TreeNode *createBinaryTree(const vector<vector<int>> &descriptions)
{
    unordered_map<int, TreeNode *> track;
    vector<int> roots;
    for (vector<int> i : descriptions)
    {
        if (track.find(i[0]) != track.end())
        {
            createNode(track, i);
        }
        else
        {
            track[i[0]] = new TreeNode(i[0]);
            roots.push_back(i[0]);
            createNode(track, i);
        }
        auto it = find(roots.begin(), roots.end(), i[1]);

        if (it != roots.end())
        {
            roots.erase(it);
        }
    }
    return track[roots[0]];
}

int main()
{
    cout << createBinaryTree({{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}})->val << endl;
    return 0;
}
// g++ file.cpp -o
// A critical point in a linked list is defined as either a local maxima or a local minima.

// A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

// A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

// Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

// Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    int index = 1;
    int prevCrit = 0;
    int minDistance = INT_MAX;
    int firstCrit = 0;
    vector<int> result = {INT_MAX, INT_MIN};

    ListNode *prevNode = head;
    head = head->next;
    int temp;
    while (head != NULL)
    {
        index++;
        if (head->next != NULL)
        {
            if ((prevNode->val < head->val && head->val > head->next->val) || (prevNode->val > head->val && head->val < head->next->val))
            {
                cout << prevCrit << " " << minDistance << " " << index << endl;
                if (!firstCrit)
                {
                    firstCrit = index;
                }
                else
                {
                    temp = index - prevCrit;
                    if (temp < minDistance)
                    {
                        minDistance = temp;
                    }
                }
                prevCrit = index;
            }
        }
        prevNode = head;
        head = head->next;
    }
    if (index < 4 || minDistance == INT_MAX)
    {
        return {-1, -1};
    }

    return {minDistance, prevCrit - firstCrit};
}

int main()
{
    ListNode *head;
    ListNode *n1;
    ListNode *n2;
    ListNode *n3;
    ListNode *n4;
    ListNode *n5;
    n5 = new ListNode(0, NULL);
    n4 = new ListNode(5, n5);
    n3 = new ListNode(2, n4);
    n2 = new ListNode(0, n3);
    n1 = new ListNode(4, n2);

    vector<int> result = nodesBetweenCriticalPoints(n1);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
// g++ file.cpp -o
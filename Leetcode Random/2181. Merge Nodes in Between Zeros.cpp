// You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

// For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

// Return the head of the modified linked list.
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

ListNode *mergeNodes(ListNode *head)
{
    // Too easy Medium question
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    ListNode *result = head;
    ListNode *temp;
    while (head->next != NULL)
    {
        temp = head;
        head = head->next;
        while (head->val != 0)
        {
            temp->val += head->val;
            head = head->next;
        }
        temp->next = head;
    }
    temp->next = NULL;
    return result;
}

int main()
{
    ListNode *head;
    ListNode *n1;
    ListNode *n2;
    ListNode *n3;
    ListNode *n4;
    n4 = new ListNode(0, NULL);
    n3 = new ListNode(2, n4);
    n2 = new ListNode(1, n3);
    n1 = new ListNode(0, n2);

    head = mergeNodes(n1);
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
// g++ file.cpp -o
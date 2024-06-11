#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    T val;
    Node<T> *next;
    Node()
    {
        next = NULL;
    }
    Node(T it)
    {
        val = it;
    }
    Node(T it, Node<T> *nex)
    {
        val = it;
        next = nex;
    }
};

template <class T>
Node<T> *RemoveDuplicateSorted(Node<T> *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node<T> *curr = head, *next = head->next;
    while (next != NULL)
    {
        if (curr->val == next->val)
        {
            curr->next = next->next;
            delete (next);
            next = curr->next;
        }
        else
        {
            curr = curr->next;
            next = next->next;
        }
    }
    return head;
};

template <class T>
Node<T> *RemoveDuplicateUnSorted(Node<T> *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    set<T> check;
    Node<T> *curr = head, *prev = NULL;
    while (curr != NULL)
    {
        if (check.find(curr->val) != check.end())
        {
            prev->next = curr->next;
            delete (curr);
            curr = prev->next;
        }
        else
        {
            check.insert(curr->val);
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
};

template <class T>
Node<T> *RemoveAllDuplicateSorted(Node<T> *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node<T> *dummy;
    dummy = new Node<T>();
    dummy->next = head;
    Node<T> *curr = head, *prev = dummy;

    while (curr != NULL)
    {
        if (curr->next != NULL && curr->val == curr->next->val)
        {
            while (curr->next != NULL && curr->val == curr->next->val)
            {
                prev->next = curr->next;
                delete (curr);
                curr = prev->next;
            }
            prev->next = curr->next;
            delete (curr);
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy->next;
};

int main()
{
    Node<int> *head;
    Node<int> *n1;
    Node<int> *n2;
    Node<int> *n3;
    Node<int> *n4;
    n4 = new Node<int>(3, NULL);
    n3 = new Node<int>(3, n4);
    n2 = new Node<int>(3, n3);
    n1 = new Node<int>(1, n2);

    head = RemoveAllDuplicateSorted(n1);
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
// g++ file.cpp -o
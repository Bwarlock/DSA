#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    T val;
    Node<T> *next;
    Node<T> *random;
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
    Node(T it, Node<T> *nex, Node<T> *ran)
    {
        val = it;
        next = nex;
        random = ran;
    }
};

template <class T>
Node<T> *copyLinkedListMap(Node<T> *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node<T> dummy;
    Node<T> *ptr = head, *clone = &dummy;
    unordered_map<Node<T> *, Node<T> *> hash;

    while (ptr != NULL)
    {
        clone->next = new Node<T>(ptr->val);
        clone = clone->next;
        hash[ptr] = clone;
        ptr = ptr->next;
    }
    clone->next = NULL;

    ptr = head;
    clone = dummy.next;
    while (ptr != NULL)
    {
        clone->random = hash[ptr->random];
        clone = clone->next;
        ptr = ptr->next;
    }

    return dummy.next;
};

template <class T>
Node<T> *copyLinkedListNoMap(Node<T> *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node<T> *ptr = head, *qtr = NULL, *clone;

    while (ptr != NULL)
    {
        qtr = ptr->next;
        Node<T> *newNode = new Node<T>(ptr->val);
        ptr->next = newNode;
        newNode->next = qtr;

        ptr = qtr;
    }
    ptr = head, qtr = NULL, clone = head->next;
    while (ptr != NULL)
    {
        qtr = ptr->next;

        if (ptr->random)
        {
            qtr->random = ptr->random->next;
        }
        else
        {
            qtr->random = NULL;
        }

        ptr->next = qtr->next;
        ptr = ptr->next;
        if (ptr)
        {
            qtr->next = ptr->next;
            qtr = qtr->next;
        }
        else
        {
            qtr->next = NULL;
        }
    }

    return clone;
};

int main()
{
    Node<int> *head;
    Node<int> *n1;
    Node<int> *n2;
    Node<int> *n3;
    Node<int> *n4;
    n4 = new Node<int>(4, NULL, NULL);
    n3 = new Node<int>(3, n4, n4);
    n2 = new Node<int>(2, n3, n4);
    n1 = new Node<int>(1, n2, n3);

    head = copyLinkedListNoMap(n1);
    while (head != NULL)
    {
        cout << head->val << ",";
        cout << (head->random ? head->random->val : 0) << " ";
        head = head->next;
    }
    return 0;
}
// g++ file.cpp -o
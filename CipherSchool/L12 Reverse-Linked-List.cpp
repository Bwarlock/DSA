#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    T item;
    Node *next;
    Node()
    {
        next = NULL;
    }
    Node(T it)
    {
        item = it;
    }
    Node(T it, Node *nex)
    {
        item = it;
        next = nex;
    }
};

template <class T>
Node<T> *reverseLinkedList(Node<T> *list)
{
    if (list == NULL)
    {
        return NULL;
    }
    Node<T> *prev = NULL;
    Node<T> *curr = list;
    Node<T> *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list = prev;
    return prev;
};

template <class T>
Node<T> *reverseInGroupLinkedList(Node<T> *head, int group)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node<T> *prev = NULL;
    Node<T> *curr = head;
    Node<T> *next = NULL;
    int k = 0;
    while (curr != NULL && k < group)
    {
        k++;
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if (curr != NULL)
    {
        head->next = reverseInGroupLinkedList(curr, group);
    }
    return prev;
}

int main()
{
    Node<int> *head;
    Node<int> *n1;
    Node<int> *n2;
    Node<int> *n3;
    Node<int> *n4;
    n1 = new Node<int>();
    n2 = new Node<int>();
    n3 = new Node<int>();
    n4 = new Node<int>();

    n1->item = 2;
    n2->item = 3;
    n3->item = 4;
    n4->item = 5;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    head = reverseInGroupLinkedList<int>(n1, 2);
    while (head != NULL)
    {
        cout << head->item << " ";
        head = head->next;
    }
    return 0;
}
// g++ file.cpp -o
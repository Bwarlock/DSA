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
Node<T> *reorderLL(Node<T> *head, int K)
{
    if (head == NULL || head->next == NULL || K == 0)
    {
        return head;
    }
    Node<T> *fast = head;
    Node<T> *slow = head;
    int count = 0;
    while (fast != NULL && count < K)
    {
        count++;
        fast = fast->next;
    }
    if (fast == NULL)
    {
        return head;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = head;
    head = slow->next;
    slow->next = NULL;
    return head;
};

int main()
{
    Node<int> *head;
    Node<int> *n1;
    Node<int> *n2;
    Node<int> *n3;
    Node<int> *n4;
    n4 = new Node<int>(3, NULL);
    n3 = new Node<int>(2, n4);
    n2 = new Node<int>(1, n3);
    n1 = new Node<int>(0, n2);

    head = reorderLL(n1, 2);
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
// g++ file.cpp -o
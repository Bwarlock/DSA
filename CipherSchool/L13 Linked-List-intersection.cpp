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
Node<int> *intersectionLL(Node<T> *n, Node<T> *m) // time:O(n+m+n)  space:O(4)
{
    int sizeN = 0;
    int sizeM = 0;
    Node<T> *head = n;
    Node<T> *head2 = m;
    while (head != NULL)
    {
        sizeN++;
        head = head->next;
    }
    head = m;
    while (head != NULL)
    {
        sizeM++;
        head = head->next;
    }

    head = n;
    head2 = m;
    if (sizeN < sizeM)
    {
        while (sizeN < sizeM)
        {
            head2 = head2->next;
            sizeM--;
        }
    }
    else
    {
        while (sizeN > sizeM)
        {
            head = head->next;
            sizeN--;
        }
    }

    while (head != head2)
    {
        head = head->next;
        head2 = head2->next;
    }

    return head;
};

template <class T>
Node<int> *intersectionLLSpace(Node<T> *n, Node<T> *m) // time:O(n+m)  space:O(n)
{
    set<Node<int> *> check;

    Node<T> *head = n;
    while (head != NULL)
    {
        check.insert(head);
        head = head->next;
    }
    head = m;
    while (head != NULL)
    {
        if (check.find(head) != check.end())
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
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
    n2 = new Node<int>(9, n3);
    n1 = new Node<int>(0, n2);

    Node<int> *m1;
    Node<int> *m2;
    Node<int> *m3;
    m3 = new Node<int>(3, n2);
    m2 = new Node<int>(2, m3);
    m1 = new Node<int>(1, m2);

    Node<int> *inter = intersectionLL<int>(n1, m1);
    if (inter != NULL)
    {
        cout << "Intersection : " << inter->val << endl;
    }
    else
    {
        cout << "No Intersection" << endl;
    }
    head = n1;
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    head = m1;
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
// g++ file.cpp -o
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

// Recursive Solution
template <class T>
Node<T> *mergeTwoLists(Node<T> *a, Node<T> *b)
{
    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }
    else
    {
        Node<T> *result;
        if (a->item <= b->item)
        {
            result = a;
            result->next = mergeTwoLists(a->next, b);
        }
        else
        {
            result = b;
            result->next = mergeTwoLists(a, b->next);
        }
        return result;
    }
};

// Iterative Solution , Merge Sort n*k*log(n)
template <class T>
Node<T> *mergeLists(vector<Node<T> *> list)
{
    if (list.size() == 0)
    {
        return NULL;
    }
    else if (list.size() == 1)
    {
        return list[0];
    }
    else
    {
        int last = list.size() - 1;
        while (last > 0)
        {
            int i = 0, j = last;
            while (i < j)
            {
                list[i] = mergeTwoLists(list[i], list[j]);
                i++;
                j--;
                if (i >= j)
                {
                    last = j;
                }
            }
        }
    }
    return list[0];
};

int main()
{
    Node<int> *head;
    Node<int> *n1;
    Node<int> *n2;
    n1 = new Node<int>();
    n2 = new Node<int>();

    n1->item = 2;
    n2->item = 3;

    n1->next = n2;
    n2->next = NULL;

    Node<int> *n3;
    Node<int> *n4;
    n3 = new Node<int>();
    n4 = new Node<int>();

    n3->item = 1;
    n4->item = 5;

    n3->next = n4;
    n4->next = NULL;

    Node<int> *n5;
    Node<int> *n6;
    n5 = new Node<int>();
    n6 = new Node<int>();

    n5->item = 1;
    n6->item = 8;

    n5->next = n6;
    n6->next = NULL;

    head = mergeLists<int>({n1, n3, n5});
    while (head != NULL)
    {
        cout << head->item << " ";
        head = head->next;
    }
    return 0;
}
// g++ file.cpp -o
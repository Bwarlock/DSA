#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    T item;
    Node *next;
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

    head = n1;
    n1->next = n2;
    n2->next = NULL;
    while (head != NULL)
    {
        cout << head->item << " ";
        head = head->next;
    }
    return 0;
}
// g++ file.cpp -o
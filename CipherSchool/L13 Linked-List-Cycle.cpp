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
bool RemoveCycle(Node<T> *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    Node<T> *fast = head;
    Node<T> *slow = head;
    do
    {
        slow = slow->next;
        fast = fast->next;
        if (fast == NULL)
        {
            return false;
        }
        fast = fast->next;
        if (fast == NULL)
        {
            return false;
        }
    } while (fast != slow);

    slow = head;
    Node<T> *prev = fast;
    while (fast != slow)
    {
        slow = slow->next;
        prev = fast;
        fast = fast->next;
    }

    prev->next = NULL;
    return true;
}

int main()
{
    Node<int> *head;
    Node<int> *n1;
    Node<int> *n2;
    Node<int> *n3;
    Node<int> *n4;
    n4 = new Node<int>(3);
    n3 = new Node<int>(2, n4);
    n2 = new Node<int>(1, n3);
    n1 = new Node<int>(0, n2);
    n4->next = n3;

    bool cycle = RemoveCycle<int>(n1);
    if (cycle)
    {
        cout << "Cycle Detected" << endl;
    }
    else
    {
        cout << "No Cycle" << endl;
    }
    head = n1;
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
// g++ file.cpp -o
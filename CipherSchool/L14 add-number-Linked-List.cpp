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

Node<int> *addNumberLL(Node<int> *a, Node<int> *b)
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
        // a and b not Null

        Node<int> dummy;
        Node<int> *r = &dummy;
        Node<int> *first = a, *second = b;
        int sum = 0, carry = 0;
        while (first != NULL || second != NULL)
        {
            sum = (first == NULL ? 0 : first->val) + (second == NULL ? 0 : second->val) + carry;
            carry = sum / 10;
            sum = sum % 10;
            r->next = new Node<int>(sum);
            r = r->next;

            if (first != NULL)
            {
                first = first->next;
            }
            if (second != NULL)
            {
                second = second->next;
            }
        }
        if (carry > 0)
        {
            r->next = new Node<int>(carry);
            r = r->next;
        }
        r->next = NULL;
        return dummy.next;
    }
};

int main()
{
    Node<int> *head;
    Node<int> *n1;
    Node<int> *n2;
    Node<int> *n3;
    Node<int> *n4;
    n4 = new Node<int>(3, NULL); // Most Significant Bit
    n3 = new Node<int>(2, n4);
    n2 = new Node<int>(1, n3);
    n1 = new Node<int>(0, n2); // Least Significant Bit
    // 3210

    Node<int> *m1;
    Node<int> *m2;
    Node<int> *m3;
    m3 = new Node<int>(3, NULL);
    m2 = new Node<int>(2, m3);
    m1 = new Node<int>(1, m2);
    // 321

    head = addNumberLL(n1, m1);
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
// g++ file.cpp -o
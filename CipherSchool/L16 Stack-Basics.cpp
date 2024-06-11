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
class StackVector
{

private:
    int top;
    vector<T> stack;

public:
    StackVector()
    {
        top = -1;
        stack = {};
    }
    StackVector(vector<T> list)
    {
        top = -1;
        stack = {};
        for (T i : list)
        {
            push(i);
        }
    }
    void push(T item)
    {
        stack.push_back(item);
        top++;
    }
    T pop()
    {
        if (top >= 0)
        {
            T item = stack[top--];
            stack.pop_back();
            return item;
        }
        else
        {
            // Throw error
            cout << "Trying to UnderFlow" << endl;
            return 0;
        }
    }
    T peek()
    {
        if (top > -1)
        {
            return stack[top];
        }
        else
        {
            // Throw error
            cout << "Empty" << endl;
            return 0;
        }
    }
    bool isEmpty()
    {
        return top == -1;
    }
    int size()
    {
        return top + 1;
    }
};

template <class T>
class StackList
{
private:
    int length;
    Node<T> *top;

public:
    StackList()
    {
        length = -1;
        top = NULL;
    }
    void push(T item)
    {
        Node<T> *newNode = new Node<T>(item);
        newNode->next = top;
        top = newNode;
        length++;
    }
    T pop()
    {
        if (top != NULL)
        {
            Node<T> *ptr = top;
            T temp = top->val;
            top = top->next;
            delete ptr;
            return temp;
        }
        else
        {
            // Throw error
            cout << "Trying to UnderFlow" << endl;
            return 0;
        }
    }
    bool isEmpty()
    {
        return top == NULL;
    }
    T peek()
    {
        if (top != NULL)
        {

            return top->val;
        }
        else
        {
            // Throw error
            cout << "Empty" << endl;
            return 0;
        }
    }
    int size()
    {
        return length + 1;
    }
};

int main()
{
    // StackVector<int> s1 = StackVector<int>({1, 2, 3, 4});
    // s1.push(5);
    // cout << s1.peek() << s1.pop() << s1.pop() << s1.peek() << endl;

    StackList<int> s2 = StackList<int>();
    s2.push(5);
    s2.push(4);
    cout << s2.peek() << s2.pop() << s2.peek() << endl;
    return 0;
}
// g++ file.cpp -o
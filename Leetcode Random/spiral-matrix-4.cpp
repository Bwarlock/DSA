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

class Solution
{
public:
    static vector<vector<int>> spiralMatrix4(int m, int n, Node<int> *head)
    {
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        vector<vector<int>> result(m, vector<int>(n, -1));
        while (top <= bottom && left <= right && head != NULL)
        {

            for (int i = left; i <= right && head != NULL; i++)
            {
                result[top][i] = head->item;
                head = head->next;
            }
            top++;

            for (int i = top; i <= bottom && head != NULL; i++)
            {
                result[i][right] = head->item;
                head = head->next;
            }
            right--;
            if (top <= bottom)
            {
                for (int i = right; i >= left && head != NULL; i--)
                {
                    result[bottom][i] = head->item;
                    head = head->next;
                }
                bottom--;
            }
            if (left <= right)
            {
                for (int i = bottom; i >= top && head != NULL; i--)
                {
                    result[i][left] = head->item;
                    head = head->next;
                }
                left++;
            }
        }
        return result;
    }
};

int main()
{
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

    for (vector<int> i : Solution::spiralMatrix4(1, 5, n1))
    {
        cout << "[ ";
        for (int k : i)
        {
            cout << k << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
    return 0;
}
// g++ file.cpp -o
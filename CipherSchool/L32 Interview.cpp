#include <bits/stdc++.h>
using namespace std;

char nextChar() {}

void sendSignal() {}

void GameSignalServer()
{
    vector<string> moves = {"JUMP", "BOMB", "BOMBING"};
    vector<int> count(moves.size(), 0);

    while (true)
    {
        char temp = nextChar();
        for (int i = 0; i < moves.size(); i++)
        {
            if (moves[i][count[i]] == temp)
            {
                count[i]++;
                if (count[i] == moves[i].size())
                {
                    sendSignal();
                }
            }
            else
            {
                count[i] = 0;
            }
        }
    }
}

string parsingString(string &line)
{
    unordered_map<int, int> starting;
    unordered_map<int, int> closing;
    string result = "";
    int count = 0;
    int high = 0;
    for (int i = 0; i < line.size(); i++)
    {
        if (i == '(')
        {
            if (high < count)
            {
                high = count;
            }
            starting[count] = i;
            count++;
        }
        else if (i == ')')
        {
            closing[count] = i;
            count--;
        }
    }
    // save the integer after (){integer} as a map as well
    while (high >= 0)
    {
        // go for high to 0 and take the substring from starting to closing
        // repeat it given integer number of times
        // result =
    }

    return result;
}

// [9,15] [10,12][12,14][]
void meetingScheduling()
{
    // sort according to starting time
    // create priority queue
    // throw the end time into heap
    // at next index check if the lowest (min heap) is becoming available if yes no need for another cabin
    // if the lowest leaving time is higher than current starting time then add cabin
}

void rottenORANGE()
{
    // Naive approach N*N*N
    // traverse matrix
    // keep array of indexes of fresh orange
    // start the simulation for each fresh orange

    // if any four corner && (rotten array) r rotten make it rotten and add it to the rotten array
    // After N PASSES is the length is > 0 cant turn all
    // if at some point fresh array turns empty return the time

    // at each fresh check , we could end up checking N*N rotten oranges along with the 4 corners
    // or we could keep N*N marrix for rottens and that makes 8 checks only
    // so N*N*8 is the complexity
}

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

Node<int> *listOddEven(Node<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    Node<int> *temp = root;
    Node<int> *OddStart = new Node<int>(0);
    Node<int> *EvenStart = new Node<int>(0);
    Node<int> *odd = OddStart;
    Node<int> *even = EvenStart;
    Node<int> *result = new Node<int>(0);
    while (root != NULL)
    {
        if (root->val & 1)
        {
            odd->next = root;
            odd = odd->next;
        }
        else
        {
            even->next = root;
            even = even->next;
        }
        root = root->next;
    }

    odd = OddStart->next;
    even = EvenStart->next;
    root = result;
    while (odd != NULL && even != NULL)
    {

        root->next = odd;
        odd = odd->next;
        root = root->next;

        root->next = even;
        even = even->next;
        root = root->next;
    }
    while (odd != NULL)
    {

        root->next = odd;
        odd = odd->next;
        root = root->next;
    }
    while (even != NULL)
    {
        root->next = even;
        even = even->next;
        root = root->next;
    }

    return result->next;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
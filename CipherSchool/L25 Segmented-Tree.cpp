
#include <bits/stdc++.h>
using namespace std;

class SegementedTree
{
    int *arr;
    int arrSize;
    int *tree;
    int N;

    int getLeftChild(int index)
    {
        return 2 * index + 1;
    }
    int getRightChild(int index)
    {
        return 2 * index + 2;
    }
    void buildTree(int nodeIndex, int start, int end)
    {
        if (start == end)
        {
            this->tree[nodeIndex] = this->arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            int leftChild = getLeftChild(nodeIndex);
            int rightChild = getRightChild(nodeIndex);
            buildTree(leftChild, start, mid);
            buildTree(rightChild, mid + 1, end);
            this->tree[nodeIndex] = this->tree[leftChild] + this->tree[rightChild];
        }
    }
    void updateTree(int nodeIndex, int start, int end, const int &indexToUpdate, const int &delta)
    {
        if (indexToUpdate < start || end < indexToUpdate || start > end)
        {
            return;
        }
        this->tree[nodeIndex] += delta;
        if (start < end)
        {
            int mid = (start + end) / 2;
            int leftChild = getLeftChild(nodeIndex);
            int rightChild = getRightChild(nodeIndex);
            if (start <= indexToUpdate || indexToUpdate <= mid)
            {
                updateTree(leftChild, start, mid, indexToUpdate, delta);
            }
            else
            {
                updateTree(rightChild, mid + 1, end, indexToUpdate, delta);
            }
        }
    }
    int getSumTree(int nodeIndex, int start, int end, const int &qStart, const int &qEnd)
    {
        if (qEnd < start || end < qStart)
        {
            // Out Of Bound For start end
            // start end is outside qStart qEnd
            return 0;
        }
        else if (qStart <= start && end <= qEnd)
        {
            // Partial + Full Inner Bound For start end
            // start end in inside qStart qEnd
            return this->tree[nodeIndex];
        }
        else
        {
            // Part Inner + Part Outer Bound
            // either start or end is inside qStart qEnd
            int mid = (start + end) / 2;
            int leftChild = getLeftChild(nodeIndex);
            int rightChild = getRightChild(nodeIndex);

            return getSumTree(leftChild, start, mid, qStart, qEnd) + getSumTree(rightChild, mid + 1, end, qStart, qEnd);
        }
    }

public:
    SegementedTree(int *arr, int arrSize)
    {
        this->arrSize = arrSize;
        this->arr = arr;

        // Size of tree array
        // n (0,0)(1,1)(2,2)(3,3) leaf nodes
        // + n - 1 upper nodes
        // Maybe it should be 2n
        // tested and 2n doesnt work
        this->N = 4 * this->arrSize;
        this->tree = new int[this->arrSize];
        for (int i = 0; i < this->N; i++)
        {
            this->tree[i] = 0;
        }
        buildTree(0, 0, this->arrSize - 1);
    }
    void update(int indexToUpdate, int delta)
    {
        this->arr[indexToUpdate] += delta;
        updateTree(0, 0, this->arrSize - 1, indexToUpdate, delta);
    }
    int getSum(int qStart, int qEnd)
    {
        return getSumTree(0, 0, this->arrSize - 1, qStart, qEnd);
    }
    void printTree()
    {
        for (int i = 0; i < this->N; i++)
        {
            cout << this->tree[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    SegementedTree *st = new SegementedTree(arr, 6);
    st->printTree();
    cout << st->getSum(3, 5) << endl;
    return 0;
}
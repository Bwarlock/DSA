
#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    int capacity;
    int size;
    int *heap;

    void heapify(int index)
    {
        int left = leftChild(index), right = rightChild(index);
        while (left <= this->size)
        {
            if (right <= this->size && this->heap[left] < this->heap[right])
            {
                swap(this->heap[index], this->heap[right]);
                index = right;
            }
            else
            {
                swap(this->heap[index], this->heap[left]);
                index = left;
            }
            left = leftChild(index);
            right = rightChild(index);
        }
    }

public:
    int parent(int index)
    {
        return (index - 1) / 2;
    }
    int leftChild(int index)
    {
        return (2 * index + 1);
    }
    int rightChild(int index)
    {
        return (2 * index + 2);
    }
    MaxHeap(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->heap = new int[this->capacity];
    }
    MaxHeap(vector<int> &arr)
    {
        this->capacity = arr.size();
        this->size = 0;
        this->heap = new int[this->capacity];
        for (int i : arr)
        {
            this->heap[this->size] = i;
            this->size++;
        }

        for (int i = this->capacity - 1; i > 0; i -= 2)
        {
            heapify(parent(i));
        }
    }
    void push(int key)
    {
        if (this->size == this->capacity)
        {
            return;
        }
        this->size++;
        int index = this->size - 1;
        this->heap[index] = key;

        while (index != 0 && this->heap[index] > this->heap[parent(index)])
        {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    int top()
    {
        return this->size == 0 ? -1 : this->heap[0];
    }

    void pop()
    {
        if (this->size == 0)
        {
            return;
        }
        if (this->size == 1)
        {
            this->size--;
            return;
        }
        swap(this->heap[0], this->heap[size]);
        this->size--;
        heapify(0);
    }
};

vector<double> medianOfRunningStream(vector<int> &arr)
{
    vector<double> result(arr.size());
    priority_queue<int> MaxHeap;
    priority_queue<int, vector<int>, greater<int>> MinHeap;
    for (int i = 0; i < arr.size(); i++)
    {
        MaxHeap.push(arr[i]);
        if (MaxHeap.size() - MinHeap.size() > 1)
        {
            MinHeap.push(MaxHeap.top());
            MaxHeap.pop();
        }
        if (i & 1)
        {
            result[i] = (MaxHeap.top() + MinHeap.top()) / 2;
        }
        else
        {
            result[i] = (MaxHeap.top());
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {1, 5, 4, 7};
    MaxHeap *heap = new MaxHeap(arr);

    cout << heap->top() << endl;
    heap->pop();
    cout << heap->top() << endl;

    for (double i : medianOfRunningStream(arr))
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
// Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

// Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

#include <bits/stdc++.h>
using namespace std;

template <typename K, typename V>
V get_or_default(const unordered_map<K, V> &map, const K &key, const V &default_value)
{
    auto it = map.find(key);
    return (it != map.end()) ? it->second : default_value + map.size();
}

void mergeSort(vector<int> &arr, int left, int mid, int right, unordered_map<int, int> &hash)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    vector<int> leftArray = vector<int>(subArrayOne);
    vector<int> rightArray = vector<int>(subArrayTwo);

    // space n
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (get_or_default(hash, leftArray[indexOfSubArrayOne], leftArray[indexOfSubArrayOne]) <= get_or_default(hash, rightArray[indexOfSubArrayTwo], rightArray[indexOfSubArrayTwo]))
        {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne)
    {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo)
    {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void merge(vector<int> &arr, int const begin, int const end, unordered_map<int, int> &hash)
{
    // nLogn
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    merge(arr, begin, mid, hash);
    merge(arr, mid + 1, end, hash);
    mergeSort(arr, begin, mid, end, hash);
}

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    unordered_map<int, int> hash;
    for (int i = 0; i < m; i++)
    {
        // space n
        hash[arr2[i]] = i;
        cout << arr2[i] << " " << i << endl;
    }

    merge(arr1, 0, n - 1, hash);
    return arr1;
}

int main()
{
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};
    for (int i : relativeSortArray(arr1, arr2))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
// g++ file.cpp -o
#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSort(vector<int> a, vector<int> b){
    int n = a.size();
    int m = b.size();
    vector<int> result(n+m);
    int i = n-1 , j = m-1 , k = n+m-1;
    while (i>=0 && j>=0){
        if(a[i] > b[j]){
            result[k] = a[i];
            i--;
        }
        else{
            result[k] = b[j];
            j--;
        }
        k--;
    }
    while (i >= 0){
        result[k] = a[i];
        i--;
        k--;
    }
    while (j >= 0){
        result[k] = b[j];
        j--;
        k--;
    }
    return result;
}

int main() {
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 4, 6};
        
    for (int num : mergeSort(a ,b)) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
//g++ file.cpp
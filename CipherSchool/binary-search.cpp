#include <bits/stdc++.h>
using namespace std;


int firstOccurance(vector<int> a, int x){
    int low = 0;
    int n = a.size();
    int high = n - 1;
    int mid;
    int res = -1;
    while (low <= high){
        mid = (low + high)/2;
        if(a[mid] < x){
            low = mid + 1;
        }
        else if(x < a[mid]){
            high = mid - 1;
        }
        else{
            if(mid == 0 || a[mid-1] < a[mid]){
                res = mid;
                break; 
            }
            else{
                high = mid - 1;
            }
        }   
    }
    return res;
}

int lastOccurance(vector<int> a, int x){
    int low = 0;
    int n = a.size();
    int high = n - 1;
    int mid;
    int res = -1;
    while (low <= high){
        mid = (low + high)/2;
        if(a[mid] < x){
            low = mid + 1;
        }
        else if(x < a[mid]){
            high = mid - 1;
        }
        else{
            if(mid == n-1 || a[mid] < a[mid+1]){
                res = mid;
                break; 
            }
            else{
                low = mid + 1;
            }
        }   
    }
    return res;
}

vector<int> firstLastOccurance(vector<int> a, int x){
    return {firstOccurance(a , x) , lastOccurance(a,x)};
}

int main() {
    vector<int> nums = {2, 2, 2, 2,2, 4, 8};
    int target = 2;
    vector<int> result = firstLastOccurance(nums, target);
    cout << "First occurrence: " << result[0] << endl;
    cout << "Last occurrence: " << result[1] << endl;
    return 0;
}
//g++ file.cpp -o
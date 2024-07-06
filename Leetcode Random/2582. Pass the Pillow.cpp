// There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

// For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
// Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.

#include <bits/stdc++.h>
using namespace std;

int passThePillow(int n, int time)
{
    return (time / (n - 1)) & 1 ? n - (time % (n - 1)) : 1 + (time % (n - 1));
}

int main()
{
    cout << passThePillow(4, 5) << endl;
    return 0;
}
// g++ file.cpp -o
// There are n 1-indexed robots, each having a position on a line, health, and movement direction.

// You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.

// All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.

// If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.

// Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final heath of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.

// Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.

// Note: The positions may be unsorted.

#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> &a, vector<int> &b)
{
    return (a[3] < b[3]);
}

vector<int> survivedRobotsHealths(const vector<int> &positions, const vector<int> &healths, string directions)
{
    vector<vector<int>> combine;
    for (int i = 0; i < positions.size(); i++)
    {
        if (directions[i] == 'R')
        {
            combine.push_back({positions[i], healths[i], 1, i});
        }
        else
        {
            combine.push_back({positions[i], healths[i], 0, i});
        }
    }
    sort(combine.begin(), combine.end());
    stack<vector<int>> stk;
    vector<int> result;
    vector<vector<int>> inter;
    stk.push(combine[0]);
    for (int i = 1; i < combine.size(); i++)
    {
        if (!stk.empty())
        {
            if (stk.top()[2] ^ combine[i][2])
            {
                if (stk.top()[1] < combine[i][1])
                {
                    stk.pop();
                    combine[i][1]--;
                    stk.push(combine[i]);
                }
                else if (stk.top()[1] > combine[i][1])
                {
                    stk.top()[1]--;
                }
                else
                {
                    stk.pop();
                }
                // if top > current , nothing changes in stk
            }
            else
            {
                stk.push(combine[i]);
            }
        }
        else
        {
            stk.push(combine[i]);
        }
    }
    while (!stk.empty())
    {
        inter.push_back(stk.top());
        stk.pop();
    }
    sort(inter.begin(), inter.end(), comparator);
    for (vector<int> i : inter)
    {
        result.push_back(i[1]);
    }
    return result;
}

int main()
{
    cout << survivedRobotsHealths({5, 4, 3, 2, 1}, {2, 17, 9, 15, 10}, "RRRRR")[0] << endl;
    return 0;
}
// g++ file.cpp -o
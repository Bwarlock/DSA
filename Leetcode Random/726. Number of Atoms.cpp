#include <bits/stdc++.h>
using namespace std;

// Given a string formula representing a chemical formula, return the count of each atom.

// The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

// One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

// For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
// Two formulas are concatenated together to produce another formula.

// For example, "H2O2He3Mg4" is also a formula.
// A formula placed in parentheses, and a count (optionally added) is also a formula.

// For example, "(H2O2)" and "(H2O2)3" are formulas.
// Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

// The test cases are generated so that all the values in the output fit in a 32-bit integer.

class comparator
{
public:
    bool operator()(string &a, string &b)
    {
        return (a > b);
    }
};

string createElement(int &i, int &len, string &formula)
{
    string temp = "";
    if (i < len && isupper(formula[i]))
    {
        temp += formula[i];
        i++;
    }
    while (i < len && islower(formula[i]))
    {
        temp += formula[i];
        i++;
    }
    cout << temp << "temp" << endl;
    return temp;
}

int createCount(int &i, int &len, string &formula)
{
    string tempCount = "";
    while (i < len && isdigit(formula[i]))
    {
        cout << "digit" << formula[i] << endl;
        tempCount += formula[i];
        i++;
    }
    return tempCount.empty() ? 1 : stoi(tempCount);
}

void countBracket(int &i, int &len, string &formula, unordered_map<string, int> &count, unordered_set<string> &check)
{
    cout << "hi" << i << endl;
    unordered_map<string, int> tempMap;
    while (i < len && formula[i] != ')')
    {
        if (formula[i] == '(')
        {
            i++;
            countBracket(i, len, formula, tempMap, check);
            continue;
        }
        string temp = createElement(i, len, formula);

        int tempCount = createCount(i, len, formula);

        tempMap[temp] = (tempMap.find(temp) != tempMap.end() ? tempMap[temp] : 0) + tempCount;
    }
    i++;

    int tempCountOut = createCount(i, len, formula);

    for (auto it : tempMap)
    {
        cout << it.first << it.second << endl;

        count[it.first] += it.second * tempCountOut;
        check.insert(it.first);
        cout << "yo" << it.first << count[it.first] << endl;
        // count[k] = (count.find(k) != count.end() ? count[k] : 0) + (tempCount.empty() ? 1 : stoi(tempCount));
        // pq.push(k);
    }
}

string countOfAtoms(string formula)
{
    unordered_map<string, int> count;

    string result = "";
    unordered_set<string> check;
    int len = formula.length();
    for (int i = 0; i < len;)
    {
        if (formula[i] == '(')
        {
            i++;
            countBracket(i, len, formula, count, check);
        }
        else
        {
            string temp = createElement(i, len, formula);
            int tempCount = createCount(i, len, formula);

            count[temp] += tempCount;
            check.insert(temp);
            cout << "yo" << temp << count[temp] << endl;
        }
    }
    cout << "last" << endl;
    vector<string> vc(check.begin(), check.end());
    priority_queue<string, vector<string>, comparator> pq(comparator(), vc);
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        result += pq.top() + to_string(count[pq.top()]);
        pq.pop();
    }
    return result;
}

int main()
{
    cout << countOfAtoms("K4(ON(SO3)2)2") << endl;
    return 0;
}
// Got 0ms ON Hard les gooo
// g++ file.cpp -o
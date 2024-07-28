#include <bits/stdc++.h>
using namespace std;
#define CHARSET 256

class TrieNode
{
public:
    bool isWord;
    TrieNode *children[CHARSET];
    TrieNode()
    {
        this->isWord = false;
        for (int i = 0; i < CHARSET; i++)
        {
            this->children[i] = NULL;
        }
    }
};

class Trie
{
    // Space O( height * Charset ) ( maxLengthWord * 256 )
    TrieNode *root;
    Trie()
    {
        this->root = new TrieNode();
    }
    // Insert
    void Insert(const string &word)
    {
        // O(N)
        TrieNode *crawler = this->root;
        for (int i = 0; i < word.size(); i++)
        {
            if (crawler->children[int(word[i])] == NULL)
            {
                crawler->children[int(word[i])] == new TrieNode();
            }
            crawler = crawler->children[int(word[i])];
        }
        crawler->isWord = true;
    }
    // Search
    bool Search(const string &word)
    {
        // O(N)
        TrieNode *crawler = this->root;
        for (int i = 0; i < word.size(); i++)
        {
            if (crawler->children[int(word[i])] == NULL)
            {
                return true;
            }
            crawler = crawler->children[int(word[i])];
        }
        return crawler->isWord;
    }
    // Delete
    bool isLeafNode(TrieNode *node)
    {
        // O( Charset )
        for (int i = 0; i < CHARSET; i++)
        {
            if (node->children[i] != NULL)
            {
                return false;
            }
        }
        return true;
    }
    bool Delete(TrieNode *crawler, int curr, const int &len, const string &word)
    {
        // O( len * Charset )
        if (curr == len)
        {
            crawler->isWord = false;
            return isLeafNode(crawler);
        }
        else
        {

            if (Delete(crawler->children[int(word[curr - 1])], curr + 1, len, word))
            {
                delete crawler->children[int(word[curr - 1])];
                return !crawler->isWord && isLeafNode(crawler);
            }
        }
        return false;
    }
    void Delete(const string &word)
    {
        // O( len * Charset )
        // Assumes word actually exists other wise check with Search first
        TrieNode *crawler = this->root;
        Delete(crawler, 1, word.size(), word);
    }
};

// Union Find
class DisjointSet
{
    int *parent;
    int size;

public:
    DisjointSet(int size)
    {
        this->size = size;
        this->parent = new int[this->size];
        for (int i = 0; i < size; i++)
        {
            this->parent[i] = i;
        }
    }
    void Union(int a, int b)
    {
        // O(N)
        int parentA = this->parent[a];
        for (int i = 0; i < size; i++)
        {
            if (this->parent[i] == parentA)
            {
                this->parent[i] = this->parent[b];
            }
        }
    }
    bool Find(int a, int b)
    {
        // O(1)
        return (this->parent[a] == this->parent[b]);
    }
};

class OptimizedDisjointSet
{
    int *parent;
    int size;

public:
    OptimizedDisjointSet(int size)
    {
        this->size = size;
        this->parent = new int[this->size];
        for (int i = 0; i < size; i++)
        {
            this->parent[i] = i;
        }
    }
    int FindParent(int a)
    {
        // Normally O(N)
        if (this->parent[a] == a)
        {
            return a;
        }
        // This Step Reduces Complexity to O(1) on Finding Same Element's Parent 2nd Time
        int paren = FindParent(this->parent[a]);
        this->parent[a] = paren;
        return paren;
    }
    void Union(int a, int b)
    {
        // O(N) 1st time;
        // O(1) 2nd time for either a or b;
        int parentA = FindParent(a);
        int parentB = FindParent(b);
        if (parentA != parentB)
        {
            this->parent[parentA] = parentB;
        }
    }
    bool isConnected(int a, int b)
    {
        // O(1)
        return (FindParent(a) == FindParent(b));
    }
};

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
// g++ file.cpp -o
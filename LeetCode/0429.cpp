class Node
{
public:
    int val;
    vector<Node *> children;
    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node *> _children) : val(_val), children(_children) {}
};

#include "0429.hpp"

int main()
{
    Solution sln;
    return 0;
}

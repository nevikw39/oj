class Node
{
public:
    bool val = false, isLeaf = false;
    Node *topLeft = nullptr, *topRight = nullptr, *bottomLeft = nullptr, *bottomRight = nullptr;
    Node() {}
    Node(bool _val, bool _isLeaf) : val(_val), isLeaf(_isLeaf) {}
    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) : val(_val), isLeaf(_isLeaf)
    {
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

#include "0427.hpp"

int main()
{
    Solution sln;
    return 0;
}

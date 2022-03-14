class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

#include "0138.hpp"

int main()
{
    Solution sln;
    return 0;
}

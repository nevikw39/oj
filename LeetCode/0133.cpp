#include <vector>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

#include "0133.hpp"

int main()
{
    Node *a = new Node(1), *b = new Node(2), *c = new Node(3), *d = new Node(4);
    a->neighbors = {b, d};
    b->neighbors = {a, c};
    c->neighbors = {b, d};
    d->neighbors = {a, c};
    Solution sln;
    sln.cloneGraph(a);
    return 0;
}

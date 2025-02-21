struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include "1261.hpp"

int main()
{
    FindElements findElements(new TreeNode(-1, nullptr, new TreeNode(-1)));
    assert(findElements.find(1) == false); // return False
    assert(findElements.find(2) == true); // return True
    return 0;
}

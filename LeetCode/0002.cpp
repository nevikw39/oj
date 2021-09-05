struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include "0002.hpp"

int main()
{
    Solution sln;
    for (auto ptr = sln.addTwoNumbers(new ListNode(2, new ListNode(4, new ListNode(3))), new ListNode(5, new ListNode(6, new ListNode(4)))); ptr; ptr = ptr->next)
        cout << ptr->val << ' ';
    cout << '\n';
    for (auto ptr = sln.addTwoNumbers(new ListNode(0), new ListNode(0)); ptr; ptr = ptr->next)
        cout << ptr->val << ' ';
    cout << '\n';
    for (auto ptr = sln.addTwoNumbers(new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))), new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))))); ptr; ptr = ptr->next)
        cout << ptr->val << ' ';
    cout << '\n';
    return 0;
}

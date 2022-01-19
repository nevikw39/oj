struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include "0142.hpp"

int main()
{
    ListNode *l = new ListNode(-1);
    l->next = new ListNode(-7);
    l->next->next = new ListNode(7);
    l->next->next->next = new ListNode(-4);
    l->next->next->next->next = new ListNode(19);
    l->next->next->next->next->next = new ListNode(6);
    l->next->next->next->next->next->next = new ListNode(-9);
    l->next->next->next->next->next->next->next = new ListNode(-5);
    l->next->next->next->next->next->next->next->next = new ListNode(2);
    l->next->next->next->next->next->next->next->next->next = new ListNode(-5);
    l->next->next->next->next->next->next->next->next->next->next = l->next->next->next->next->next->next;
    Solution sln;
    cout << sln.detectCycle(l) << '\n';
    return 0;
}

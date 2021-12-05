struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include "2058.hpp"

ListNode *build(vector<int> v)
{
    ListNode *ln = nullptr;
    for (auto itr = v.rbegin(); itr != v.rend(); itr++)
        ln = new ListNode(*itr, ln);
    return ln;
}

int main()
{
    Solution sln;
    auto a = sln.nodesBetweenCriticalPoints(build({3, 1})),
         b = sln.nodesBetweenCriticalPoints(build({5, 3, 1, 2, 5, 1, 2})),
         c = sln.nodesBetweenCriticalPoints(build({1, 3, 2, 2, 3, 2, 2, 2, 7})),
         d = sln.nodesBetweenCriticalPoints(build({2, 3, 3, 2})),
         e = sln.nodesBetweenCriticalPoints(build({4, 2, 4, 1}));
    cout << a[0] << ' ' << a[1] << '\n'
         << b[0] << ' ' << b[1] << '\n'
         << c[0] << ' ' << c[1] << '\n'
         << d[0] << ' ' << d[1] << '\n'
         << e[0] << ' ' << e[1] << '\n';
    return 0;
}

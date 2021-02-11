#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
struct node
{
    int v;
    node *l, *r;
};
struct cmp
{
    bool operator()(node *a, node *b)
    {
        return a->v > b->v;
    }
};
int l;
void f(node *r, int d)
{
    if (r == nullptr)
        return;
    if (r->l == nullptr && r->r == nullptr)
    {
        l += r->v * d;
        return;
    }
    f(r->l, d + 1);
    f(r->r, d + 1);
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        priority_queue<node *, vector<node *>, cmp> p;
        while (n--)
        {
            int tmp;
            cin >> tmp;
            p.push(new node{tmp, nullptr, nullptr});
        }
        while (p.size() > 1)
        {
            node *n1 = p.top();
            p.pop();
            node *n2 = p.top();
            p.pop();
            p.push(new node{n1->v + n2->v, n1, n2});
        }
        l = 0;
        f(p.top(), 0);
        cout << l << endl;
    }
    return 0;
}

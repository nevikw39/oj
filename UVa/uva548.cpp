#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_pbds;
struct node
{
    int n;
    node *l, *r;
};
node *build(const vector<int> &in, const vector<int> &post, int l0, int r0, int l1, int r1)
{
    if (l0 > r0)
        return nullptr;
    int r = post[r1], p = l0;
    while (in[p] != r)
        p++;
    int cnt = p - l0;
    auto n = new node;
    n->n = r;
    n->l = build(in, post, l0, p - 1, l1, l1 + cnt - 1);
    n->r = build(in, post, p + 1, r0, l1 + cnt, r1 - 1);
    return n;
}
int mn, mn_sum;
void dfs(node *n, int sum)
{
    sum += n->n;
    if (!n->l && !n->r)
        if (sum < mn_sum || sum == mn_sum && n->n < mn)
        {
            mn = n->n;
            mn_sum = sum;
            return;
        }
    if (n->l)
        dfs(n->l, sum);
    if (n->r)
        dfs(n->r, sum);
}
void destroy(node *n)
{
    if (n->l)
        destroy(n->l);
    if (n->r)
        destroy(n->r);
    delete n;
}
int main()
{
#ifdef ONLINE_JUDGE
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#endif
    for (;;)
    {
        vector<int> in, post;
        string s;
        getline(cin, s);
        if (!s.length())
            return 0;
        stringstream ss(s);
        int tmp;
        while (ss >> tmp)
            in.push_back(tmp);
        getline(cin, s);
        ss.clear();
        ss.str(s);
        while (ss >> tmp)
            post.push_back(tmp);
        int n = in.size();
        auto r = build(in, post, 0, n - 1, 0, n - 1);
        mn_sum = INT_MAX;
        dfs(r, 0);
        cout << mn << '\n';
        destroy(r);
    }
}
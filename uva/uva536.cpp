#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_pbds;
void build(const string &pre, const string &in, int l0, int r0, int l1, int r1)
{
    if (l0 > r0)
        return;
    int r = pre[l0], p = l1;
    while (in[p] != r)
        p++;
    int cnt = p - l1;
    build(pre, in, l0 + 1, l0 + cnt, l1, p - 1);
    build(pre, in, l0 + cnt + 1, r0, p + 1, r1);
    cout.put(r);
}
int main()
{
#ifdef ONLINE_JUDGE
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#endif
    string pre, in;
    while (cin >> pre >> in)
    {
        int n = pre.length();
        build(pre, in, 0, n - 1, 0, n - 1);
        cout.put('\n');
    }
    return 0;
}
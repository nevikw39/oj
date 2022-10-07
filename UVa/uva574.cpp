/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

int t, n;

vector<int> x, v;
set<vector<int>, greater<>> r;

void f(int i = 0, int sum = 0)
{
    if (sum == t)
    {
        r.emplace(v);
        return;
    }
    if (i == n)
        return;
    f(i + 1, sum);
    v.push_back(x[i]);
    f(i + 1, sum + x[i]);
    v.pop_back();
}

void solve()
{
    x.assign(n, 0);
    for (int &i : x)
        cin >> i;
    r.clear();
    f();
    cout << "Sums of " << t << ":\n";
    if (r.empty())
    {
        cout << "NONE\n";
        return;
    }
    for (const auto &i : r)
    {
        cout << i[0];
        for (int j = 1, l = i.size(); j < l; j++)
            cout << '+' << i[j];
        cout << '\n';
    }
}

int main()
{
    nevikw39;
    while (cin >> t >> n && t * n)
        solve();
    return 0;
}
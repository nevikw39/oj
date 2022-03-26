/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr), ios::sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
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

vector<vector<int>> t;
vector<pair<int, int>> d;
vector<int> p;

void dfs(bool flag, int x = 0, int a = -1)
{
    for (const int &i : t[x])
    {
        if (i == a)
            continue;
        if (flag)
        {
            if (i == d[x].ND)
            {
                if (d[i].ST < p[x] + 1)
                {
                    p[i] = d[i].ST;
                    d[i] = {p[x] + 1, x};
                }
                else
                    p[i] = max(p[i], p[x] + 1);
            }
            else
            {
                p[i] = d[i].ST;
                d[i] = {d[x].ST + 1, x};
            }
        }
        dfs(flag, i, x);
        if (!flag)
        {
            if (d[x].ST < d[i].ST + 1)
            {
                p[x] = d[x].ST;
                d[x] = {d[i].ST + 1, i};
            }
            else
                p[x] = max(p[x], d[i].ST + 1);
        }
    }
}

int main()
{
    nevikw39;
    int n;
    cin >> n;
    t.resize(n);
    d.resize(n);
    p.resize(n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    dfs(false);
    dfs(true);
    for (const auto &[i, _] : d)
        cout << i << ' ';
    cout << '\n';
    return 0;
}
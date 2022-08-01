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

void solve()
{
    string t;
    int n;
    cin >> t >> n;
    vector<tuple<int, int, int>> v;
    vector<pair<int, int>> vv;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0, lt = t.length(), ls = s.length(); j + ls <= lt; j++)
            if (t.substr(j, ls) == s)
                v.emplace_back(j, j + ls, i);
    }
    sort(ALL(v));
    int l = 0, i = 0;
    while (l < t.size())
    {
        bool flag = false;
        int mx = 0, mxi = -1;
        while (i < v.size())
            if (get<0>(v[i]) <= l)
            {
                flag = true;
                if (mx < get<1>(v[i]))
                {
                    mx = get<1>(v[i]);
                    mxi = i;
                }
                ++i;
            }
            else
                break;
        if (!flag)
            break;
        vv.emplace_back(get<2>(v[mxi]), get<0>(v[mxi]) + 1);
        l = mx;
    }
    if (l < t.size())
    {
        cout << "-1\n";
        return;
    }
    cout << vv.size() << '\n';
    for (const auto &[i, j] : vv)
        cout << i << ' ' << j << '\n';
}

int main()
{
    nevikw39;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

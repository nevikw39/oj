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

tuple<int, int, int> solve(const vector<int> &v)
{
    int n = v.size(), minus = 0, two = 0;
    for (const int &i : v)
    {
        if (i < 0)
            ++minus;
        if (abs(i) == 2)
            ++two;
    }
    if (~minus & 1)
        return {two, 0, 0};
    int l = 0, r = 0;
    auto itr = v.cbegin();
    while (*itr > 0)
        l += *itr++ == 2;
    l += *itr == -2;
    auto jtr = v.crbegin();
    while (*jtr > 0)
        r += *jtr++ == 2;
    r += *jtr == -2;
    return l < r ? make_tuple(two - l, int(itr - v.cbegin() + 1), 0) : make_tuple(two - r, 0, int(jtr - v.crbegin() + 1));
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    tuple<int, int, int> t = {-1, -1, -1};
    int i = 0;
    for (int j = 0; j < n; j++)
        if (!a[j])
        {
            if (j - i > 0)
            {
                auto &&[two, l, r] = solve(vector<int>(a.begin() + i, a.begin() + j));
                if (get<0>(t) < two)
                    t = {two, i + l, n - j + r};
            }
            i = j + 1;
        }
    if (i != n)
    {
        auto &&[two, l, r] = solve(vector<int>(a.begin() + i, a.end()));
        if (get<0>(t) < two)
            t = {two, i + l, r};
    }
    if (!~get<0>(t))
    {
        cout << n << " 0\n";
        return;
    }
    cout << get<1>(t) << ' ' << get<2>(t) << '\n';
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

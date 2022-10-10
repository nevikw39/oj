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
    string s;
    cin >> s;
    char a = s.front(), b = s.back();
    bool flag = a < b;
    vector<int> v(s.length()), r;
    iota(ALL(v), 0);
    sort(ALL(v), [&](int l, int r)
         { return s[l] != s[r] ? (flag ? s[l] < s[r] : s[l] > s[r]) : l < r; });
    auto itr = v.begin(), jtr = --v.end();
    while (s[*itr] != a)
        ++itr;
    while (s[*jtr] != b)
        --jtr;
    int c = 0;
    while (itr != jtr)
    {
        c += abs(s[*itr] - s[*(itr + 1)]);
        r.push_back(*itr++ + 1);
    }
    r.push_back(*jtr + 1);
    cout << c << ' ' << r.size() << '\n';
    for (int i : r)
        cout << i << ' ';
    cout << '\n';
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

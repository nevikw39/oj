/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <atcoder/all>
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
using namespace atcoder;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

int main()
{
    nevikw39;
    int h, w, m;
    cin >> h >> w >> m;
    vector<tuple<char, int, int>> tax(m);
    for (auto &[t, a, x] : tax)
        cin >> t >> a >> x;
    reverse(ALL(tax));
    int row = 0, col = 0;
    vector<bool> v_row(h), v_col(w);
    map<int, int64_t> mp;
    for (auto [t, a, x] : tax)
        if (t == '1')
        {
            if (!v_row[a - 1])
            {
                v_row[a - 1] = true;
                mp[x] += w - col;
                ++row;
            }
        }
        else
        {
            if (!v_col[a - 1])
            {
                v_col[a - 1] = true;
                mp[x] += h - row;
                ++col;
            }
        }
    mp.erase(0);
    int64_t sum = 0;
    for (auto [_, i] : mp)
        sum += i;
    mp[0] = 1LL * h * w - sum;
    vector<int> vec;
    for (auto [k, v] : mp)
        if (!v)
            vec.emplace_back(k);
    for (int i : vec)
        mp.erase(i);
    cout << mp.size() << '\n';
    for (auto [k, v] : mp)
        cout << k << ' ' << v << '\n';
    return 0;
}

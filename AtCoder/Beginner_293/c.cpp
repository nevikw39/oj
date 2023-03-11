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
    int h, w, r = 0;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (auto &i : a)
        for (int &j : i)
            cin >> j;
    queue<tuple<int, int, _hash<int>>> q;
    _hash<int> hs;
    hs.insert(a[0][0]);
    q.emplace(0, 0, hs);
    while (q.size())
    {
        auto [i, j, hs] = q.front();
        q.pop();
        if (i == h - 1 && j == w - 1)
        {
            ++r;
            continue;
        }
        if (i + 1 < h && hs.find(a[i + 1][j]) == hs.end())
        {
            hs.insert(a[i + 1][j]);
            q.emplace(i + 1, j, hs);
            hs.erase(a[i + 1][j]);
        }
        if (j + 1 < w && hs.find(a[i][j + 1]) == hs.end())
        {
            hs.insert(a[i][j + 1]);
            q.emplace(i, j + 1, hs);
            hs.erase(a[i][j + 1]);
        }
    }
    cout << r << '\n';
    return 0;
}
